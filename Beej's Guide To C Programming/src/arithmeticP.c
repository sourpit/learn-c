#include <stdio.h>

int my_strlen (char *s);

int
main (void)
{
  int a[] = { 11, 22, 33, 44, 55, 999 };

  int *p = &a[0]; // Or "int *p = a;" works just as well

  // Then let's print the value there by dereferencing the pointer
  printf ("%d\n", *p);
  // Prints 11: because its point to first index of the array

  // So when we add 1 to *p it will go to next index
  printf ("%d\n", *(p + 1));
  // Its same as p[1], because the index is started at 0

  while (*p != 999)
    {
      printf ("%d\n", *p);
      p++;
    }

  printf ("%d\n", my_strlen ("Hello, World!"));
}

int
my_strlen (char *s)
{
  char *p = s;

  while (*p != '\0')
    p++;

  return p - s;
}
