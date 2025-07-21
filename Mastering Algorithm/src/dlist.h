#ifndef DLIST_H
#define DLIST_H

#include <stdlib.h>

/* Define a structure for linked list elements */
struct DListElmt{
  void *data;
  struct DListElmt *prev;
  struct DListElmt *next;
};

/* Define a structure for linked list */
struct DList {
  int size;

  int (*match)(const void *key1, const void *key2);
  void (*destroy)(void *data);

  struct DListElmt *head;
  struct DListElmt *tail;
};

void dlist_destroy(struct DList *list);
int dlist_ins_next(struct DList *list, struct DListElmt *element, const void *data);
int dlist_ins_prev(struct DList *list, struct DListElmt *element, const void *data);
int dlist_remove(struct DList *list, struct DListElmt *element, void **data);

#define dlist_size(list) ((list)->size)

#define dlist_tail(list) ((list)->tail)

#define dlist_is_head(list, element) ((element) == (list)->head ? 1 : 0)

#define dlist_is_tail(list,element) ((element)->next == NULL ? 1 : 0)

#define dlist_data(element) ((element)->data)

#define dlist_next(element) ((element)->next)

#endif /* ifndef DLIST_H */
