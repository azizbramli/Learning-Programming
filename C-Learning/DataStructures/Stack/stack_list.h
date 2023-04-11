/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#ifndef _STACK_LIST_H_
#define _STACK_LIST_H_

#include <stdbool.h>

typedef struct    s_stack
{
  void            *data;
  struct s_stack  *next;
}                 Stack;

bool    is_empty(Stack *);
void    push(Stack **, Stack *);
Stack   *pop(Stack **);

#endif
