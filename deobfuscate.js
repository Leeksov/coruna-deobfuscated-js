const fs = require('fs');
const path = require('path');
const beautify = require('js-beautify').js;

const DIR = __dirname;
const OUT = path.join(DIR, 'deobfuscated');

if (!fs.existsSync(OUT)) fs.mkdirSync(OUT);

// ── 1. XOR string decode ──
const reXorStr = /\(\[\s*([0-9,\s]+)\]\s*\.map\s*\(\s*x\s*=>\s*\{\s*return\s+String\.fromCharCode\s*\(\s*x\s*\^\s*(\d+)\s*\)\s*;?\s*\}\s*\)\.join\s*\(\s*""\s*\)\)/g;

function decodeXorStr(content) {
  return content.replace(reXorStr, (full, arrStr, keyStr) => {
    const key = parseInt(keyStr, 10);
    const arr = arrStr.split(',').map(s => parseInt(s.trim(), 10));
    if (!arr.every(n => !isNaN(n))) return full;
    const decoded = arr.map(x => String.fromCharCode(x ^ key)).join('');
    return '"' + escJs(decoded) + '"';
  });
}

// ── 2. Numeric XOR constants ──
// 4294967296 + (a ^ b)  where a,b can be negative
const reNumXor1 = /4294967296\s*\+\s*\(\s*(-?\d+)\s*\^\s*(-?\d+)\s*\)/g;
// (a ^ b) standalone between operators — only in safe contexts
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

// ── 3. Boolean / minification cleanup ──
function cleanupBooleans(content) {
  content = content.replace(/!0/g, 'true');
  content = content.replace(/!1/g, 'false');
  content = content.replace(/void 0/g, 'undefined');
  return content;
}

// ── 4. Base64 decode (fallback file) ──
function decodeBase64Payloads(content) {
  const reB64 = /globalThis\.vKTo89\.tI4mjA\(\s*"[^"]+"\s*,\s*"([A-Za-z0-9+/=]+)"\s*\)/g;
  return content.replace(reB64, (full, b64) => {
    try {
      const decoded = Buffer.from(b64, 'base64').toString('utf8');
      return '/* decoded base64 payload */\n' + decoded;
    } catch { return full; }
  });
}

// ── 5. Rename map (based on analysis) ──
const RENAME_MAP = {
  // globalThis API
  'globalThis.vKTo89.OLdwIx': 'globalResolve',
  'globalThis.vKTo89.tI4mjA': 'globalLoadBase64',
  // Mach-O segments
  '__TEXT': '__TEXT',
  '__LINKEDIT': '__LINKEDIT',
  '__AUTH_CONST': '__AUTH_CONST',
  '__DATA': '__DATA',
  '__DATA_DIRTY': '__DATA_DIRTY',
  '__DATA_CONST': '__DATA_CONST',
  '__OBJC_RO': '__OBJC_RO',
  // config classes — inferred from behavior
  'Vt': 'Ptr64',       // 64-bit pointer (it,et = lo,hi)
  'Pn': 'memory',      // memory read/write primitives
  'Dn': 'engine',      // engine/runtime context
  'Tn': 'PtrClass',    // pointer class ref
  'Hn': 'config',      // config/constants
  'Mn': 'baseOffset',
  // common method names
  '.le(': '.readU32(',
  '.hr(': '.readPtr(',
  '.lr(': '.readStr(',
  '.rr(': '.readU32Raw(',
  '.sr(': '.writeU32(',
  '.Dr(': '.writePtr(',
  '.br(': '.readPtrStripped(',
  '.re(': '.readPair(',
  '.dr(': '.readString(',
  '.ee(': '.readAddrVal(',
  '.wr(': '.readByte(',
  '.Ar(': '.getBackingAddr(',
  '.Pr(': '.withSwap(',
  '.ne(': '.addrOfObj(',
  '.tA(': '.addrOfJS(',
  '.Ci(': '.readU64(',
  '.zi(': '.writeU64(',
  // Mach-O parser
  '.Hs': '.parsedHeader',
  '.ho': '.segments',
  '.Gs': '.baseData',
  '.Qs': '.vmSlide',
  '.Ys': '.linkeditBase',
  '.Zs': '.dyldCacheSlide',
  '.Ks': '.dyldCacheBase',
  '.so': '.symtabData',
  '.oo': '.symtabSize',
  '.Re': '.segName',
  '.Xe': '.vmAddr',
  '.Es': '.vmAddrCopy',
  '.Os': '.vmSize',
  '.Ge': '.fileOff',
  '.Ms': '.nSections',
  '.Ls': '.sections',
  '.Ds': '.sectionsRaw',
  '.Vs': '.sectName',
  // dyld cache
  '.No': '.cacheSlide',
  '.Vo': '.cacheHeader',
  '.Zo': '.parsedImages',
  '.jo': '.loadImages',
  '.Fo': '.magic',
  '.Ko': '.getSlide',
  '.Go': '.allPaths',
  '.Qo': '.getImage',
  '.Yo': '.findImageAddr',
  '.So': '.findSegment',
  '.To': '.getSegmentOrThrow',
  '.yo': '.getDyldCache',
  '.Ro': '.findInSegment',
  '.Co': '.readFromSegment',
  '.Mo': '.scanSegmentPair',
  '.Do': '.scanSegment32',
  '.Lo': '.scanSegment64',
  '.Bo': '.findSegmentByRange',
  '.Ao': '.isInSegment',
  '.Uo': '.findValueInSegment',
  '.Oo': '.fileOffsetToVA',
  // exploit chain
  '.Ec': '.jitWriteAddr',
  '.Bc': '.stackPivotAddr',
  '.Lc': '.dyldCache',
  '.dh': '.gadgetFinder',
  '.Rc': '.syscallNums',
  '.Wc': '.invokeSyscall',
  '.Oc': '.fakeStruct',
  '.Qc': '.isARM64e',
  // XSL controller (trigger)
  '.mh': '.xslPayload',
  '.ph': '.xmlDoc',
  '.sh': '.triggerXSL',
  '.ah': '.initTrigger',
  '.Xh': '.warmup',
  // gadget finder
  '.Xc': '.buildMask',
  '.Gc': '.findGadget',
  '.Nc': '.findGadgetInImages',
  '.Hc': '.findGadgetNoPtr',
  '.Pc': '.findGadgetAllImages',
  '.kc': '.extractBranches',
  '.Tc': '.branchCount',
  // exploit result
  '.zc': '.gadgetAddr',
  '.Dc': '.functionStart',
  '.Zc': '.branchTargets',
  '.Sc': '.ptrValue',
  // class renames
  'class tt': 'class MachOBinary',
  'class rt': 'class MachOReaderAbsolute',
  'class et': 'class MachOReaderRelative',
  'class nt': 'class DyldSharedCache',
  'class ii': 'class SyscallBase',
  'class ci': 'class SyscallImpl',
  'class ti': 'class GadgetFinder',
  'class li': 'class ExploitChainARM64e',
  'class si': 'class ExploitChainARM64',
  'class hi': 'class XSLTrigger',
  // worker/loader
  '.Ni': '.converter',
  '.Vi': '.tempBuf',
  '.la': '.addrOfArray',
  '.ra': '.wasmInstanceA',
  '.ia': '.wasmInstanceB',
  '.ea': '.callA',
  '.aa': '.callB',
  '.na': '.setA',
  '.sa': '.setB',
  '.ha': '.u32View',
  '.oa': '.u64View',
  '.ba': '.rwPrimA',
  '.ga': '.rwPrimB',
  '.wa': '.rwPrimC',
  '.ya': '.rwPrimD',
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

// ── Utils ──
function escJs(s) {
  return s.replace(/\\/g, '\\\\').replace(/"/g, '\\"')
    .replace(/\n/g, '\\n').replace(/\r/g, '\\r')
    .replace(/\0/g, '\\0');
}

// ── Main pipeline ──
function deobfuscate(content, filename) {
  let out = content;
  out = decodeXorStr(out);          // XOR strings
  out = foldNumericXor(out);        // numeric constants
  if (filename.includes('fallback')) {
    out = decodeBase64Payloads(out);
  }
  out = applyRenames(out);          // rename vars/methods
  out = cleanupBooleans(out);       // !0 → true etc
  out = beautify(out, {
    indent_size: 2,
    max_preserve_newlines: 2,
    break_chained_methods: false,
    keep_array_indentation: true,
    brace_style: 'collapse',
    end_with_newline: true,
  });
  return out;
}

// ── Process files ──
const jsFiles = fs.readdirSync(DIR)
  .filter(f => f.endsWith('.js') && !f.endsWith('.decoded.js')
    && f !== 'decode-xor.js' && f !== 'deobfuscate.js');

for (const file of jsFiles) {
  const inPath = path.join(DIR, file);
  const content = fs.readFileSync(inPath, 'utf8');
  console.log(`Processing ${file}...`);
  try {
    const result = deobfuscate(content, file);
    const outPath = path.join(OUT, file);
    fs.writeFileSync(outPath, result, 'utf8');
    console.log(`  → ${path.relative(DIR, outPath)} (${(result.length/1024).toFixed(0)} KB)`);
  } catch (err) {
    console.error(`  Error: ${err.message}`);
  }
}

console.log('\nDone. Deobfuscated files in ./deobfuscated/');
