#include <stdlib.h>
#include <string.h>

#include "event.h"
#include "events.h"
#include "queue.h"

int receive_event(Queue *events, const Event *event)
{
  Event *new_event;
  new_event = (Event *)malloc(sizeof(Event));
  if(!new_event)
    return -1;

  memcpy(new_event, event, sizeof(Event));

  if (queue_enqueue(events, new_event))
    return -1;

  return 0;
}

int process_event(Queue *events, int (*dispatch)(Event *event))
{
  Event *event;

  if(!queue_size(events))
    return -1;

  else {
    if (queue_dequeue(events, (void **)&event))
      return -1;

    else {
      dispatch(event);
      free(event);
    }
  }
  return 0;
}
