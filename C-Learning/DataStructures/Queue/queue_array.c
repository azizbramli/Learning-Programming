/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#include <stdbool.h>
#include "queue_array.h"

bool    is_empty(Queue *queue)
{
  return queue->size == 0;
}

void    push(Queue *queue, void *elem, int size)
{
  if (queue->size < size) {
    queue->data[queue->head++] = elem;
    queue->size++;
  }
  queue->head = (queue->head >= size) ? 0 : queue->head;
}

void    *pop(Queue *queue, int size)
{
  void    *elem;

  if (queue->size > 0) {
    queue->data[queue->tail] = "X";
    elem = queue->data[queue->tail++];
    queue->size--;
  }
  queue->tail = (queue->tail >= size) ? 0 : queue->tail;
  return elem;
}
