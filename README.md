# ThinScript

ThinScript is an experimental programming language that compiles to both WebAssembly and JavaScript.
It's meant to be a thin layer on top of WebAssembly that makes it easier to work with: no dependencies and fast compile times.
The syntax is inspired by TypeScript and the compiler is open source and bootstrapped (it can compile itself).

This is still an experiment and isn't intended for real use yet.
The generated code currently doesn't delete anything.
WebAssembly is a volatile work-in-progress and the binary format will be changed before the final release.
Debugging support for WebAssembly is non-existent in current implementations.
You get the idea.

## Demo

An interactive compiler demo is available online at http://evanw.github.io/thinscript/.
Here's some example code to demonstrate the language (documentation will be written at some point):

```TypeScript
declare function print(text: string): void;

class Link {
  value: int;
  next: Link;
}

class List {
  first: Link;
  last: Link;

  append(value: int): void {
    var link = new Link();
    link.value = value;

    // Append the new link to the end of the chain
    if (this.first == null) this.first = link;
    else this.last.next = link;
    this.last = link;
  }
}

extern function main(): int {
  var list = new List();
  list.append(1);
  list.append(2);
  list.append(3);

  var total = 0;
  var link = list.first;
  while (link != null) {
    total = total + link.value;
    link = link.next;
  }

  print("hello, world");
  return total;
}
```
