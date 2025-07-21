#include "pointer.h"
#include <stdio.h>

int main (void)
{
  struct List *list;
  struct ListElmt *element;

  int choices;
  fprintf(stdout, \
      "Doubly Linked List\n \
      1. Init,\n            \
      2. Destroy,\n         \
      3. Insert,\n          \
      4. Remove\n");
  sscanf("Choose 1:", "%d", &choices);

  switch(choices) {
    case 1:
      list_init(list, element->data);
      break;

    case 2:

  }

}
