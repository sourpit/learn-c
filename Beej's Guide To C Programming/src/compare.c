#include <stdio.h>
#include <stdlib.h>

struct animal
{
  char *name;
  int legCount;
};

int compar (const void *elem1, const void *elem2);

int
main (void)
{
  struct animal a[4] = { { .name = "Dog", .legCount = 4 },
                         { .name = "Monkey", .legCount = 2 },
                         { .name = "Antelope", .legCount = 4 },
                         { .name = "Snake", .legCount = 0 } };

  qsort (a, 4, sizeof (struct animal), compar);

  for (int i = 0; i < 4; i++)
    printf ("%d: %s\n", a[i].legCount, a[i].name);
}

int
compar (const void *elem1, const void *elem2)
{
  const struct animal *animal1 = elem1;
  const struct animal *animal2 = elem2;

  if (animal1->legCount > animal2->legCount)
    return 1;

  if (animal1->legCount < animal2->legCount)
    return -1;

  return 0;
}
