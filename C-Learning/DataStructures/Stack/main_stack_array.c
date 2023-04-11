/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#include <stdio.h>
#include "stack_array.h"

static void display(Stack *stack)
{
  for (int i = stack->size - 1; i >= 0; i--) {
    printf("%s\n", (char *) stack->data[i]);
  }
}

int         main(int argc, char *argv[])
{
  Stack  stack;

  init(&stack);
  for (int i = 1; i < argc; i++) {
    push(&stack, argv[i]);
  }
  puts("\n ---------- \n");
  display(&stack);
  puts("\n ---------- \n");
  pop(&stack);
  pop(&stack);
  display(&stack);
  puts("\n ---------- \n");
  push(&stack, "D");
  push(&stack, "E");
  push(&stack, "F");
  display(&stack);
  puts("\n ---------- \n");
  pop(&stack);
  pop(&stack);
  pop(&stack);
  display(&stack);
  puts("\n ---------- \n");
  pop(&stack);
  display(&stack);
  puts("\n ---------- \n");

  return 0;
}
