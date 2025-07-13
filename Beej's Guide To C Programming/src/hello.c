#include <stdio.h>

int
main (void)
{
  // this is uninitialized variable,
  // and its bad if you left them like this.
  //
  // int i;
  // float f;

  // these are initialized variable
  int i;
  i = 2;
  float f = 3.14;
  char *s = "Hello, nigger!"; // and this called string literal
                              // because it stored not in the stack
                              // so its still there even the function
                              // have been popped.

  printf ("%s i = %d and f = %f!\n", s, i, f);
  return 1;
}
