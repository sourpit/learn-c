#include <stdio.h>

int
main (void)
{
  typedef struct animal_t
  {
    char *name;
    int legCount, speed;
  } animal_t;

  // This called anonymous structure
  typedef struct
  {
    int x, y;
  } point_t;

  struct animal_t y; // This works
  animal_t z;        // This also works because "animal" is an alias

  // You also can aliasing variables
  typedef int fiveNiggers[5];
  typedef char *niggers;
  // But this is a bad practice
  // because its make hard to know the variables are pointer or not

  fiveNiggers x = { 1, 2, 3, 4, 5 };

  point_t p = { .x = 20, .y = 40 };

  printf ("%d, %d", p.x, p.y);
}
