#include <string.h>

#include "dlist.h"

void dlist_init(struct DList *list, void (*destroy)(void *data))
{
  list->size = 0;
  list->destroy = destroy;
  list->head = NULL;
  list->tail = NULL;

  return;
}

void dlist_destroy(struct DList *list)
{
  void *data;

  while(dlist_size(list) > 0) {
    if(!dlist_remove(list,dlist_tail(list), (void **)&data) && list->destroy)
      list->destroy(data);
  }

  memset(list, 0, sizeof(struct DList));

  return;
}

int dlist_ins_next(struct DList *list, struct DListElmt *element, const void *data)
{
  struct DListElmt *new_element;

  if(!element && dlist_size(list))
    return -1;

  new_element = (struct DListElmt *)malloc(sizeof(struct DListElmt));
  if(!new_element)
    return -1;

  new_element->data = (void *)data;

  if(!dlist_size(list)) {
    list->head = new_element;
    list->head->prev = NULL;
    list->head->next = NULL;
    list->tail = new_element;
  }

  else{
    new_element->next = element->next;
    new_element->prev = element;

    if (!element->next)
      list->tail = new_element;
    else
     element->next->prev = new_element;
  }

  list->size++;

  return 0;
}

int dlist_ins_prev(struct DList *list, struct DListElmt *element, const void *data)
{
  struct DListElmt *new_element;

  if(!element && dlist_size(list))
    return -1;

  new_element = (struct DListElmt *)malloc(sizeof(struct DListElmt));
  if(!new_element)
    return -1;

  if (!dlist_size(list)) {
    list->head = new_element;
    list->head->prev = NULL;
    list->head->next = NULL;
    list->tail = new_element;
  }
  else {
    new_element->next = element;
    new_element->prev = element->prev;

    if (!element->prev)
      list->head = new_element;
    else
     element->prev->next = new_element;

    element->prev = new_element;
  }

  list->size++;

  return 0;
}

int dlist_remove(struct DList *list, struct DListElmt *element, void **data)
{
  if(!element || !dlist_size(list))
    return -1;

  *data = element->data;

  if (element == list->head) {
    list->head = element->next;

    if (!list->head)
      list->tail = NULL;
    else
     element->next->prev = NULL;
  }

  else {
    element->prev->next = element->next;

    if(!element->next)
      list->tail = element->prev;
    else
     element->next->prev = element->prev;
  }

  free(element);

  list->size--;

  return 0;
}
