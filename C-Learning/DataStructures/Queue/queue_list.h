/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#ifndef _QUEUE_LIST_H_
#define _QUEUE_LIST_H_

typedef struct    s_queue
{
  void            *data;
  struct s_queue  *next;
}                 Queue;

#endif
