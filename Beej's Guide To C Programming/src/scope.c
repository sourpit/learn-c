#include <stdio.h>

void variableHiding (void);
void blockScope (void);
void forLoop (void);

// These are file scope variables
int shared = 10; // File scope! Visible to the whole file after this!

int
main (void)
{
  variableHiding ();
  blockScope ();

  printf ("%d", shared);

  for (int i = 0; i < 10; i++)
    printf ("%d\n", i);

  printf ("%d\n", i); // ILLEGAL--i is only in scope for the for-loop

  forLoop ();
}

void
variableHiding (void)
{
  int i = 10;

  {
    int i = 20;

    printf ("%d\n", i); // Inner scope i, 20 (outer i is hidden)
  }

  printf ("%d\n", i); // Outer scope i, 10
}

void
blockScope (void)
{
  int a = 12; // Local to outer block, but visible in inner block

  if (a == 12)
    {
      int b = 99; // Local to inner block, not visible in outer block

      printf ("%d, %d\n", a, b); // OK: "12 99"
    }

  printf ("%d\n", a); // OK, we're still in a's scope

  printf ("%d\n", b); // ILLEGAL, out of b's scope
}

void
forLoop (void)
{
  for (int i = 0; i < 5; i++)
    {
      int i = 999; // Hides the i in the for-loop scope
      printf ("%d\n", i);
    }
}
