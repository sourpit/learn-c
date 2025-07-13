#include <stdio.h>
#include <stdlib.h>

int
main (void)
{
  // int a;           // signed
  // signed int a;    // signed
  // signed a;        // signed, "shorthand" for "int" or "signed int", rare
  // unsigned int b;  // unsigned
  // unsigned c;      // unsigned, shorthand for "unsigned int"

  // char is a small int that uses just a single byte of space
  // char a;           // Could be signed or unsigned
  // signed char b;    // Definitely signed
  // unsigned char c;  // Definitely unsigned
  //
  // chars might be signed or unsigned depending on your compiler

  // We can do math with char
  char a = 10, b = 20;

  printf ("%d\n", a + b);

  // These two line are equivalent:
  // long long int x;
  // long long x;

  // And so are these:
  // short int x;
  // short x;
  printf ("%lu\n", stringToDouble ("NIGGER"));

  // It come at a price. You can't take the address of a register:
  register int x;
  int *p = &x;
}
