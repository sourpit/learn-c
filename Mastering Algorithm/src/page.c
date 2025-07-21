#include "clist.h"
#include "page.h"

int replace_page(struct CListElmt **current)
{
  while(((struct Page *)(*current)->data)->reference) {
    ((struct Page *)(*current)->data)->reference = 0;
    *current = clist_next(*current);
  }

  return ((struct Page *)(*current)->data)->number;
}
