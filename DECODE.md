# Obfuscation Techniques & Decoding Guide

This document describes the obfuscation methods used in the Coruna exploit modules and how to reverse them.

---

## 1. XOR-Encoded Strings

The primary obfuscation technique. Human-readable strings are stored as arrays of integers, each XORed with a constant key:

```js
// Obfuscated
([8, 95, 95, 9, 8, 9, 91, 91, 10].map(x => { return String.fromCharCode(x ^ 57); }).join(""))

// Decoded → "__TEXT"  (each byte: 8^57=95='_', 95^57=80='_', ...)
```

**How it works:**
- Each number `n` in the array represents one character: `String.fromCharCode(n ^ KEY)`
- The XOR key varies per string (common range: 48–121)
- The result is joined into a single string

**Regex pattern used for detection:**

```js
/\(\[\s*([0-9,\s]+)\]\s*\.map\s*\(\s*x\s*=>\s*\{\s*return\s+String\.fromCharCode\s*\(\s*x\s*\^\s*(\d+)\s*\)\s*;?\s*\}\s*\)\.join\s*\(\s*""\s*\)\)/g
```

---

## 2. Numeric Constant Folding

Numeric values (addresses, type IDs, bitmasks) are hidden behind XOR expressions:

```js
// Pattern A: unsigned 32-bit via 4294967296 offset
4294967296 + (1215443043 ^ -932040639)   // → 0xFEEDFACF (Mach-O magic)

// Pattern B: standalone XOR
(1395676770 ^ 1395672674)                // → 0x00001000 (page size)
```

**To evaluate manually:**

```js
// In Node.js or browser console:
console.log(((1215443043 ^ -932040639) >>> 0).toString(16))  // "feedfacf"
console.log(((1395676770 ^ 1395672674) >>> 0).toString(16))  // "1000"
```

---

## 3. Base64-Encoded Payloads

The `fallback_2d2c721e.js` file embeds a full JavaScript module as a base64 string, loaded via:

```js
globalThis.vKTo89.tI4mjA("key", "BASE64_ENCODED_JS_HERE")
```

The deobfuscator decodes these inline and replaces them with the raw JavaScript.

---

## 4. Minified Identifiers

Variable and method names are single or double characters (`tt`, `rt`, `le`, `hr`). The deobfuscator's `RENAME_MAP` restores meaningful names based on behavioral analysis:

| Original | Renamed | Reasoning |
|----------|---------|-----------|
| `.le(` | `.readU32(` | Reads 4 bytes, returns number |
| `.hr(` | `.readPtr(` | Reads 8 bytes, returns pointer |
| `.lr(` | `.readStr(` | Reads bytes, returns string |
| `class tt` | `class MachOBinary` | Parses Mach-O headers and segments |
| `class nt` | `class DyldSharedCache` | Handles dyld shared cache |

---

## Using the Tools

### `decode-xor.js` — Standalone XOR Decoder

No dependencies required — just Node.js.

```bash
# Print all decoded strings from a file
node decode-xor.js config_81502427.js

# Process every .js file in a directory
node decode-xor.js --all
node decode-xor.js --all /path/to/files

# Create a .decoded.js with XOR patterns replaced by string literals
node decode-xor.js --replace config_81502427.js
```

**Output modes:**
- **Default** — prints unique decoded strings with the XOR key used
- **`--replace`** — writes `<filename>.decoded.js` with obfuscated patterns swapped for plain strings (structure/variable names unchanged)
- **`--all`** — batch mode, processes all `.js` files in the given directory

### `deobfuscate.js` — Full Pipeline

Requires `js-beautify`:

```bash
npm install js-beautify
node deobfuscate.js
```

Processes all `.js` files in the working directory and outputs fully deobfuscated versions to `./deobfuscated/`. Applies all five passes (XOR decode → numeric fold → base64 decode → rename → beautify).

---

## Decoded String Examples

### config_81502427.js

| Decoded String | Purpose |
|---------------|---------|
| `1ff010bb3e857e2b0383f1d9a1cf9f54e321fbb0` | Module hash (SHA-1) |
| `6b57ca3347345883898400ea4318af3b9aa1dc5c` | Module hash (SHA-1) |
| `__TEXT` | Mach-O segment |
| `__LINKEDIT` | Mach-O segment |
| `__AUTH_CONST` | Mach-O segment (PAC) |
| `dyld` | Dynamic linker |
| `dyld_v1  arm64e` | dyld cache magic |

### macos_stage1_7b7a39f8.js

**Segments:** `__TEXT`, `__DATA`, `__AUTH`, `__AUTH_CONST`, `__DATA_DIRTY`, `__DATA_CONST`, `__OBJC_RO`, `__dyld4`

**Libraries:** `libdyld.dylib`, `libxml2.2.dylib`, `libobjc.A.dylib`, `JavaScriptCore`, `Foundation`, `CoreGraphics`, `CloudKit`, `UIKitCore`, `CoreMedia`, `CoreUtils`, `ActionKit`

**Symbols:** `_malloc`, `_free`, `_xmlMalloc`, `_jitCagePtr`, `__platform_memset`, `__platform_memmove`, `__ZN3JSC10LinkBuffer8linkCodeE...`, `_OBJC_CLASS_$_NSUUID`

### KRfmo6_166411bd.js (loader)

- `use strict`, `Navigator` — environment checks
- `bigint`, `number` — type guards
- `text/javascript` — MIME type for Worker blob
- `jsobj must be a BigUint64Array, or a Uint[8,16,32]Array` — validation error
- `unreachable` — WebAssembly trap marker
- `vKTo89`, `OLdwIx` — global API identifiers

---

## Limitations

1. **XOR pattern only** — the decoder handles the specific `.map(x => String.fromCharCode(x ^ KEY)).join("")` pattern. Strings built via concatenation or other obfuscation methods are not caught.
2. **Numeric arrays only** — expressions like `4294967296 + (...)` inside array literals are not parsed.
3. **Rename coverage** — the `RENAME_MAP` covers ~100 identifiers identified through manual analysis. Many short variable names remain unresolved and require manual reverse engineering.

---

*This guide covers the mechanical obfuscation layer. Understanding the exploit logic requires further analysis of the deobfuscated code.*
