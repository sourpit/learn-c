#include <stdio.h>

int main(void)
{
  /* \x000 is C notation for Hex characters
   * 001   ^A
   * 002   ^B
   * 003   ^C
   * 004   ^D
   * and so on. */
  printf("Hi!\x003\n");

  /* This is a function call, which calls a function
   * named printf, with the argument "hello, world\n" */
  fprintf(stdout, "Hello, World!\n");

  /* Program exited successfuly */
  return 0;
}
