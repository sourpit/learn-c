#include <stdio.h>

// This how null works
#define NULL ((void *)0)

int
main (void)
{
  int i;
  int *p;

  // p now points to i, P holds adress of i
  p = &i;

  i = 10;  // i is now 10
  *p = 20; // the thing p points to (namely i) is now 20!!

  printf ("i is %d\n", i);  // prints "20"
  printf ("i is %d\n", *p); // "20"! dereference-p is the same as i!

  printf ("%zu\n", sizeof p);
}
