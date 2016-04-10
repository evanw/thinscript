function loadStdlibForWebAssembly() {
  var stdlib = {
    exports: null,
    bytes: null,
    chars: null,
    ints: null,
    stdout: '',
    fs: {},

    reset: function() {
      stdlib.stdout = '';
      stdlib.fs = {};
    },

    createLengthPrefixedString: function(text) {
      var chars = stdlib.chars, length = text.length, result = stdlib.exports.main_newString(length), ptr = result + 4 >> 1;
      for (var i = 0; i < length; i++) chars[ptr + i] = text.charCodeAt(i);
      return result;
    },

    extractLengthPrefixedString: function(index) {
      var chars = stdlib.chars, text = '', length = stdlib.ints[index >> 2], i = index + 4 >> 1;
      while (length-- > 0) text += String.fromCharCode(chars[i++]);
      return text;
    },

    assert: function(truth) {
      if (!truth) {
        throw new Error('Assertion failed');
      }
    },

    Terminal_setColor: function(color) {
    },

    Terminal_write: function(text) {
      stdlib.stdout += stdlib.extractLengthPrefixedString(text);
    },

    IO_readTextFile: function(path) {
      var contents = stdlib.fs[stdlib.extractLengthPrefixedString(path)];
      return typeof contents === 'string' ? stdlib.createLengthPrefixedString(contents) : null;
    },

    IO_writeTextFile: function(path, contents) {
      stdlib.fs[stdlib.extractLengthPrefixedString(path)] = stdlib.extractLengthPrefixedString(contents);
      return true;
    },

    IO_writeBinaryFile: function(path, contents) {
      var data = stdlib.ints[contents >> 2];
      var length = stdlib.ints[contents + 4 >> 2];
      stdlib.fs[stdlib.extractLengthPrefixedString(path)] = stdlib.bytes.subarray(data, data + length);
      return true;
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
    stdout: '',
    fs: {},

    reset: function() {
      this.stdout = '';
      this.fs = {};
    },

    assert: function(truth) {
      if (!truth) {
        throw new Error('Assertion failed');
      }
    },

    Terminal_setColor: function(color) {
    },

    Terminal_write: function(text) {
      this.stdout += text;
    },

    IO_readTextFile: function(path) {
      var contents = this.fs[path];
      return typeof contents === 'string' ? contents : null;
    },

    IO_writeTextFile: function(path, contents) {
      this.fs[path] = contents;
      return true;
    },

    IO_writeBinaryFile: function(path, contents) {
      this.fs[path] = contents._data.subarray(0, contents._length);
      return true;
    },

    Profiler_begin: function() {
      time = now();
    },

    Profiler_end: function(text) {
      console.log(text + ': ' + Math.round(now() - time) + 'ms');
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

function compileWebAssembly(code) {
  var stdlib = loadStdlibForWebAssembly();
  var module = Wasm.instantiateModule(code, {global: stdlib});
  var exports = module.exports;
  var memory = exports.memory;
  stdlib.exports = exports;
  stdlib.bytes = new Uint8Array(memory);
  stdlib.chars = new Uint16Array(memory);
  stdlib.ints = new Int32Array(memory);

  return function(sources, target, name) {
    var output = name;
    switch (target) {
      case 'C': output += '.c'; break;
      case 'JavaScript': output += '.js'; break;
      case 'WebAssembly': output += '.wasm'; break;
      default: throw new Error('Invalid target: ' + target);
    }

    console.log('compiling to ' + target + ' using WebAssembly');
    var before = now();

    stdlib.reset();
    exports.main_reset();

    sources.forEach(function(source) {
      stdlib.fs[source.name] = source.contents;
      exports.main_addArgument(stdlib.createLengthPrefixedString(source.name));
    });

    exports.main_addArgument(stdlib.createLengthPrefixedString('--out'));
    exports.main_addArgument(stdlib.createLengthPrefixedString(output));

    var success = exports.main_entry() === 0;
    var after = now();
    var totalTime = Math.round(after - before);
    console.log('total time: ' + totalTime + 'ms');

    return {
      secondaryOutput: success && name + '.h' in stdlib.fs ? stdlib.fs[name + '.h'] : null,
      output: success ? stdlib.fs[output] : null,
      totalTime: totalTime,
      stdout: stdlib.stdout,
      success: success,
    };
  };
}

function compileJavaScript(code) {
  var stdlib = loadStdlibForJavaScript();
  var exports = {};
  new Function('global', 'exports', code)(stdlib, exports);

  return function(sources, target, name) {
    var output = name;
    switch (target) {
      case 'C': output += '.c'; break;
      case 'JavaScript': output += '.js'; break;
      case 'WebAssembly': output += '.wasm'; break;
      default: throw new Error('Invalid target: ' + target);
    }

    console.log('compiling to ' + target + ' using JavaScript');
    var before = now();

    stdlib.reset();
    exports.main_reset();

    sources.forEach(function(source) {
      stdlib.fs[source.name] = source.contents;
      exports.main_addArgument(source.name);
    });

    exports.main_addArgument('--out');
    exports.main_addArgument(output);

    var success = exports.main_entry() === 0;
    var after = now();
    var totalTime = Math.round(after - before);
    console.log('total time: ' + totalTime + 'ms');

    return {
      secondaryOutput: success && name + '.h' in stdlib.fs ? stdlib.fs[name + '.h'] : null,
      output: success ? stdlib.fs[output] : null,
      totalTime: totalTime,
      stdout: stdlib.stdout,
      success: success,
    };
  };
}

function now() {
  return typeof performance !== 'undefined' && performance.now ? performance.now() : +new Date;
}
