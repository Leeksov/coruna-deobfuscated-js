"""
IDA Python script — export Hex-Rays pseudocode for every function.

Usage inside IDA:
  File -> Script file...  -> select this script
  OR
  Alt+F7 -> select this script

Output:
  <idb_directory>/<input_filename>_pseudocode.c
  <idb_directory>/<input_filename>_pseudocode.json  (structured, per-function)

Requirements:
  - IDA Pro with Hex-Rays decompiler (ARM64 / x86_64)
  - Wait for auto-analysis to finish before running
"""

import os
import json
import time

import idaapi
import idautils
import idc
import ida_funcs
import ida_name
import ida_segment
import ida_auto

try:
    import ida_hexrays
    HAS_HEXRAYS = True
except ImportError:
    HAS_HEXRAYS = False


def wait_for_analysis():
    """Block until IDA finishes auto-analysis."""
    ida_auto.auto_wait()


def get_output_dir():
    """Return the directory where the IDB lives, or the input file dir."""
    idb_path = idaapi.get_path(idaapi.PATH_TYPE_IDB)
    if idb_path:
        return os.path.dirname(idb_path)
    inp = idaapi.get_input_file_path()
    if inp:
        return os.path.dirname(inp)
    return os.getcwd()


def get_base_name():
    """Input file name without extension."""
    name = idaapi.get_root_filename()
    if not name:
        name = "output"
    base, _ = os.path.splitext(name)
    return base


def decompile_func(ea):
    """Try to decompile function at `ea`. Returns pseudocode string or None."""
    if not HAS_HEXRAYS:
        return None
    try:
        cfunc = ida_hexrays.decompile(ea)
        if cfunc:
            lines = cfunc.get_pseudocode()
            text_lines = []
            for sl in lines:
                line = ida_hexrays.tag_remove(sl.line)
                text_lines.append(line)
            return "\n".join(text_lines)
    except ida_hexrays.DecompilationFailure:
        return None
    except Exception:
        return None
    return None


def collect_functions():
    """Yield (ea, name, size) for every function in the database."""
    for seg_ea in idautils.Segments():
        seg = ida_segment.getseg(seg_ea)
        if not seg:
            continue
        for func_ea in idautils.Functions(seg.start_ea, seg.end_ea):
            func = ida_funcs.get_func(func_ea)
            if not func:
                continue
            name = ida_name.get_name(func_ea) or ("sub_%X" % func_ea)
            size = func.size()
            yield func_ea, name, size


def export_all():
    if not HAS_HEXRAYS:
        print("[!] Hex-Rays decompiler not available. Install the decompiler plugin.")
        print("[!] Falling back to disassembly-only export.")

    print("[*] Waiting for auto-analysis to complete...")
    wait_for_analysis()

    if HAS_HEXRAYS:
        if not ida_hexrays.init_hexrays_plugin():
            print("[!] Failed to initialize Hex-Rays plugin.")
            return

    out_dir = get_output_dir()
    base = get_base_name()
    c_path = os.path.join(out_dir, base + "_pseudocode.c")
    json_path = os.path.join(out_dir, base + "_pseudocode.json")

    functions = list(collect_functions())
    total = len(functions)
    print("[*] Found %d functions" % total)

    results = []
    success = 0
    failed = 0

    c_lines = []
    c_lines.append("// Auto-generated pseudocode export")
    c_lines.append("// Source: %s" % idaapi.get_root_filename())
    c_lines.append("// Functions: %d" % total)
    c_lines.append("// Generated: %s" % time.strftime("%Y-%m-%d %H:%M:%S"))
    c_lines.append("")

    for idx, (ea, name, size) in enumerate(functions):
        if (idx + 1) % 10 == 0 or idx == 0:
            print("[*] Processing %d/%d: %s (0x%X)" % (idx + 1, total, name, ea))

        pseudo = None
        if HAS_HEXRAYS:
            pseudo = decompile_func(ea)

        entry = {
            "address": "0x%X" % ea,
            "name": name,
            "size": size,
        }

        if pseudo:
            entry["pseudocode"] = pseudo
            entry["status"] = "ok"
            success += 1

            c_lines.append("/" * 72)
            c_lines.append("// Function: %s" % name)
            c_lines.append("// Address:  0x%X" % ea)
            c_lines.append("// Size:     %d bytes" % size)
            c_lines.append("/" * 72)
            c_lines.append("")
            c_lines.append(pseudo)
            c_lines.append("")
            c_lines.append("")
        else:
            entry["status"] = "failed"
            failed += 1

            disasm_lines = []
            current = ea
            func = ida_funcs.get_func(ea)
            end = func.end_ea if func else ea + size
            while current < end:
                disasm_lines.append("  0x%X: %s" % (current, idc.generate_disasm_line(current, 0)))
                current = idc.next_head(current, end)
                if current == idc.BADADDR:
                    break

            asm_text = "\n".join(disasm_lines)
            entry["disassembly"] = asm_text

            c_lines.append("/" * 72)
            c_lines.append("// Function: %s  [DECOMPILATION FAILED — disassembly below]" % name)
            c_lines.append("// Address:  0x%X" % ea)
            c_lines.append("// Size:     %d bytes" % size)
            c_lines.append("/" * 72)
            c_lines.append("/*")
            c_lines.append(asm_text)
            c_lines.append("*/")
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
            "functions": results,
        }, f, indent=2, ensure_ascii=False)

    print("")
    print("=" * 60)
    print("[+] Export complete!")
    print("[+] Total functions:  %d" % total)
    print("[+] Decompiled:       %d" % success)
    print("[+] Failed (asm only): %d" % failed)
    print("[+] C output:   %s" % c_path)
    print("[+] JSON output: %s" % json_path)
    print("=" * 60)


if __name__ == "__main__":
    export_all()
else:
    export_all()
