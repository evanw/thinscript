var fs = require('fs');

eval(fs.readFileSync('./www/common.js', 'utf8'));

// Always build all targets to catch errors in other targets
function compile(compiler, sources) {
  var compiled = compileJavaScript(compiler);

  var compiledJS = compiled(sources, 'JavaScript');
  if (compiledJS.stdout) process.stdout.write(compiledJS.stdout);
  if (!compiledJS.success) process.exit(1);

  var compiledWASM = compiled(sources, 'WebAssembly');
  if (compiledWASM.stdout) process.stdout.write(compiledWASM.stdout);
  if (!compiledWASM.success) process.exit(1);

  return {
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

var compiled = fs.readFileSync(__dirname + '/www/compiled.js', 'utf8');

console.log('compiling...');
var compiled = compile(compiled, sources);

console.log('compiling again...');
var compiled = compile(compiled.js, sources);

console.log('compiling again...');
var compiled = compile(compiled.js, sources);

fs.writeFileSync(__dirname + '/www/compiled.wasm', Buffer(compiled.wasm));
console.log('wrote to "www/compiled.wasm"');

fs.writeFileSync(__dirname + '/www/compiled.js', compiled.js);
console.log('wrote to "www/compiled.js"');
