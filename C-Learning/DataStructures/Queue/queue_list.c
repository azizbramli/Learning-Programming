/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#include <stdbool.h>
#include <stddef.h>
#include "queue_list.h"

static  Queue *last_elem;

bool    is_empty(Queue *queue)
{
  return queue == NULL;
}

void    push(Queue **queue, Queue *elem)
{
  if (*queue == NULL) {
    *queue = elem;
    last_elem = elem;
  } else {
    last_elem->next = elem;
    last_elem = elem;
  }
  last_elem->next = NULL;
}

Queue   *pop(Queue **queue)
{
  Queue *elem = *queue;

  *queue = elem->next;
  return elem;
}
