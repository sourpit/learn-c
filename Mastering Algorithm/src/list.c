#include "list.h"
#include <string.h>

void list_init(struct List *list, void (*destroy)(void *data))
{
  list_size(list) = 0;
  list->destroy = destroy;
  list_head(list) = NULL;
  list_tail(list) = NULL;
}

void list_destroy(struct List *list)
{
  void *data;

  while (list_size(list) > 0) {
    if (list_rem_next(list, NULL, (void **)&data) == 0 && list->destroy)
    {
      list->destroy(data);
    }
  }

  memset(list, 0, sizeof(struct List));

  return;
}

int list_ins_next(struct List *list, struct ListElmt *element, const void *data)
{
  struct ListElmt *new_element;

  new_element = (struct ListElmt *) malloc(sizeof(struct ListElmt));
  if (!new_element)
    return -1;

  new_element->data = (void *)data;

  if (!element) {
    if (!list_size(list))
      list->tail = new_element;

    new_element->next = list_head(list);
    list_head(list) = new_element;
  }
  else {
    if (!element->next)
      list_tail(list) = new_element;

    new_element->next = element->next;
    element->next = new_element;
  }

  list->size++;

  return 0;
}

int list_rem_next(struct List *list, struct ListElmt *element, void **data)
{
  struct ListElmt *old_element;

  if (!list_size(list))
    return -1;

  if (!element) {
    *data = list->head->data;
    old_element = list->head;
    list->head = list->head->next;

    if (list_size(list))
      list->tail = NULL;
  }

  else {
    if (!element->next)
      return -1;

    *data = element->next->data;
    old_element = element->next;
    element->next = element->next->next;

    if (!element->next)
      list->tail = element;
  }

  free (old_element);

  list->size--;

  return 0;
}
