/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#ifndef _STACK_ARRAY_H_
#define _STACK_ARRAY_H_

#include <stdbool.h>

#define MAX_SIZE 128

typedef struct
{
  int   size;
  void  *data[MAX_SIZE];
}       Stack;

void    init(Stack *);
bool    is_empty(Stack *);
void    push(Stack *, void *);
void    *pop(Stack *);

#endif
