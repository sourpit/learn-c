#include <stdbool.h>
#include <stdio.h>

int
main (void)
{
  // In C, 0 means "false" and non-zero means "true"
  int x = 1;
  bool ow = true;

  if (x)
    {
      printf ("x is true!\n");
    }

  if (ow)
    {
      printf ("x is true!\n");
    }

  printf ("%d\n", true == 12); // prints "0", false!
}
