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
try {
  var command = [
    'cc',
    '"' + __dirname + '/lib/thinc.c"',
    '"' + __dirname + '/out/compiled.c"',
    '-o "' + __dirname + '/out/thinc"',
    '-Wall',
    '-Wextra',
    '-Wpedantic',
    '-Wno-unused-parameter',
    '-Wno-unused-function',
    '-O3',
  ];
  console.log(command.join(' '));
  child_process.execSync(command.join(' '), {stdio: 'inherit'});
} catch (e) {
}
