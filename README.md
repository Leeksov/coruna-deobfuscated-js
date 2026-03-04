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

### Tooling

| File | Description |
|------|-------------|
| `deobfuscate.js` | Full deobfuscation pipeline (Node.js). Run `node deobfuscate.js` to regenerate all deobfuscated files. Requires `js-beautify`. |
| `decode-xor.js` | Standalone XOR string decoder. Prints decoded strings or creates `.decoded.js` files with `--replace`. |
| `DECODE.md` | Detailed guide to the obfuscation techniques and how to use the decoding tools. |

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
