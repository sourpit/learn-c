#include <stdio.h>

union foo
{
  float b;
  short a;
};

int
main (void)
{
  union foo x;

  x.b = 3.14159;

  printf ("%f\a\n", x.b);
  printf ("%d\a\n", x.a);
}
