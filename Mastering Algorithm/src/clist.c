#include "clist.h"
#include <string.h>

void clist_init(struct CList *list, void (*destroy)(void *data))
{
  list->size = 0;
  list->destroy = destroy;
  list->head = NULL;

  return;
}

void clist_destroy(struct CList *list)
{
  void *data;

  while(clist_size(list) > 0)
    if(!clist_rem_next(list, list->head, (void **)&data) && list->destroy)
      list->destroy(data);

  memset(list, 0, sizeof(struct CList));

  return;
}

int clist_ins_next(struct CList *list, struct CListElmt *element, const void *data)
{
  struct CListElmt *new_element;

  new_element = (struct CListElmt *)malloc(sizeof(struct CListElmt));
  if(!new_element)
    return -1;

  new_element->data = (void *)data;

  if(!clist_size(list)) {
    new_element->next = new_element;
    list->head = new_element;
  }
  else {
    new_element->next = element->next;
    element->next = new_element;
  }

  list->size++;

  return 0;
}

int clist_rem_next(struct CList *list, struct CListElmt *element, void **data)
{
  struct CListElmt *old_element;

  if(!clist_size(list))
    return -1;

  *data = element->next->data;

  if(element->next == element) {
    old_element = element->next;
    list->head = NULL;
  }

  else {
    old_element = element->next;
    element->next = element->next->next;

    if(old_element == clist_head(list))
      list->head = old_element->next;
  }

  free(old_element);

  list->size--;

  return 0;
}
