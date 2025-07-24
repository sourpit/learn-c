#ifndef CHTBL_H
#define CHTBL_H

#include <stdlib.h>

#include "list.h"

/* Chained Hash Table */
struct CHTbl {
  int buckets;

  int (*h)(const void *key);
  int (*match)(const void *key1, const void *key2);
  void (*destroy)(void *data);

  int size;
  List *table;
};


int chtbl_init(struct CHTbl *htbl, int buckets, int (*h)(const void *key), \
               int (*match)(const void *key1, const void *key2), \
               void (*destroy)(void *data));

void chtbl_destroy(struct CHTbl *htbl);

int chtbl_insert(struct CHTbl *htbl, const void *data);

int chtbl_remove(struct CHTbl *htbl, void **data);

int chtbl_lookup(const CHTbl *htbl, void **data);

#define chtbl_size(htbl) ((htbl)->size)

#endif /* ifndef CHTBL_H */
