function loadStdlibForWebAssembly() {
  var extractLengthPrefixedString = function(index) {
    var bytes = stdlib.bytes;
    var text = '', length = stdlib.ints[index >> 2], i = index + 4;
    while (length-- > 0) text += String.fromCharCode(bytes[i++]);
    return text;
  }

  var stdlib = {
    strings: [],
    bytes: null,
    ints: null,

    assert: function(truth) {
      if (!truth) {
        throw new Error('Assertion failed');
      }
    },

    Profiler_begin: function() {
      time = now();
    },

    Profiler_end: function(text) {
      console.log(stdlib.strings[text - 1] + ': ' + Math.round(now() - time) + 'ms');
    },

    String_new: function(ptr) {
      stdlib.strings.push(extractLengthPrefixedString(ptr));
      return stdlib.strings.length;
    },

    String_length: function(self) {
      return stdlib.strings[self - 1].length;
    },

    String_get: function(self, index) {
      return stdlib.strings[self - 1].charCodeAt(index);
    },

    String_append: function(self, other) {
      stdlib.strings.push(stdlib.strings[self - 1] + stdlib.strings[other - 1]);
      return stdlib.strings.length;
    },

    String_appendNew: function(self, other) {
      stdlib.strings.push(stdlib.strings[self - 1] + extractLengthPrefixedString(other));
      return stdlib.strings.length;
    },

    String_slice: function(self, start, end) {
      stdlib.strings.push(stdlib.strings[self - 1].slice(start, end));
      return stdlib.strings.length;
    },

    String_equal: function(self, other) {
      return stdlib.strings[self - 1] === stdlib.strings[other - 1];
    },

    String_equalNew: function(self, other) {
      return stdlib.strings[self - 1] === extractLengthPrefixedString(other);
    },

    String_toStringSigned: function(value) {
      stdlib.strings.push((value | 0).toString());
      return stdlib.strings.length;
    },

    String_toStringUnsigned: function(value) {
      stdlib.strings.push((value >>> 0).toString());
      return stdlib.strings.length;
    },

    String_quote: function(self) {
      stdlib.strings.push(JSON.stringify(stdlib.strings[self - 1]));
      return stdlib.strings.length;
    },
  };
  return stdlib;
}

function loadStdlibForJavaScript() {
  var time = 0;

  return {
    assert: function(truth) {
      if (!truth) {
        throw new Error('Assertion failed');
      }
    },

    Profiler_begin: function() {
      time = now();
    },

    Profiler_end: function(text) {
      console.log(text + ': ' + Math.round(now() - time) + 'ms');
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

    Uint8Array_new: function(length) {
      return new Uint8Array(length);
    },
  };
}

function fetch(url, responseType, callback) {
  var xhr = new XMLHttpRequest;
  xhr.open('GET', url);
  xhr.onload = function() {
    callback(xhr.response);
  };
  xhr.responseType = responseType;
  xhr.send(null);
}

function loadJavaScript(callback) {
  fetch('compiled.js', 'text', callback);
}

function loadWebAssembly(callback) {
  fetch('compiled.wasm', 'arraybuffer', function(buffer) {
    callback(new Uint8Array(buffer));
  });
}

var CompileTarget = {
  JAVASCRIPT: 1,
  WEBASSEMBLY: 2,
};

function filterSources(sources, target, callback) {
  sources.forEach(function(source) {
    if (/\.js\./.test(source.name) && target !== CompileTarget.JAVASCRIPT ||
        /\.wasm\./.test(source.name) && target !== CompileTarget.WEBASSEMBLY) {
      return;
    }
    callback(source);
  });
}

function compileWebAssembly(code) {
  var stdlib = loadStdlibForWebAssembly();
  var module = Wasm.instantiateModule(code, {globals: stdlib});
  var exports = module.exports;
  var memory = exports.memory;
  stdlib.bytes = new Uint8Array(memory);
  stdlib.ints = new Int32Array(memory);

  return function(sources, target) {
    console.log('compiling to ' + (target === CompileTarget.JAVASCRIPT ? 'JavaScript' : 'WebAssembly') + ' using WebAssembly');
    var before = now();

    stdlib.strings = [];

    exports.Compiler_resetHeapPointer();
    var compiler = exports.Compiler_new(target);

    filterSources(sources, target, function(source) {
      stdlib.strings.push(source.name);
      var nameString = stdlib.strings.length;

      stdlib.strings.push(source.contents);
      var contentsString = stdlib.strings.length;

      exports.Compiler_addInput(compiler, nameString, contentsString);
    });

    exports.Compiler_finish(compiler);

    var wasm = exports.Compiler_wasm(compiler);
    var wasmData = wasm && stdlib.ints[wasm >> 2];
    var wasmLength = wasm && stdlib.ints[(wasm + 4) >> 2];

    var after = now();
    var totalTime = Math.round(after - before);
    console.log('total time: ' + totalTime + 'ms');

    return {
      wasm: wasm ? stdlib.bytes.subarray(wasmData, wasmData + wasmLength) : null,
      log: stdlib.strings[exports.Compiler_log(compiler) - 1] || '',
      js: stdlib.strings[exports.Compiler_js(compiler) - 1] || '',
      totalTime: totalTime,
    };
  };
}

function compileJavaScript(code) {
  var stdlib = loadStdlibForJavaScript();
  var exports = {};
  new Function('globals', 'exports', code)(stdlib, exports);

  return function(sources, target) {
    console.log('compiling to ' + (target === CompileTarget.JAVASCRIPT ? 'JavaScript' : 'WebAssembly') + ' using JavaScript');
    var before = now();

    var compiler = exports.Compiler_new(target);

    filterSources(sources, target, function(source) {
      exports.Compiler_addInput(compiler, source.name, source.contents);
    });

    exports.Compiler_finish(compiler);
    var wasm = exports.Compiler_wasm(compiler);

    var after = now();
    var totalTime = Math.round(after - before);
    console.log('total time: ' + totalTime + 'ms');

    return {
      wasm: wasm ? wasm.bytes() : null,
      log: exports.Compiler_log(compiler),
      js: exports.Compiler_js(compiler),
      totalTime: totalTime,
    };
  };
}

function now() {
  return typeof performance !== 'undefined' && performance.now ? performance.now() : +new Date;
}
