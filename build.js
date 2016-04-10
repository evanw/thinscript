var child_process = require('child_process');
var fs = require('fs');

eval(fs.readFileSync('./out/common.js', 'utf8'));

// Always build all targets to catch errors in other targets
function compile(compiler, sources) {
  var compiled = compileJavaScript(compiler);

  var compiledC = compiled(sources, 'C');
  if (compiledC.stdout) process.stdout.write(compiledC.stdout);
  if (!compiledC.success) process.exit(1);

  var compiledJS = compiled(sources, 'JavaScript');
  if (compiledJS.stdout) process.stdout.write(compiledJS.stdout);
  if (!compiledJS.success) process.exit(1);

  var compiledWASM = compiled(sources, 'WebAssembly');
  if (compiledWASM.stdout) process.stdout.write(compiledWASM.stdout);
  if (!compiledWASM.success) process.exit(1);

  return {
    c: compiledC.output,
    js: compiledJS.output,
    wasm: compiledWASM.output,
  };
}

function compileNativeUnix() {
  try {
    var command = [
      'cc',
      __dirname + '/lib/thinc.c',
      __dirname + '/out/compiled.c',
      '-o', __dirname + '/out/thinc',
      '-Wall',
      '-Wextra',
      '-Wno-unused-parameter',
      '-Wno-unused-function',
      '-std=c99',
      '-O3',
    ];
    console.log(command.join(' '));
    var child = child_process.spawn(command.shift(), command, {stdio: 'inherit'});
  } catch (e) {
    console.log('failed to build the native compiler');
  }
}

function compileNativeWindows() {
  // Find all installed Visual Studio versions
  var versions = [];
  Object.keys(process.env).forEach(function(key) {
    var match = /^VS(\d+)COMNTOOLS$/.exec(key);
    if (match) {
      versions.push(match[1] | 0);
    }
  });

  // Try the compilers in descending order
  versions.sort(function(a, b) {
    return b - a;
  });
  next();

  function next() {
    if (!versions.length) {
      console.log('failed to build the native compiler');
      return;
    }

    var version = versions.shift();
    var folder = process.env['VS' + version + 'COMNTOOLS'];
    var child = child_process.spawn('cmd.exe', [], {cwd: __dirname, stdio: ['pipe', process.stdout, process.stderr]});
    child.stdin.write('"' + folder + '/../../VC/bin/vcvars32.bat"\n');
    child.stdin.write('cl.exe /O2 lib/thinc.c out/compiled.c /Fe"out/thinc.exe"\n');
    child.stdin.end();
    child.on('close', function(code) {
      if (code !== 0 || !fs.existsSync(__dirname + '/out/thinc.exe')) {
        next();
      }
    });
  }
}

var sourceDir = __dirname + '/src';
var sources = [];

fs.readdirSync(sourceDir).forEach(function(entry) {
  if (/\.thin$/.test(entry)) {
    sources.push({
      name: entry,
      contents: fs.readFileSync(sourceDir + '/' + entry, 'utf8').replace(/\r\n/g, '\n'),
    });
  }
});

var compiled = fs.readFileSync(__dirname + '/out/compiled.js', 'utf8');

console.log('compiling...');
var compiled = compile(compiled, sources);

console.log('compiling again...');
var compiled = compile(compiled.js, sources);

console.log('compiling again...');
var compiled = compile(compiled.js, sources);

fs.writeFileSync(__dirname + '/out/compiled.c', compiled.c);
console.log('wrote to "out/compiled.c"');

fs.writeFileSync(__dirname + '/out/compiled.js', compiled.js);
console.log('wrote to "out/compiled.js"');

fs.writeFileSync(__dirname + '/out/compiled.wasm', Buffer(compiled.wasm));
console.log('wrote to "out/compiled.wasm"');

console.log('building the native compiler...');
if (process.platform === 'win32') compileNativeWindows();
else compileNativeUnix();
