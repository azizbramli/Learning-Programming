/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#ifndef _QUEUE_ARRAY_H_
#define _QUEUE_ARRAY_H_

#define MAX_SIZE 128

typedef struct
{
  int   head;
  int   tail;
  int   size;
  void  *data[MAX_SIZE];
}       Queue;

#endif
