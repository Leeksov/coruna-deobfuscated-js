"""
IDA Python script - export Hex-Rays pseudocode for every function.

Usage:  File -> Script file  (Alt+F7)
Output: <idb_dir>/<filename>_pseudocode.c  +  .json
"""

import os
import json
import time
import traceback

import idaapi
import idautils
import idc
import ida_funcs
import ida_name
import ida_segment
import ida_auto
import ida_lines
import ida_xref
import ida_bytes

HAS_HEXRAYS = False
HEXRAYS_ERR = ""

try:
    import ida_hexrays
    HAS_HEXRAYS = True
except ImportError as e:
    HEXRAYS_ERR = str(e)


def diagnose():
    """Print diagnostic info about Hex-Rays availability."""
    print("")
    print("=" * 60)
    print("[DIAG] IDA version: %s" % idaapi.get_kernel_version())
    try:
        import ida_ida
        print("[DIAG] Processor: %s" % ida_ida.inf_get_procname())
        print("[DIAG] File type: %d" % ida_ida.inf_get_filetype())
        print("[DIAG] 64-bit: %s" % ida_ida.inf_is_64bit())
    except Exception:
        print("[DIAG] (could not read inf fields)")
    print("[DIAG] ida_hexrays import: %s" % ("OK" if HAS_HEXRAYS else "FAILED: " + HEXRAYS_ERR))

    if HAS_HEXRAYS:
        try:
            ok = ida_hexrays.init_hexrays_plugin()
            print("[DIAG] init_hexrays_plugin(): %s" % ok)
        except Exception as e:
            print("[DIAG] init_hexrays_plugin() exception: %s" % e)

        try:
            ver = ida_hexrays.get_hexrays_version()
            print("[DIAG] Hex-Rays version: %s" % ver)
        except Exception as e:
            print("[DIAG] get_hexrays_version() exception: %s" % e)

        # Try decompiling the first function as a test
        for func_ea in idautils.Functions():
            func = ida_funcs.get_func(func_ea)
            if func and func.size() > 16:
                name = ida_name.get_name(func_ea) or "?"
                print("[DIAG] Test decompile: %s @ 0x%X (size %d)" % (name, func_ea, func.size()))
                try:
                    cfunc = ida_hexrays.decompile(func_ea)
                    if cfunc:
                        print("[DIAG]   -> SUCCESS! Got cfunc object")
                        lines = cfunc.get_pseudocode()
                        print("[DIAG]   -> %d pseudocode lines" % len(lines))
                        if len(lines) > 0:
                            print("[DIAG]   -> First line: %s" % ida_lines.tag_remove(lines[0].line))
                    else:
                        print("[DIAG]   -> decompile() returned None")
                except ida_hexrays.DecompilationFailure as e:
                    print("[DIAG]   -> DecompilationFailure: %s" % str(e))
                except Exception as e:
                    print("[DIAG]   -> Exception: %s: %s" % (type(e).__name__, str(e)))
                    traceback.print_exc()
                break

    print("=" * 60)
    print("")


def get_output_paths():
    idb_path = idaapi.get_path(idaapi.PATH_TYPE_IDB)
    d = os.path.dirname(idb_path) if idb_path else os.path.dirname(idaapi.get_input_file_path() or "")
    if not d:
        d = os.getcwd()
    name = idaapi.get_root_filename() or "output"
    base, _ = os.path.splitext(name)
    return (os.path.join(d, base + "_pseudocode.c"),
            os.path.join(d, base + "_pseudocode.json"))


def try_decompile(ea):
    """Attempt decompilation. Returns (pseudocode_str, error_str)."""
    if not HAS_HEXRAYS:
        return None, "ida_hexrays not available"

    try:
        cfunc = ida_hexrays.decompile(ea)
    except ida_hexrays.DecompilationFailure as e:
        return None, "DecompilationFailure: %s" % str(e)
    except Exception as e:
        return None, "%s: %s" % (type(e).__name__, str(e))

    if not cfunc:
        return None, "decompile() returned None"

    try:
        lines = cfunc.get_pseudocode()
        text_lines = []
        for sl in lines:
            text_lines.append(ida_lines.tag_remove(sl.line))
        return "\n".join(text_lines), None
    except Exception as e:
        return None, "pseudocode extraction failed: %s" % str(e)


def get_string_at(ea):
    """Try to read a C-string at ea."""
    s = idc.get_strlit_contents(ea, -1, idc.STRTYPE_C)
    if s:
        return s.decode("utf-8", errors="replace")
    return None


def get_xrefs_to(ea):
    """Get callers of this function."""
    refs = []
    for xref in idautils.XrefsTo(ea, 0):
        caller = ida_funcs.get_func(xref.frm)
        if caller:
            name = ida_name.get_name(caller.start_ea) or ("sub_%X" % caller.start_ea)
            refs.append("0x%X (%s)" % (xref.frm, name))
        else:
            refs.append("0x%X" % xref.frm)
    return refs


def get_calls_from(ea):
    """Get functions called from this function."""
    func = ida_funcs.get_func(ea)
    if not func:
        return []
    calls = []
    seen = set()
    current = func.start_ea
    while current < func.end_ea:
        for xref in idautils.XrefsFrom(current, 0):
            if xref.type in (ida_xref.fl_CN, ida_xref.fl_CF):
                target = xref.to
                if target not in seen:
                    seen.add(target)
                    name = ida_name.get_name(target) or ("sub_%X" % target)
                    calls.append(name)
        current = idc.next_head(current, func.end_ea)
        if current == idc.BADADDR:
            break
    return calls


def get_string_refs(ea):
    """Get string references from this function."""
    func = ida_funcs.get_func(ea)
    if not func:
        return []
    strings = []
    current = func.start_ea
    while current < func.end_ea:
        for xref in idautils.XrefsFrom(current, 0):
            if xref.type in (ida_xref.dr_R, ida_xref.dr_O, ida_xref.dr_W, 1, 2, 3):
                s = get_string_at(xref.to)
                if s and len(s) >= 2:
                    strings.append((current, s))
        current = idc.next_head(current, func.end_ea)
        if current == idc.BADADDR:
            break
    return strings


def get_disasm(ea):
    """Get annotated disassembly for a function."""
    func = ida_funcs.get_func(ea)
    if not func:
        return "  ; no function at 0x%X" % ea
    lines = []
    current = func.start_ea
    while current < func.end_ea:
        disasm = idc.generate_disasm_line(current, 0)
        cmt = idc.get_cmt(current, 0) or idc.get_cmt(current, 1) or ""
        line = "  0x%X:  %s" % (current, disasm)
        if cmt:
            line += "    ; %s" % cmt
        lines.append(line)
        current = idc.next_head(current, func.end_ea)
        if current == idc.BADADDR:
            break
    return "\n".join(lines)


def export_all():
    diagnose()

    print("[*] Waiting for auto-analysis...")
    ida_auto.auto_wait()

    hexrays_ok = False
    if HAS_HEXRAYS:
        try:
            hexrays_ok = ida_hexrays.init_hexrays_plugin()
        except:
            pass

    c_path, json_path = get_output_paths()

    functions = list((ea, ida_name.get_name(ea) or ("sub_%X" % ea), ida_funcs.get_func(ea).size())
                     for ea in idautils.Functions()
                     if ida_funcs.get_func(ea))

    total = len(functions)
    print("[*] Found %d functions. Hex-Rays: %s" % (total, "YES" if hexrays_ok else "NO"))

    results = []
    success = 0
    failed = 0
    errors_summary = {}

    c_lines = [
        "// Pseudocode / Disassembly export",
        "// Source: %s" % idaapi.get_root_filename(),
        "// Functions: %d" % total,
        "// Hex-Rays: %s" % ("available" if hexrays_ok else "NOT available"),
        "// Generated: %s" % time.strftime("%Y-%m-%d %H:%M:%S"),
        "",
    ]

    for idx, (ea, name, size) in enumerate(functions):
        if (idx + 1) % 10 == 0 or idx == 0:
            print("[*] %d/%d: %s (0x%X) [ok=%d fail=%d]" % (idx + 1, total, name, ea, success, failed))

        pseudo, err = try_decompile(ea) if hexrays_ok else (None, "Hex-Rays not initialized")

        calls = get_calls_from(ea)
        xrefs = get_xrefs_to(ea)
        str_refs = get_string_refs(ea)

        entry = {
            "address": "0x%X" % ea,
            "name": name,
            "size": size,
            "calls": calls,
            "called_by": xrefs[:20],
            "string_refs": [s for _, s in str_refs],
        }

        header = [
            "/" * 72,
            "// Function: %s" % name,
            "// Address:  0x%X  Size: %d bytes" % (ea, size),
        ]
        if calls:
            header.append("// Calls:    %s" % ", ".join(calls[:15]))
        if xrefs:
            header.append("// Xrefs:    %d callers" % len(xrefs))
        if str_refs:
            header.append("// Strings:  %s" % ", ".join('"%s"' % s for _, s in str_refs[:10]))
        header.append("/" * 72)

        if pseudo:
            entry["pseudocode"] = pseudo
            entry["status"] = "ok"
            success += 1
            c_lines.extend(header)
            c_lines.append("")
            c_lines.append(pseudo)
            c_lines.append("")
            c_lines.append("")
        else:
            entry["error"] = err
            entry["status"] = "failed"
            failed += 1
            errors_summary[err] = errors_summary.get(err, 0) + 1

            if idx < 5:
                print("[!] FAILED %s: %s" % (name, err))

            asm = get_disasm(ea)
            entry["disassembly"] = asm

            header[1] = "// Function: %s  [ASM — %s]" % (name, err)
            c_lines.extend(header)
            c_lines.append("")
            for _, s in str_refs:
                c_lines.append('// REF: "%s"' % s)
            c_lines.append(asm)
            c_lines.append("")
            c_lines.append("")

        results.append(entry)

    with open(c_path, "w", encoding="utf-8") as f:
        f.write("\n".join(c_lines))

    with open(json_path, "w", encoding="utf-8") as f:
        json.dump({
            "source": idaapi.get_root_filename(),
            "total_functions": total,
            "decompiled": success,
            "failed": failed,
            "hexrays_available": hexrays_ok,
            "error_summary": errors_summary,
            "functions": results,
        }, f, indent=2, ensure_ascii=False)

    print("")
    print("=" * 60)
    print("[+] Done!")
    print("[+] Total: %d  |  Decompiled: %d  |  ASM only: %d" % (total, success, failed))
    if errors_summary:
        print("[+] Error breakdown:")
        for err, cnt in sorted(errors_summary.items(), key=lambda x: -x[1]):
            print("      %3d x %s" % (cnt, err))
    print("[+] C:    %s" % c_path)
    print("[+] JSON: %s" % json_path)
    print("=" * 60)


export_all()
