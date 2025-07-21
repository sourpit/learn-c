#ifndef CLIST_H
#define CLIST_H

#include <stdlib.h>

struct CListElmt {
  void *data;
  struct CListElmt *next;
};

struct CList {
  int size;

  int (*match)(const void *key1, const void *key2);
  void (*destroy)(void *data);

  struct CListElmt *head;
};

void clist_init(struct CList *list, void (*destroy)(void *data));

void clist_destroy(struct CList *list);

int clist_ins_next(struct CList *list, struct CListElmt *element,\
                   const void *data);

int clist_rem_next(struct CList *list, struct CListElmt *element,\
                   void **data);

#define clist_size(list) ((list)->size)

#define clist_head(list) ((list)->head)

#define clist_data(element) ((element)->data)

#define clist_next(element) ((element)->next)

#endif /* ifndef CLIST_H */
