/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#include <stddef.h>
#include "stack_list.h"

bool    is_empty(Stack *stack)
{
  return stack == NULL;
}

void    push(Stack **stack, Stack *elem)
{
  elem->next = *stack;
  *stack = elem;
}

Stack   *pop(Stack **stack)
{
  Stack *elem = *stack;

  *stack = elem->next;
  return elem;  
}
