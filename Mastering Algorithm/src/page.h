#ifndef PAGE_H
#define PAGE_H

#include "clist.h"
struct Page {
  int number;
  int reference;
};

int replace_page(struct CListElmt **current);

#endif /* ifndef PAGE_H */
