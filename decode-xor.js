/**
 * Расшифровка XOR-обфускации в JS файлах проекта.
 * Паттерн: ([n1, n2, ...].map(x => String.fromCharCode(x ^ KEY)).join(""))
 *
 * Запуск:
 *   node decode-xor.js [файл.js]           — вывести расшифрованные строки
 *   node decode-xor.js --replace [файл.js] — создать файл с подставленными строками (.decoded.js)
 *   node decode-xor.js --all              — обработать все .js в текущей папке (только вывод)
 */

const fs = require('fs');
const path = require('path');

const args = process.argv.slice(2);
const replaceMode = args[0] === '--replace';
const allMode = args[0] === '--all';
const inputFile = replaceMode || allMode ? args[1] : (args[0] || path.join(__dirname, 'config_81502427.js'));

function decodeXor(arr, key) {
  if (!Array.isArray(arr)) return '';
  return arr.map(x => String.fromCharCode(Number(x) ^ key)).join('');
}

function escapeForJs(s) {
  return s.replace(/\\/g, '\\\\').replace(/"/g, '\\"').replace(/\n/g, '\\n').replace(/\r/g, '\\r');
}

const rePattern = /\[\s*([0-9,\s]+)\]\s*\.map\s*\(\s*x\s*=>\s*\{\s*return\s+String\.fromCharCode\s*\(\s*x\s*\^\s*(\d+)\s*\)\s*;?\s*\}\s*\)\.join\s*\(\s*""\s*\)/g;

function extractAll(content) {
  const results = [];
  let m;
  rePattern.lastIndex = 0;
  while ((m = rePattern.exec(content)) !== null) {
    const arrStr = m[1];
    const key = parseInt(m[2], 10);
    const arr = arrStr.split(',').map(s => parseInt(s.trim(), 10));
    if (arr.every(n => !isNaN(n))) {
      const decoded = decodeXor(arr, key);
      results.push({ key, decoded, fullMatch: m[0] });
    }
  }
  return results;
}

function replaceInContent(content) {
  return content.replace(rePattern, (fullMatch, arrStr, keyStr) => {
    const key = parseInt(keyStr, 10);
    const arr = arrStr.split(',').map(s => parseInt(s.trim(), 10));
    if (!arr.every(n => !isNaN(n))) return fullMatch;
    const decoded = decodeXor(arr, key);
    return '"' + escapeForJs(decoded) + '"';
  });
}

function processFile(filePath) {
  if (!fs.existsSync(filePath)) {
    console.error('Файл не найден:', filePath);
    return [];
  }
  const content = fs.readFileSync(filePath, 'utf8');
  const decoded = extractAll(content);
  const seen = new Set();
  console.log('\nФайл:', filePath);
  console.log('Найдено XOR-строк:', decoded.length);
  decoded.forEach((item) => {
    if (seen.has(item.decoded)) return;
    seen.add(item.decoded);
    const safe = item.decoded.replace(/[\x00-\x1f]/g, c => '\\x' + c.charCodeAt(0).toString(16).padStart(2, '0'));
    console.log(`  [key=${item.key}] ${safe}`);
  });
  return { content, decoded, filePath };
}

function main() {
  if (replaceMode && inputFile) {
    const content = fs.readFileSync(inputFile, 'utf8');
    const out = replaceInContent(content);
    const outPath = inputFile.replace(/\.js$/, '.decoded.js');
    fs.writeFileSync(outPath, out, 'utf8');
    console.log('Записано:', outPath);
    return;
  }

  if (allMode) {
    const dir = path.resolve(args[1] || __dirname);
    const files = fs.readdirSync(dir).filter(f => f.endsWith('.js') && !f.endsWith('.decoded.js') && f !== 'decode-xor.js');
    files.forEach(f => processFile(path.join(dir, f)));
    return;
  }

  const result = processFile(inputFile);
  if (result.decoded && result.decoded.length > 0) {
    console.log('\n--- Все вхождения ---');
    result.decoded.forEach((item, i) => {
      const preview = item.decoded.length > 100 ? item.decoded.slice(0, 100) + '...' : item.decoded;
      const safe = preview.replace(/[\x00-\x1f]/g, c => '\\x' + c.charCodeAt(0).toString(16).padStart(2, '0'));
      console.log(`${i + 1}. "${safe}" (key=${item.key})`);
    });
  }
}

main();
