const fs = require('fs');
const path = require('path');

const beautify = require('js-beautify').js;

const DIR = __dirname;
const OUT = path.join(DIR, 'deobfuscated');
if (!fs.existsSync(OUT)) fs.mkdirSync(OUT);

// ═══════════════════════════════════════════════════════════
//  Reuse deobfuscation helpers from deobfuscate.js
// ═══════════════════════════════════════════════════════════

const reXorStr = /\(\[\s*([0-9,\s]+)\]\s*\.map\s*\(\s*x\s*=>\s*\{\s*return\s+String\.fromCharCode\s*\(\s*x\s*\^\s*(\d+)\s*\)\s*;?\s*\}\s*\)\.join\s*\(\s*""\s*\)\)/g;

function escJs(s) {
  return s.replace(/\\/g, '\\\\').replace(/"/g, '\\"')
    .replace(/\n/g, '\\n').replace(/\r/g, '\\r')
    .replace(/\0/g, '\\0');
}

function decodeXorStr(content) {
  return content.replace(reXorStr, (full, arrStr, keyStr) => {
    const key = parseInt(keyStr, 10);
    const arr = arrStr.split(',').map(s => parseInt(s.trim(), 10));
    if (!arr.every(n => !isNaN(n))) return full;
    const decoded = arr.map(x => String.fromCharCode(x ^ key)).join('');
    return '"' + escJs(decoded) + '"';
  });
}

const reNumXor1 = /4294967296\s*\+\s*\(\s*(-?\d+)\s*\^\s*(-?\d+)\s*\)/g;
const reNumXor2 = /\((\d{6,})\s*\^\s*(-?\d{6,})\)/g;

function foldNumericXor(content) {
  content = content.replace(reNumXor1, (full, a, b) => {
    const val = (4294967296 + (parseInt(a) ^ parseInt(b))) >>> 0;
    return '0x' + val.toString(16);
  });
  content = content.replace(reNumXor2, (full, a, b) => {
    const va = parseInt(a), vb = parseInt(b);
    if (isNaN(va) || isNaN(vb)) return full;
    const val = (va ^ vb) >>> 0;
    return '0x' + val.toString(16);
  });
  return content;
}

function cleanupBooleans(content) {
  return content.replace(/!0/g, 'true').replace(/!1/g, 'false').replace(/void 0/g, 'undefined');
}

const RENAME_MAP = {
  'globalThis.vKTo89.OLdwIx': 'globalResolve',
  'globalThis.vKTo89.tI4mjA': 'globalLoadBase64',
  '.le(': '.readU32(', '.hr(': '.readPtr(', '.lr(': '.readStr(',
  '.rr(': '.readU32Raw(', '.sr(': '.writeU32(', '.Dr(': '.writePtr(',
  '.br(': '.readPtrStripped(', '.re(': '.readPair(', '.dr(': '.readString(',
  '.ee(': '.readAddrVal(', '.wr(': '.readByte(', '.Ar(': '.getBackingAddr(',
  '.Pr(': '.withSwap(', '.ne(': '.addrOfObj(', '.tA(': '.addrOfJS(',
  '.Ci(': '.readU64(', '.zi(': '.writeU64(',
  '.Hs': '.parsedHeader', '.ho': '.segments', '.Gs': '.baseData',
  '.Qs': '.vmSlide', '.Ys': '.linkeditBase', '.Zs': '.dyldCacheSlide',
  '.Ks': '.dyldCacheBase', '.so': '.symtabData', '.oo': '.symtabSize',
  '.Re': '.segName', '.Xe': '.vmAddr', '.Es': '.vmAddrCopy',
  '.Os': '.vmSize', '.Ge': '.fileOff', '.Ms': '.nSections',
  '.Ls': '.sections', '.Ds': '.sectionsRaw', '.Vs': '.sectName',
  '.No': '.cacheSlide', '.Vo': '.cacheHeader', '.Zo': '.parsedImages',
  '.jo': '.loadImages', '.Fo': '.magic', '.Ko': '.getSlide',
  '.Go': '.allPaths', '.Qo': '.getImage', '.Yo': '.findImageAddr',
  '.So': '.findSegment', '.To': '.getSegmentOrThrow',
  '.yo': '.getDyldCache', '.Ro': '.findInSegment',
  '.Co': '.readFromSegment', '.Mo': '.scanSegmentPair',
  '.Do': '.scanSegment32', '.Lo': '.scanSegment64',
  '.Bo': '.findSegmentByRange', '.Ao': '.isInSegment',
  '.Uo': '.findValueInSegment', '.Oo': '.fileOffsetToVA',
  '.Ec': '.jitWriteAddr', '.Bc': '.stackPivotAddr', '.Lc': '.dyldCache',
  '.dh': '.gadgetFinder', '.Rc': '.syscallNums', '.Wc': '.invokeSyscall',
  '.Oc': '.fakeStruct', '.Qc': '.isARM64e',
  '.mh': '.xslPayload', '.ph': '.xmlDoc', '.sh': '.triggerXSL',
  '.ah': '.initTrigger', '.Xh': '.warmup',
  '.Xc': '.buildMask', '.Gc': '.findGadget',
  '.Nc': '.findGadgetInImages', '.Hc': '.findGadgetNoPtr',
  '.Pc': '.findGadgetAllImages', '.kc': '.extractBranches',
  '.Tc': '.branchCount',
  '.zc': '.gadgetAddr', '.Dc': '.functionStart',
  '.Zc': '.branchTargets', '.Sc': '.ptrValue',
  'class tt': 'class MachOBinary', 'class rt': 'class MachOReaderAbsolute',
  'class et': 'class MachOReaderRelative', 'class nt': 'class DyldSharedCache',
  'class ii': 'class SyscallBase', 'class ci': 'class SyscallImpl',
  'class ti': 'class GadgetFinder', 'class li': 'class ExploitChainARM64e',
  'class si': 'class ExploitChainARM64', 'class hi': 'class XSLTrigger',
  '.Ni': '.converter', '.Vi': '.tempBuf', '.la': '.addrOfArray',
  '.ra': '.wasmInstanceA', '.ia': '.wasmInstanceB',
  '.ea': '.callA', '.aa': '.callB', '.na': '.setA', '.sa': '.setB',
  '.ha': '.u32View', '.oa': '.u64View',
  '.ba': '.rwPrimA', '.ga': '.rwPrimB', '.wa': '.rwPrimC', '.ya': '.rwPrimD',
  '.Aa': '.addrOfPtr',
};

function applyRenames(content) {
  let out = content;
  for (const [from, to] of Object.entries(RENAME_MAP)) {
    if (from === to) continue;
    const escaped = from.replace(/[.*+?^${}()|[\]\\]/g, '\\$&');
    out = out.replace(new RegExp(escaped, 'g'), to);
  }
  return out;
}

function deobfuscate(content, filename) {
  let out = content;
  out = decodeXorStr(out);
  out = foldNumericXor(out);
  out = applyRenames(out);
  out = cleanupBooleans(out);
  out = beautify(out, {
    indent_size: 2, max_preserve_newlines: 2,
    break_chained_methods: false, keep_array_indentation: true,
    brace_style: 'collapse', end_with_newline: true,
  });
  return out;
}

// ═══════════════════════════════════════════════════════════
//  1. BLOB0 — JavaScript payloads
// ═══════════════════════════════════════════════════════════

console.log('=== BLOB0 (JavaScript) ===\n');

for (const variant of ['A_16434916', 'B_6241388a']) {
  const binPath = path.join(DIR, `final_payload_${variant}_blob0.bin`);
  if (!fs.existsSync(binPath)) continue;
  const raw = fs.readFileSync(binPath, 'utf8');
  console.log(`final_payload_${variant}_blob0.bin: ${raw.length} chars of JS`);

  const outName = `final_payload_${variant}_blob0.js`;
  const result = deobfuscate(raw, outName);
  const outPath = path.join(OUT, outName);
  fs.writeFileSync(outPath, result, 'utf8');
  console.log(`  → deobfuscated/${outName} (${(result.length/1024).toFixed(0)} KB)\n`);
}

// ═══════════════════════════════════════════════════════════
//  2. MACH-O parser
// ═══════════════════════════════════════════════════════════

console.log('=== MACH-O BINARIES ===\n');

const MH_MAGIC_64 = 0xFEEDFACF;
const CPU_TYPE = { 0x0100000C: 'ARM64' };
const CPU_SUBTYPE = { 0x00: 'ALL', 0x02: 'ARM64E' };
const FILE_TYPE = {
  1: 'MH_OBJECT', 2: 'MH_EXECUTE', 3: 'MH_FVMLIB', 4: 'MH_CORE',
  5: 'MH_PRELOAD', 6: 'MH_DYLIB', 7: 'MH_DYLINKER', 8: 'MH_BUNDLE',
  9: 'MH_DYLIB_STUB', 10: 'MH_DSYM', 11: 'MH_KEXT_BUNDLE', 12: 'MH_FILESET'
};
const LC_NAMES = {
  0x01: 'LC_SEGMENT', 0x02: 'LC_SYMTAB', 0x04: 'LC_THREAD',
  0x05: 'LC_UNIXTHREAD', 0x0B: 'LC_DYSYMTAB', 0x0C: 'LC_LOAD_DYLIB',
  0x0D: 'LC_ID_DYLIB', 0x0E: 'LC_LOAD_DYLINKER',
  0x19: 'LC_SEGMENT_64', 0x1D: 'LC_ID_DYLIB', 0x1F: 'LC_LOAD_WEAK_DYLIB',
  0x22: 'LC_DYLD_INFO', 0x24: 'LC_VERSION_MIN_MACOSX',
  0x25: 'LC_VERSION_MIN_IPHONEOS', 0x26: 'LC_FUNCTION_STARTS',
  0x29: 'LC_DATA_IN_CODE', 0x2A: 'LC_SOURCE_VERSION',
  0x2B: 'LC_DYLIB_CODE_SIGN_DRS',
  0x32: 'LC_BUILD_VERSION',
  0x80000022: 'LC_DYLD_INFO_ONLY', 0x80000018: 'LC_LOAD_WEAK_DYLIB',
  0x8000001C: 'LC_RPATH', 0x80000028: 'LC_MAIN',
  0x8000002B: 'LC_DYLIB_CODE_SIGN_DRS',
  0x0000001A: 'LC_FVMFILE', 0x1B: 'LC_IDENT',
  0x80000033: 'LC_DYLD_EXPORTS_TRIE', 0x80000034: 'LC_DYLD_CHAINED_FIXUPS',
  0x0000001D: 'LC_LOAD_UPWARD_DYLIB',
};

function readU32(buf, off) { return buf.readUInt32LE(off); }
function readU64(buf, off) {
  return buf.readUInt32LE(off) + buf.readUInt32LE(off + 4) * 0x100000000;
}
function readCStr(buf, off, maxLen) {
  let end = off;
  const limit = Math.min(off + (maxLen || 256), buf.length);
  while (end < limit && buf[end] !== 0) end++;
  return buf.toString('utf8', off, end);
}

function parseMachO(buf) {
  const magic = readU32(buf, 0);
  if (magic !== MH_MAGIC_64) return null;

  const cpuType = readU32(buf, 4);
  const cpuSubtype = readU32(buf, 8);
  const fileType = readU32(buf, 12);
  const nCmds = readU32(buf, 16);
  const sizeOfCmds = readU32(buf, 20);
  const flags = readU32(buf, 24);

  const header = {
    magic: '0x' + magic.toString(16).toUpperCase(),
    cpuType: CPU_TYPE[cpuType] || '0x' + cpuType.toString(16),
    cpuSubtype: CPU_SUBTYPE[cpuSubtype] || '0x' + cpuSubtype.toString(16),
    fileType: FILE_TYPE[fileType] || fileType,
    nCmds, sizeOfCmds,
    flags: '0x' + flags.toString(16),
  };

  const segments = [];
  const dylibs = [];
  const loadCommands = [];
  let off = 32; // after mach_header_64

  for (let i = 0; i < nCmds; i++) {
    const cmd = readU32(buf, off);
    const cmdSize = readU32(buf, off + 4);
    const cmdName = LC_NAMES[cmd] || '0x' + cmd.toString(16);
    loadCommands.push({ cmd: cmdName, size: cmdSize });

    if (cmd === 0x19) { // LC_SEGMENT_64
      const segName = readCStr(buf, off + 8, 16);
      const vmAddr = readU64(buf, off + 24);
      const vmSize = readU64(buf, off + 32);
      const fileOff = readU64(buf, off + 40);
      const fileSize = readU64(buf, off + 48);
      const maxProt = readU32(buf, off + 56);
      const initProt = readU32(buf, off + 60);
      const nSections = readU32(buf, off + 64);
      const segFlags = readU32(buf, off + 68);

      const sections = [];
      let sOff = off + 72;
      for (let s = 0; s < nSections; s++) {
        const sectName = readCStr(buf, sOff, 16);
        const sectSeg = readCStr(buf, sOff + 16, 16);
        const sectAddr = readU64(buf, sOff + 32);
        const sectSize = readU64(buf, sOff + 40);
        const sectOff = readU32(buf, sOff + 48);
        sections.push({
          name: sectName, segment: sectSeg,
          addr: '0x' + sectAddr.toString(16),
          size: sectSize, fileOff: sectOff,
        });
        sOff += 80;
      }

      segments.push({
        name: segName,
        vmAddr: '0x' + vmAddr.toString(16),
        vmSize: '0x' + vmSize.toString(16),
        fileOff, fileSize,
        maxProt, initProt, nSections, flags: segFlags,
        sections,
      });
    }

    if (cmd === 0x0C || cmd === 0x8000001C || cmd === 0x80000018 ||
        cmd === 0x1F || cmd === 0x0000001D) {
      // LC_LOAD_DYLIB variants
      const nameOff = readU32(buf, off + 8);
      if (off + nameOff < buf.length) {
        dylibs.push(readCStr(buf, off + nameOff, cmdSize - nameOff));
      }
    }

    off += cmdSize;
  }

  return { header, segments, dylibs, loadCommands };
}

const machoFiles = fs.readdirSync(DIR).filter(f => f.endsWith('_macho.bin') || f.includes('macho_'));

for (const file of machoFiles) {
  const buf = fs.readFileSync(path.join(DIR, file));
  const parsed = parseMachO(buf);
  if (!parsed) {
    console.log(`${file}: not a Mach-O 64-bit binary`);
    continue;
  }

  console.log(`${file} (${buf.length} bytes):`);
  console.log(`  Type: ${parsed.header.fileType} | CPU: ${parsed.header.cpuType} (${parsed.header.cpuSubtype})`);
  console.log(`  Flags: ${parsed.header.flags} | Load commands: ${parsed.header.nCmds}`);
  console.log(`  Segments:`);
  for (const seg of parsed.segments) {
    console.log(`    ${seg.name.padEnd(16)} vmAddr=${seg.vmAddr}  vmSize=${seg.vmSize}  fileOff=${seg.fileOff}  fileSize=${seg.fileSize}`);
    for (const sect of seg.sections) {
      console.log(`      ${sect.name.padEnd(20)} addr=${sect.addr}  size=${sect.size}  fileOff=${sect.fileOff}`);
    }
  }
  if (parsed.dylibs.length) {
    console.log(`  Linked dylibs:`);
    for (const d of parsed.dylibs) console.log(`    ${d}`);
  }
  console.log(`  All load commands:`);
  for (const lc of parsed.loadCommands) console.log(`    ${lc.cmd} (${lc.size} bytes)`);
  console.log();

  const outPath = path.join(OUT, file.replace('.bin', '_parsed.txt'));
  const lines = [];
  lines.push(`Mach-O Analysis: ${file}`);
  lines.push(`${'='.repeat(60)}`);
  lines.push(`Size: ${buf.length} bytes`);
  lines.push(`Type: ${parsed.header.fileType}`);
  lines.push(`CPU: ${parsed.header.cpuType} (subtype: ${parsed.header.cpuSubtype})`);
  lines.push(`Flags: ${parsed.header.flags}`);
  lines.push(`Load commands: ${parsed.header.nCmds}\n`);
  lines.push('Segments:');
  for (const seg of parsed.segments) {
    lines.push(`  ${seg.name}`);
    lines.push(`    vmAddr: ${seg.vmAddr}  vmSize: ${seg.vmSize}`);
    lines.push(`    fileOff: ${seg.fileOff}  fileSize: ${seg.fileSize}`);
    lines.push(`    maxProt: ${seg.maxProt}  initProt: ${seg.initProt}  nSections: ${seg.nSections}`);
    for (const sect of seg.sections) {
      lines.push(`      [${sect.name}] addr=${sect.addr} size=${sect.size} fileOff=${sect.fileOff}`);
    }
  }
  if (parsed.dylibs.length) {
    lines.push('\nLinked dylibs:');
    for (const d of parsed.dylibs) lines.push(`  ${d}`);
  }
  lines.push('\nLoad commands:');
  for (const lc of parsed.loadCommands) lines.push(`  ${lc.cmd} (${lc.size} bytes)`);

  fs.writeFileSync(outPath, lines.join('\n') + '\n', 'utf8');
  console.log(`  → deobfuscated/${path.basename(outPath)}`);
}

// ═══════════════════════════════════════════════════════════
//  3. SHELLCODE — ARM64 analysis
// ═══════════════════════════════════════════════════════════

console.log('\n=== SHELLCODE (ARM64) ===\n');

function extractStrings(buf, minLen = 4) {
  const strings = [];
  let cur = '';
  let startOff = 0;
  for (let i = 0; i < buf.length; i++) {
    const b = buf[i];
    if (b >= 0x20 && b <= 0x7E) {
      if (cur.length === 0) startOff = i;
      cur += String.fromCharCode(b);
    } else {
      if (cur.length >= minLen) {
        strings.push({ offset: startOff, str: cur });
      }
      cur = '';
    }
  }
  if (cur.length >= minLen) strings.push({ offset: startOff, str: cur });
  return strings;
}

function analyzeARM64(buf) {
  let stp_count = 0, ldp_count = 0, bl_count = 0, ret_count = 0;
  let br_count = 0, svc_count = 0, nop_count = 0;
  const svc_offsets = [];

  for (let i = 0; i + 3 < buf.length; i += 4) {
    const insn = readU32(buf, i);
    if ((insn & 0x7FC00000) === 0x29000000 || (insn & 0x7FC00000) === 0x29800000) stp_count++;
    if ((insn & 0x7FC00000) === 0x29400000 || (insn & 0x7FC00000) === 0x29C00000) ldp_count++;
    if ((insn & 0xFC000000) === 0x94000000) bl_count++;
    if (insn === 0xD65F03C0) ret_count++;
    if ((insn & 0xFFFFFFE0) === 0xD61F0000 || (insn & 0xFFFFFFE0) === 0xD63F0000) br_count++;
    if ((insn & 0xFFE0001F) === 0xD4000001) {
      svc_count++;
      const imm = (insn >> 5) & 0xFFFF;
      svc_offsets.push({ offset: i, syscall: imm });
    }
    if (insn === 0xD503201F) nop_count++;
  }

  return { stp_count, ldp_count, bl_count, ret_count, br_count, svc_count, nop_count, svc_offsets };
}

const scFile = 'final_payload_A_16434916_shellcode.bin';
const scPath = path.join(DIR, scFile);
if (fs.existsSync(scPath)) {
  const buf = fs.readFileSync(scPath);
  console.log(`${scFile}: ${buf.length} bytes`);

  const stats = analyzeARM64(buf);
  console.log(`  ARM64 instruction stats:`);
  console.log(`    STP (store pair):  ${stats.stp_count}`);
  console.log(`    LDP (load pair):   ${stats.ldp_count}`);
  console.log(`    BL (branch+link):  ${stats.bl_count}`);
  console.log(`    RET:               ${stats.ret_count}`);
  console.log(`    BR/BLR (indirect): ${stats.br_count}`);
  console.log(`    SVC (syscall):     ${stats.svc_count}`);
  console.log(`    NOP:               ${stats.nop_count}`);

  if (stats.svc_offsets.length) {
    console.log(`  Syscall invocations:`);
    for (const s of stats.svc_offsets) {
      console.log(`    offset 0x${s.offset.toString(16)}: SVC #0x${s.syscall.toString(16)} (${s.syscall === 0x80 ? 'mach_trap / BSD syscall' : 'syscall #' + s.syscall})`);
    }
  }

  const strings = extractStrings(buf, 4);
  if (strings.length) {
    console.log(`  Embedded strings (${strings.length}):`);
    for (const s of strings) {
      console.log(`    0x${s.offset.toString(16).padStart(6, '0')}: "${s.str}"`);
    }
  }

  const lines = [];
  lines.push(`Shellcode Analysis: ${scFile}`);
  lines.push(`${'='.repeat(60)}`);
  lines.push(`Size: ${buf.length} bytes (${(buf.length / 4)} instructions max)`);
  lines.push(`\nARM64 instruction statistics:`);
  lines.push(`  STP (store pair):    ${stats.stp_count}`);
  lines.push(`  LDP (load pair):     ${stats.ldp_count}`);
  lines.push(`  BL (branch+link):    ${stats.bl_count}`);
  lines.push(`  RET:                 ${stats.ret_count}`);
  lines.push(`  BR/BLR (indirect):   ${stats.br_count}`);
  lines.push(`  SVC (syscall):       ${stats.svc_count}`);
  lines.push(`  NOP:                 ${stats.nop_count}`);
  if (stats.svc_offsets.length) {
    lines.push(`\nSyscall invocations:`);
    for (const s of stats.svc_offsets) {
      lines.push(`  offset 0x${s.offset.toString(16)}: SVC #0x${s.syscall.toString(16)}`);
    }
  }
  if (strings.length) {
    lines.push(`\nEmbedded strings:`);
    for (const s of strings) {
      lines.push(`  0x${s.offset.toString(16).padStart(6, '0')}: "${s.str}"`);
    }
  }

  // Hex dump first 256 bytes
  lines.push(`\nHex dump (first 256 bytes):`);
  for (let i = 0; i < Math.min(256, buf.length); i += 16) {
    const hex = [];
    const ascii = [];
    for (let j = 0; j < 16 && i + j < buf.length; j++) {
      hex.push(buf[i + j].toString(16).padStart(2, '0'));
      ascii.push(buf[i + j] >= 0x20 && buf[i + j] <= 0x7E ? String.fromCharCode(buf[i + j]) : '.');
    }
    lines.push(`  ${i.toString(16).padStart(6, '0')}  ${hex.join(' ').padEnd(48)}  |${ascii.join('')}|`);
  }

  const outPath = path.join(OUT, 'shellcode_analysis.txt');
  fs.writeFileSync(outPath, lines.join('\n') + '\n', 'utf8');
  console.log(`  → deobfuscated/shellcode_analysis.txt\n`);
}

// ═══════════════════════════════════════════════════════════
//  4. BLOB2 — Encoded Mach-O metadata
// ═══════════════════════════════════════════════════════════

console.log('=== BLOB2 (Encoded data) ===\n');

const b2File = 'final_payload_A_16434916_blob2.bin';
const b2Path = path.join(DIR, b2File);
if (fs.existsSync(b2Path)) {
  const buf = fs.readFileSync(b2Path);
  console.log(`${b2File}: ${buf.length} bytes`);

  // Check if this is a wide-encoded (2 bytes per value) format
  // First 8 bytes: CF 00 FA 00 ED 00 FE 00 — looks like Mach-O magic with zero-padding
  const isWide = (buf[1] === 0 && buf[3] === 0 && buf[5] === 0 && buf[7] === 0 &&
                  buf[0] === 0xCF && buf[2] === 0xFA && buf[4] === 0xED && buf[6] === 0xFE);

  if (isWide) {
    console.log('  Encoding: appears to be 16-bit wide format (2 bytes per value)');
  }

  // Try reading as uint16le pairs
  const u16 = [];
  for (let i = 0; i < buf.length; i += 2) {
    u16.push(buf.readUInt16LE(i));
  }

  // Extract ASCII-like strings from uint16 values
  const wStrings = [];
  let cur = '';
  let startIdx = 0;
  for (let i = 0; i < u16.length; i++) {
    if (u16[i] >= 0x20 && u16[i] <= 0x7E) {
      if (cur.length === 0) startIdx = i * 2;
      cur += String.fromCharCode(u16[i]);
    } else {
      if (cur.length >= 3) wStrings.push({ offset: startIdx, str: cur });
      cur = '';
    }
  }
  if (cur.length >= 3) wStrings.push({ offset: startIdx, str: cur });

  if (wStrings.length) {
    console.log(`  Extracted strings from 16-bit values (${wStrings.length}):`);
    for (const s of wStrings) {
      console.log(`    0x${s.offset.toString(16).padStart(4, '0')}: "${s.str}"`);
    }
  }

  // Also check if there's a simple byte-level XOR or encoding
  // Try to decode the non-string uint16 values
  const nonAscii = u16.filter(v => v > 0x7E || (v > 0 && v < 0x20));
  const maxVal = Math.max(...nonAscii);
  const uniqueHigh = [...new Set(nonAscii)].sort((a, b) => a - b);
  console.log(`  Non-ASCII uint16 values: ${nonAscii.length} of ${u16.length} total`);
  console.log(`  Unique non-ASCII values: ${uniqueHigh.length} (max: 0x${maxVal.toString(16)})`);

  if (uniqueHigh.length <= 40) {
    console.log(`  All unique non-ASCII: [${uniqueHigh.map(v => '0x' + v.toString(16)).join(', ')}]`);
  }

  // Analyze structure: find where strings are placed relative to each other
  const lines = [];
  lines.push(`Blob2 Analysis: ${b2File}`);
  lines.push(`${'='.repeat(60)}`);
  lines.push(`Size: ${buf.length} bytes (${u16.length} uint16 values)`);
  lines.push(`Encoding: 16-bit wide values (Mach-O magic visible as wide bytes)\n`);
  if (wStrings.length) {
    lines.push('Extracted strings:');
    for (const s of wStrings) {
      lines.push(`  0x${s.offset.toString(16).padStart(4, '0')}: "${s.str}"`);
    }
  }
  lines.push(`\nNon-ASCII uint16 value histogram:`);
  const freq = {};
  for (const v of nonAscii) freq[v] = (freq[v] || 0) + 1;
  const sorted = Object.entries(freq).sort((a, b) => b[1] - a[1]);
  for (const [val, count] of sorted.slice(0, 30)) {
    lines.push(`  0x${parseInt(val).toString(16).padStart(4, '0')}: ${count} times`);
  }

  lines.push(`\nHex dump (first 256 bytes):`);
  for (let i = 0; i < Math.min(256, buf.length); i += 16) {
    const hex = [];
    const ascii = [];
    for (let j = 0; j < 16 && i + j < buf.length; j++) {
      hex.push(buf[i + j].toString(16).padStart(2, '0'));
      ascii.push(buf[i + j] >= 0x20 && buf[i + j] <= 0x7E ? String.fromCharCode(buf[i + j]) : '.');
    }
    lines.push(`  ${i.toString(16).padStart(6, '0')}  ${hex.join(' ').padEnd(48)}  |${ascii.join('')}|`);
  }

  const outPath = path.join(OUT, 'blob2_analysis.txt');
  fs.writeFileSync(outPath, lines.join('\n') + '\n', 'utf8');
  console.log(`  → deobfuscated/blob2_analysis.txt\n`);
}

// ═══════════════════════════════════════════════════════════
//  5. Compare macho variants (A only)
// ═══════════════════════════════════════════════════════════

console.log('=== MACH-O VARIANTS ===\n');

const machoVariants = ['final_payload_A_16434916_macho.bin', 'final_payload_A_16434916_macho_v2.bin',
  'final_payload_A_16434916_macho_verified.bin', 'final_payload_A_macho_trimmed.bin'];
for (const file of machoVariants) {
  const fp = path.join(DIR, file);
  if (!fs.existsSync(fp)) continue;
  const buf = fs.readFileSync(fp);
  const hash = require('crypto').createHash('sha256').update(buf).digest('hex').slice(0, 16);
  console.log(`${file}: ${buf.length} bytes  sha256=${hash}...`);
}

console.log('\nDone.');
