# Coruna — Deobfuscated

Deobfuscated JavaScript modules and binary payloads extracted from `b27[.]icu`.  
Original obfuscated source: [matteyeux/coruna](https://github.com/matteyeux/coruna)

---

## Overview

This repository contains a collection of JavaScript exploit modules targeting **WebKit** on **macOS** and **iOS**. The original code was heavily obfuscated — XOR-encoded strings, folded numeric constants, minified variable names, and base64-wrapped payloads. All JavaScript files in this repo have been **fully deobfuscated**: strings are decoded, constants are evaluated, variables are renamed to descriptive identifiers, and the code is formatted for readability.

### Deobfuscation pipeline

The automated deobfuscator (`deobfuscate.js`) applies five passes:

| Pass | What it does |
|------|-------------|
| **XOR string decode** | `[n1,n2,...].map(x => String.fromCharCode(x ^ KEY)).join("")` → plain string literal |
| **Numeric constant folding** | `4294967296 + (a ^ b)` and `(a ^ b)` → evaluated hex value |
| **Base64 payload decode** | Inline base64 blobs in `fallback_2d2c721e.js` → decoded JS |
| **Variable / method rename** | ~100 mappings: `globalThis.vKTo89.OLdwIx` → `globalResolve`, `.le(` → `.readU32(`, `class tt` → `class MachOBinary`, etc. |
| **Boolean cleanup + formatting** | `!0` → `true`, `!1` → `false`, `void 0` → `undefined`, then `js-beautify` |

---

## Project Structure

### Exploit chain

```
Loaders (KRfmo6 / yAerzw / Fq2t1Q / YGPUu7)
  │
  ├─ config_81502427.js          — core config, Mach-O parser, memory primitives
  ├─ fallback_2d2c721e.js        — fallback path (base64-encoded duplicate of config)
  │
  ├─ macos_stage1_7b7a39f8.js    — macOS stage 1: dyld cache, image loading, Mach-O parsing
  ├─ macos_stage2_agTkHY_*.js    — macOS stage 2 (variant A)
  ├─ macos_stage2_eOWEVG_*.js    — macOS stage 2 (variant B)
  │
  ├─ ios_qeqLdN_ca6e6ce1.js     — iOS exploit (variant A)
  ├─ ios_uOj89n_bcb56dc5.js     — iOS exploit (variant B)
  │
  ├─ final_payload_A_16434916.js — final payload A  (PtqWRQ=true)
  │   ├─ *_inner.js              — inner module
  │   ├─ *_blob{0,1,2}.bin      — binary blobs
  │   ├─ *_macho*.bin            — Mach-O binaries
  │   └─ *_shellcode.bin         — shellcode
  │
  └─ final_payload_B_6241388a.js — final payload B  (PtqWRQ=false)
      ├─ *_inner.js
      ├─ *_blob{0,1,2}.bin
      ├─ *_macho.bin
      └─ *_shellcode.bin
```

### File reference

| File | Role |
|------|------|
| `config_81502427.js` | Core module. Mach-O load command parser, 64-bit pointer class, memory read/write primitives. |
| `fallback_2d2c721e.js` | Fallback loader — ships a base64-encoded copy of the config and bootstraps the same API. |
| `macos_stage1_7b7a39f8.js` | macOS stage 1 — parses dyld shared cache, resolves images, defines classes: `MachOBinary`, `DyldSharedCache`, `GadgetFinder`, `ExploitChainARM64e`, `XSLTrigger`. |
| `macos_stage2_*.js` | macOS stage 2 — two variants (`agTkHY`, `eOWEVG`) with platform-specific exploit logic. |
| `ios_*.js` | iOS exploit modules — two variants (`qeqLdN`, `uOj89n`). |
| `KRfmo6_166411bd.js` | Loader — WebAssembly instantiation, Web Worker communication, `BigUint64Array` / `Uint32Array` read/write primitives. |
| `yAerzw_d6cb72f5.js` | Loader variant. |
| `Fq2t1Q_dbfd6e84.js` | Loader variant. |
| `YGPUu7_8dbfa3fd.js` | Loader variant (table-based). |
| `final_payload_A_*.js` | Final exploit payload A — launched when `PtqWRQ=true`. |
| `final_payload_B_*.js` | Final exploit payload B — launched when `PtqWRQ=false`. |
| `urls.txt` | Maps local filenames to remote URLs on `b27[.]icu` with build hashes. |

### Binary files

| File | Type | Size | Description |
|------|------|------|-------------|
| `*_blob0.bin` | JavaScript | 28K / 47K | Embedded JS payloads (different between A and B). Deobfuscated as `*_blob0.js`. |
| `*_blob1.bin` | ARM64 shellcode | 31K | ARM64 machine code — identical to `*_shellcode.bin`. Shared by A and B. |
| `*_blob2.bin` | Encoded data | 30K | 16-bit wide-encoded Mach-O metadata. Contains segment names, library paths, HTTP strings. Shared by A and B. |
| `*_macho.bin` | Mach-O ARM64 | 89K | Dynamic library (`MH_DYLIB`). Links `libcompression`, `libobjc`, `UIKit`, `CoreFoundation`, `CFNetwork`, `libSystem`. Shared by A and B. |
| `*_shellcode.bin` | ARM64 shellcode | 31K | Identical to `*_blob1.bin`. Contains `dlopen`/`dlsym`, Mach-O segment scanning, `pthread_create`, `JSEvaluateScript`, syscall wrappers. |
| `*_macho_v2.bin` | Mach-O ARM64 | 90K | Page-aligned variant of the Mach-O (A only). |

### Analysis outputs

| File | Content |
|------|---------|
| `final_payload_A_16434916_blob0.js` | Deobfuscated JS from blob0 (payload A) |
| `final_payload_B_6241388a_blob0.js` | Deobfuscated JS from blob0 (payload B) |
| `final_payload_A_16434916_macho_parsed.txt` | Full Mach-O header/segment/dylib analysis |
| `shellcode_analysis.txt` | ARM64 instruction statistics, syscall locations, embedded strings |
| `blob2_analysis.txt` | 16-bit encoded data analysis with extracted strings |

### Tooling

| File | Description |
|------|-------------|
| `deobfuscate.js` | Full deobfuscation pipeline (Node.js). Run `node deobfuscate.js` to regenerate all deobfuscated files. Requires `js-beautify`. |
| `decode-xor.js` | Standalone XOR string decoder. Prints decoded strings or creates `.decoded.js` files with `--replace`. |
| `analyze-bins.js` | Binary file analyzer — deobfuscates blob0 JS, parses Mach-O headers, extracts shellcode strings, analyzes blob2 encoding. |
| `DECODE.md` | Detailed guide to the obfuscation techniques and how to use the decoding tools. |

---

## Binary Analysis

### Mach-O Dynamic Library

All `*_macho.bin` variants are the **same ARM64 `MH_DYLIB`** (shared between payload A and B):

- **CPU**: ARM64 (ALL) — not ARM64e, no PAC
- **Segments**: `__TEXT` (49K), `__DATA_CONST` (16K), `__DATA` (16K), `__LINKEDIT` (7K)
- **Notable sections**: `__x` (472 bytes — custom code cave), `__internal` (0 bytes — marker section), `__cstring` (708 bytes)
- **Linked frameworks**: `UIKit`, `CoreFoundation`, `SystemConfiguration`, `CFNetwork`
- **Linked libraries**: `libcompression`, `libobjc.A`, `libSystem.B`

Key strings from `__cstring` reveal C2 communication and system fingerprinting:

```
/usr/libexec/corelliumd        — Corellium VM detection
ProductVersion                 — device fingerprinting
IOPlatformSerialNumber         — hardware ID extraction
MobileStore/1.0                — HTTP User-Agent
application/json               — content type for C2
{"e":%u,"l":%u}               — C2 beacon format
{"cmd":"logmsg","args":...}   — C2 logging protocol
```

### ARM64 Shellcode (31K)

Position-independent code with **100 functions** (RET instructions). No direct syscalls (`SVC`) — all system calls go through resolved function pointers. Key embedded strings:

| String | Purpose |
|--------|---------|
| `dlopen`, `dlsym`, `dlclose` | Runtime dynamic loading |
| `/usr/lib/system/libdyld.dylib` | dyld resolution |
| `__dyld_dlsym_internal` | Private dyld API |
| `JSEvaluateScript` | JavaScriptCore eval |
| `pthread_create` | Thread creation |
| `vm_protect`, `vm_map`, `vm_allocate` | Mach VM manipulation |
| `mach_make_memory_entry` | Memory entry creation |
| `proc_pidinfo`, `getpid` | Process inspection |
| `sigaction` | Signal handling |
| `_objc_flush_caches` | ObjC runtime manipulation |
| `_NSGetArgc`, `_NSGetArgv` | Process argument access |

### blob2 — Encoded Mach-O Metadata

A 16-bit wide format encoding Mach-O structural data. Each value is stored as a `uint16le`. Contains recognizable strings: segment names (`__TEXT`, `__DATA_CONST`, `__LINKEDIT`), library paths (`/usr/lib/...`, `UIKit`), HTTP-related strings (`http`, `WebContent`, `Product`), and Objective-C class references (`LASS_$_`, `_SANDBOX`).

---

## Key Technical Details

### Global API

All modules depend on a pre-initialized runtime object:

```js
globalThis.vKTo89.OLdwIx(hash)  // → globalResolve — resolve module by SHA-1 hash
globalThis.vKTo89.tI4mjA(k, b64) // → globalLoadBase64 — load base64-encoded module
```

### Renamed identifiers (excerpt)

| Original | Deobfuscated | Context |
|----------|-------------|---------|
| `.le(` | `.readU32(` | Read unsigned 32-bit value |
| `.hr(` | `.readPtr(` | Read pointer (64-bit) |
| `.lr(` | `.readStr(` | Read string from memory |
| `.sr(` | `.writeU32(` | Write unsigned 32-bit value |
| `.Dr(` | `.writePtr(` | Write pointer |
| `class tt` | `class MachOBinary` | Mach-O binary parser |
| `class nt` | `class DyldSharedCache` | dyld shared cache handler |
| `class ti` | `class GadgetFinder` | ROP gadget scanner |
| `class li` | `class ExploitChainARM64e` | ARM64e exploit chain |
| `class hi` | `class XSLTrigger` | XSL-based exploit trigger |

Full rename map (~100 entries) is in `deobfuscate.js` → `RENAME_MAP`.

### Decoded strings (examples)

Mach-O segments and system libraries recovered from XOR-encoded arrays:

- Segments: `__TEXT`, `__DATA`, `__LINKEDIT`, `__AUTH_CONST`, `__DATA_DIRTY`, `__OBJC_RO`
- Libraries: `libdyld.dylib`, `libobjc.A.dylib`, `JavaScriptCore`, `Foundation`, `CoreGraphics`
- Symbols: `_malloc`, `_free`, `_jitCagePtr`, `__platform_memmove`
- dyld: `dyld_v1  arm64e`

---

## Quick Start

### Regenerate deobfuscated files

```bash
npm install js-beautify
node deobfuscate.js
```

Output goes to `./deobfuscated/`.

### Decode XOR strings only

```bash
# Print decoded strings from a single file
node decode-xor.js config_81502427.js

# Process all JS files in the current directory
node decode-xor.js --all

# Create a .decoded.js with strings replaced inline
node decode-xor.js --replace config_81502427.js
```

---

## URL Mapping

All modules are served from `b27[.]icu`. The `urls.txt` file maps each local filename to its remote URL with SHA-1 build hashes:

| Module | Hash (short) | Remote URL |
|--------|-------------|------------|
| config | `81502427` | `b27.icu/feeee5d...js` |
| macOS stage 1 | `7b7a39f8` | `b27.icu/055c5ab...js` |
| macOS stage 2 (eOWEVG) | `55afb1a6` | `b27.icu/d9a260b...js` |
| macOS stage 2 (agTkHY) | `5264a069` | `b27.icu/5aed00f...js` |
| iOS (uOj89n) | `bcb56dc5` | `b27.icu/25bb1b3...js` |
| iOS (qeqLdN) | `ca6e6ce1` | `b27.icu/d715f1d...js` |
| Fallback | `2d2c721e` | `b27.icu/2cea193...js` |
| Final payload A | `16434916` | `b27.icu/2839f4f...js` |
| Final payload B | `6241388a` | `b27.icu/ee164f9...js` |

---

## Notes

- The code **will not run** standalone — it requires the `globalThis.vKTo89` runtime to be pre-initialized by the loader.
- Binary files (`.bin`) are Mach-O executables, shellcode, or raw data blobs consumed by the final payloads.
- This repository is for **research and analysis purposes only**.

---

*Forked from [matteyeux/coruna](https://github.com/matteyeux/coruna). Deobfuscation performed with automated tooling (Claude + custom Node.js scripts).*
