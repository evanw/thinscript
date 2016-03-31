function loadStdlibForWebAssembly() {
  var stdlib = {
    strings: [],
    bytes: null,
    ints: null,

    extractLengthPrefixedString: function(index) {
      var bytes = stdlib.bytes;
      var text = '', length = stdlib.ints[index >> 2], i = index + 4;
      while (length-- > 0) text += String.fromCharCode(bytes[i++]);
      return text;
    },

    assert: function(truth) {
      if (!truth) {
        throw new Error('Assertion failed');
      }
    },

    Profiler_begin: function() {
      time = now();
    },

    Profiler_end: function(text) {
      console.log(stdlib.extractLengthPrefixedString(text) + ': ' + Math.round(now() - time) + 'ms');
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

    string_length: function(self) {
      return self.length;
    },

    string_get: function(self, index) {
      return self.charCodeAt(index);
    },

    string_equals: function(a, b) {
      return a === b;
    },

    string_slice: function(text, start, end) {
      return text.slice(start, end);
    },

    string_intToString: function(value) {
      return (value | 0).toString();
    },

    string_uintToString: function(value) {
      return (value >>> 0).toString();
    },

    StringBuilder_append: function(a, b) {
      return a + b;
    },

    StringBuilder_appendChar: function(a, b) {
      return a + String.fromCharCode(b);
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

function compileWebAssembly(code) {
  var stdlib = loadStdlibForWebAssembly();
  var module = Wasm.instantiateModule(code, {global: stdlib});
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

    sources.forEach(function(source) {
      var name = source.name;
      var contents = source.contents;
      var nameString = exports.string_new(name.length);
      var contentsString = exports.string_new(contents.length);
      var bytes = stdlib.bytes;

      for (var i = 0, length = name.length; i < length; i++) {
        bytes[nameString + i + 4] = name.charCodeAt(i);
      }

      for (var i = 0, length = contents.length; i < length; i++) {
        bytes[contentsString + i + 4] = contents.charCodeAt(i);
      }

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
      log: stdlib.extractLengthPrefixedString(exports.Compiler_log(compiler)) || '',
      js: stdlib.extractLengthPrefixedString(exports.Compiler_js(compiler)) || '',
      totalTime: totalTime,
    };
  };
}

function compileJavaScript(code) {
  var stdlib = loadStdlibForJavaScript();
  var exports = {};
  new Function('global', 'exports', code)(stdlib, exports);

  return function(sources, target) {
    console.log('compiling to ' + (target === CompileTarget.JAVASCRIPT ? 'JavaScript' : 'WebAssembly') + ' using JavaScript');
    var before = now();

    var compiler = exports.Compiler_new(target);

    sources.forEach(function(source) {
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
