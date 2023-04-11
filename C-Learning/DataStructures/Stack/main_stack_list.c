/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack_list.h"

static void display(Stack *stack) {
  Stack   *tmp = stack;
  
  while (tmp != NULL) {
    printf("%s\n", (char *) tmp->data);
    tmp = tmp->next;
  }
}

int         main(int argc, char *argv[])
{
  Stack     *stack = NULL;

  for (int i = 1; i < argc; i++) {
    Stack *elem = malloc(sizeof(Stack));
    elem->data = argv[i];
    elem->next = NULL;
    push(&stack, elem);
  }
  puts("\n ---------- \n");
  display(stack);
  puts("\n ---------- \n");
  pop(&stack);
  pop(&stack);
  display(stack);
  puts("\n ---------- \n");
  Stack *e1 = calloc(1, sizeof(Stack));
  e1->data = "D";
  e1->next = NULL;
  push(&stack, e1);
  Stack *e2 = calloc(1, sizeof(Stack));
  e2->data = "E";
  e2->next = NULL;
  push(&stack, e2);
  Stack *e3 = calloc(1, sizeof(Stack));
  e3->data = "F";
  e3->next = NULL;
  push(&stack, e3);
  display(stack);
  puts("\n ---------- \n");
  pop(&stack);
  pop(&stack);
  pop(&stack);
  display(stack);
  puts("\n ---------- \n");
  pop(&stack);
  display(stack);
  puts("\n ---------- \n");

  return 0;
}
