#include <stdio.h>
#include <stdlib.h>

int
main (void)
{
  int *p = malloc (sizeof (int));
  if (p == NULL)
    return 0;

  *p = 12;

  int *x;
  if ((x = malloc (sizeof (int) * 10)) == NULL)
    printf ("Error allocating 10 ints\n");

  *x = 10;

  printf ("%d, %d\n", *p, *x); // Print it: 12, 10

  free (p);
}
