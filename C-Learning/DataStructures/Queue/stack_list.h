/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#ifndef _STACK_LIST_H_
#define _STACK_LIST_H_

#include <stddef.h>

typedef struct    s_stack
{
  void            *data;
  struct s_stack  *next;
}                 Stack;

#endif
