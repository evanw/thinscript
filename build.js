var fs = require('fs');

function loadStdlibForJavaScript() {
  return {
    assert: function(truth) {
      if (!truth) {
        throw new Error('Assertion failed');
      }
    },

    String_new: function(value) {
      return value;
    },

    String_length: function(self) {
      return self.length;
    },

    String_get: function(self, index) {
      return self.charCodeAt(index);
    },

    String_append: function(self, other) {
      return self + other;
    },

    String_appendNew: function(self, other) {
      return self + other;
    },

    String_slice: function(self, start, end) {
      return self.slice(start, end);
    },

    String_equal: function(self, other) {
      return self === other;
    },

    String_equalNew: function(self, other) {
      return self === other;
    },

    String_toString: function(value) {
      return value.toString();
    },

    String_quote: function(self) {
      return JSON.stringify(self);
    },

    ByteArray_new: function() {
      return [];
    },

    ByteArray_length: function(self) {
      return self.length;
    },

    ByteArray_getByte: function(self, index) {
      return self[index];
    },

    ByteArray_setByte: function(self, index, byte) {
      self[index] = byte & 255;
    },

    ByteArray_appendByte: function(self, byte) {
      self.push(byte & 255);
    },
  };
}

function compileAndRunJavaScript(code, input) {
  var stdlib = loadStdlibForJavaScript();
  var exports = new Function('__imports',
    code + '\n' +
    'return {main: main, CompileResult_js: CompileResult_js, CompileResult_log: CompileResult_log, CompileResult_wasm: CompileResult_wasm};'
  )(stdlib);
  var result = exports.main(input);
  var wasm = exports.CompileResult_wasm(result);
  return {
    wasm: wasm ? new Uint8Array(wasm) : null,
    log: exports.CompileResult_log(result),
    js: exports.CompileResult_js(result),
  };
}

var sourceDir = __dirname + '/src';
var sourceCode = '';

fs.readdirSync(sourceDir).forEach(function(entry) {
  if (/\.zs$/.test(entry)) {
    sourceCode += fs.readFileSync(sourceDir + '/' + entry, 'utf8');
  }
});

var compiler = fs.readFileSync(__dirname + '/www/compiled.js', 'utf8');

console.log('compiling...');
var result = compileAndRunJavaScript(compiler, sourceCode);

if (result.log) {
  process.stdout.write(result.log);
  process.exit(1);
}

fs.writeFileSync(__dirname + '/www/compiled.wasm', Buffer(result.wasm));
console.log('wrote to "www/compiled.wasm"');

fs.writeFileSync(__dirname + '/www/compiled.js', result.js);
console.log('wrote to "www/compiled.js"');
