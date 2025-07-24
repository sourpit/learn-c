#include <stdio.h>

int main(void) {
  int a = 0, b = 0;
  int *pa = &a, *pb = NULL;

  if (a != 0)
    fprintf(stdout, "a is true\n");
  else if (a == 0) {
    fprintf(stdout, "a is false\n");
  }

  if (b == 0)
    fprintf(stdout, "b is False\n");
  else if (b != 0) {
    fprintf(stdout, "b is True\n");
  }

  fprintf(stdout, "--------\n");

  if (a) {
    fprintf(stdout, "a is true\n");
  } else if (!a) {
    fprintf(stdout, "a is false\n");
  }

  if (!b) {
    fprintf(stdout, "b is false\n");
  } else if (b) {
    fprintf(stdout, "b is true\n");
  }

  fprintf(stdout, "--------\n");

  if (pa != NULL)
    fprintf(stdout, "pa is true\n");

  else
    fprintf(stdout, "pa is false\n");

  if (pb == NULL)
    fprintf(stdout, "pb is false\n");

  else
    fprintf(stdout, "pb is true\n");

  fprintf(stdout, "--------\n");

  if (pa)
    fprintf(stdout, "pa is true\n");

  else
    fprintf(stdout, "pa is false\n");

  if (!pb)
    fprintf(stdout, "pb is false\n");

  else
    fprintf(stdout, "pb is true\n");
}
