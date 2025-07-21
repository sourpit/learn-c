#include <stdlib.h>

#include "frames.h"
#include "list.h"

int alloc_frame(struct List *frames) {
  int frame_number, *data;

  if(!list_size(frames))
    return -1;

  else {
    if(list_rem_next(frames, NULL, (void **)&data))
      return -1;

    else {
      frame_number = *data;

      free(data);
    }
  }

  return frame_number;
}

int free_frame(struct List *frames, int frame_number)
{
  int *data;

  data = (int *) malloc(sizeof(int));
  if (!data)
    return -1;

  *data = frame_number;

  if (list_ins_next(frames, NULL, data))
    return -1;

  return 0;
}
