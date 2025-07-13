#include <stdio.h>

void *my_memcpy (void *dest, void *src, int byteCount);

int
main (void)
{
  char a = 'x';

  void *p = &a;
  char *q = p;

  // printf("%c\n", *p); // ERROR: Cannot dereference void*!
  printf ("%c\n", *q);

  char *nig = "NIGGER";
  char *gger;

  my_memcpy (&gger, &nig, 7);
  printf ("%s", gger);
}

void *
my_memcpy (void *dest, void *src, int byteCount)
{
  char *s = src, *d = dest;

  while (byteCount--)
    *d++ = *s++;

  return dest;
}
