/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#ifndef _STACK_ARRAY_H_
#define _STACK_ARRAY_H_

#define MAX_SIZE 128

typedef struct
{
  int   size;
  void  *data[MAX_SIZE];
}       Stack;

#endif
