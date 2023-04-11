/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#include <stdbool.h>
#include "stack_array.h"

void    init(Stack *stack)
{
  stack->size = 0;
}

bool    is_empty(Stack *stack)
{
  return stack->size == 0;
}

void    push(Stack *stack, void *elem)
{
  stack->data[stack->size++] = elem;  
}

void    *pop(Stack *stack)
{
  stack->size--;

  return stack->data[stack->size];  
}
