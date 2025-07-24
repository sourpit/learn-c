#include "list.h"
#include <string.h>
#include "chtbl.h"

int chtbl_init(struct CHTbl *htbl, int buckets, int (*h)(const void *), int (*match)(const void *, const void *), void (*destroy)(void *data))
{
  int i;

  if (!(htbl->table =(struct List *)malloc(buckets * sizeof(struct List))))
    return -1;

  htbl->buckets = buckets;

  for(i = 0; i < htbl->buckets; i++)
    list_init(&htbl->table[i], destroy);

  htbl->h = h;
  htbl->match = match;
  htbl->destroy = destroy;

  htbl->size = 0;

  return 0;
}

void chtbl_destroy(struct CHTbl *htbl)
{
  int i;

  for(i = 0; i < htbl->buckets; i++)
    list_destroy(&htbl->table[i]);

  free(htbl->table);

  memset(htbl, 0, sizeof(struct CHTbl));

  return;
}

int chtbl_insert(struct CHTbl *htbl, const void *data)
{
  void *temp;
  int bucket, retval;

  temp = (void *)data;

  if(!chtbl_lookup(htbl, &temp))
    return 1;

  bucket = htbl->h(data) % htbl->buckets;

  retval = list_ins_next(&htbl->table[bucket], NULL, data);
  if(!retval)
    htbl->size++;

  return retval;
}

int chtbl_remove(struct CHTbl *htbl, void **data)
{
  struct ListElmt *element, *prev;

  int bucket;

  bucket = htbl->h(*data) % htbl->buckets;

  prev = NULL;

  for(element = list_head(&htbl->table[bucket]); element;
      element = list_next(element)) {
    if(htbl->match(*data, list_data(element))) {
      if(!list_rem_next(&htbl->table[bucket], prev, data)) {
        htbl->size--;
        return 0;
      }

      else
        return -1;
    }

    prev = element;
  }

  return -1;
}

int chtbl_lookup(const struct CHTbl *htbl, void **data)
{
  struct ListElmt *element;
  int bucket;
  bucket = htbl->h(*data) % htbl->buckets;

  for(element = list_head(&htbl->table[bucket]); element;
      element = list_next(element)) {

    if(htbl->match(*data, list_data(element))) {
      *data = list_data(element);
      return 0;
    }
  }

  return -1;
}
