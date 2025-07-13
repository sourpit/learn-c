#include <stdlib.h>
#include <string.h>

int
main (void)
{
  // Allocate space for 10 ints with calloc(), initialized to 0:
  int *p = calloc (10, sizeof (int));

  // Allocate space for 10 ints with calloc(), initialized to 0:
  int *q = malloc (10 * sizeof (int));
  memset (q, 0, 10 * sizeof (int)); // Set to zero.

  // Free the memory
  free (p);
  free (q);
}
