#!/usr/bin/env node

var fs = require('fs');
var compiled = null;

function Terminal_setColor(color) {
  if (process.stdout.isTTY) {
    var code =
      color === compiled.Color.BOLD ? 1 :
      color === compiled.Color.RED ? 91 :
      color === compiled.Color.GREEN ? 92 :
      color === compiled.Color.MAGENTA ? 95 :
      0;
    process.stdout.write('\x1B[0;' + code + 'm');
  }
}

function Terminal_write(text) {
  process.stdout.write(text);
}

function IO_readTextFile(path) {
  try {
    return fs.readFileSync(path, 'utf8').replace(/\r\n/g, '\n');
  } catch (e) {
    return null;
  }
}

function IO_writeTextFile(path, contents) {
  try {
    fs.writeFileSync(path, contents);
    return true;
  } catch (e) {
    return false;
  }
}

function IO_writeBinaryFile(path, contents) {
  try {
    fs.writeFileSync(path, Buffer(contents._data.subarray(0, contents._length)));
    return true;
  } catch (e) {
    return false;
  }
}

function main() {
  global.assert = require('assert');
  global.Terminal_setColor = Terminal_setColor;
  global.Terminal_write = Terminal_write;
  global.IO_readTextFile = IO_readTextFile;
  global.IO_writeTextFile = IO_writeTextFile;
  global.IO_writeBinaryFile = IO_writeBinaryFile;
  global.Profiler_begin = function() {};
  global.Profiler_end = function() {};
  global.StringBuilder_append = function(a, b) { return a + b; };
  global.StringBuilder_appendChar = function(a, b) { return a + String.fromCharCode(b); };
  global.Uint8Array_new = function(x) { return new Uint8Array(x); };
  compiled = require(__dirname + '/../out/compiled');

  for (var i = 2; i < process.argv.length; i++) {
    compiled.main_addArgument(process.argv[i]);
  }

  process.exit(compiled.main_entry());
}

main();
