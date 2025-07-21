#ifndef LIST_H
#define LIST_H
#include <stdlib.h>

/* Define a structure for linked list elements */
struct ListElmt{
  void *data;
  struct ListElmt *next;
};

/* Define a structure for linked list */
struct List {
  int size;

  int (*match)(const void *key1, const void *key2);
  void (*destroy)(void *data);

  struct ListElmt *head;
  struct ListElmt *tail;
};


/* Public interface */
void list_init(struct List *list, void (*destroy)(void *data));

void list_destroy(struct List *list);

int list_ins_next(struct List *list, struct ListElmt *element, const void *data);

int list_rem_next(struct List *list, struct ListElmt *element, void **data);

int alloc_frame(struct List *frames);

#define list_size(list) ((list)->size)

#define list_head(list) ((list)->head)

#define list_tail(list) ((list)->tail)

#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)

#define list_is_tail(list,element) ((element)->next == NULL ? 1 : 0)

#define list_data(element) ((element)->data)

#define list_next(element) ((element)->next)

#endif /* ifndef LIST_H */
