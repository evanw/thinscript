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

    String_toStringSigned: function(value) {
      return (value | 0).toString();
    },

    String_toStringUnsigned: function(value) {
      return (value >>> 0).toString();
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

function compileAndRunJavaScript(code, sources) {
  var stdlib = loadStdlibForJavaScript();
  var exports = {};
  new Function('__imports', 'exports', code)(stdlib, exports);
  var compiler = exports.Compiler_new();
  sources.forEach(function(source) {
    exports.Compiler_addInput(compiler, source.name, source.contents);
  });
  exports.Compiler_finish(compiler);
  var wasm = exports.Compiler_wasm(compiler);
  return {
    wasm: wasm ? new Uint8Array(wasm) : null,
    log: exports.Compiler_log(compiler),
    js: exports.Compiler_js(compiler),
  };
}

function compile(compiler, sources) {
  var compiler = compileAndRunJavaScript(compiler, sources);

  if (compiler.log) {
    process.stdout.write(compiler.log);
    process.exit(1);
  }

  return compiler;
}

var sourceDir = __dirname + '/src';
var sources = [];

fs.readdirSync(sourceDir).forEach(function(entry) {
  if (/\.thin$/.test(entry)) {
    sources.push({
      name: entry,
      contents: fs.readFileSync(sourceDir + '/' + entry, 'utf8'),
    });
  }
});

var compiler = fs.readFileSync(__dirname + '/www/compiled.js', 'utf8');

console.log('compiling...');
var compiler = compile(compiler, sources);

console.log('compiling again...');
var compiler = compile(compiler.js, sources);

console.log('compiling again...');
var compiler = compile(compiler.js, sources);

fs.writeFileSync(__dirname + '/www/compiled.wasm', Buffer(compiler.wasm));
console.log('wrote to "www/compiled.wasm"');

fs.writeFileSync(__dirname + '/www/compiled.js', compiler.js);
console.log('wrote to "www/compiled.js"');
