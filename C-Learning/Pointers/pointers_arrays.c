/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#include <stdio.h>

static void modify_arr(char arr[], int size)
{
  //t[3] = 'A';
  *(arr + 3) = 'A';
  for (int i = 0; i < size; i++) {
      printf("%c\t", arr[i]);
  }
  puts("");
}

int         main(void)
{
  char  arr[]     = "abcd";
  char  *p        = arr;
  char  (*pp)[5]  = &arr;

  modify_arr(arr, 4);
  modify_arr(&arr[0], 4);
  modify_arr(p, 4);
  modify_arr(pp[0], 4);
  printf("%p %p %p %p\n", arr, &arr[0], p, pp);
  printf("%p %p %p %p\n", arr + 1, &arr[0] + 1, p + 1, pp + 1);
  printf("%ld %ld %ld\n", sizeof(arr), sizeof(p), sizeof(pp));
  printf("%ld %ld %ld\n", sizeof(*arr), sizeof(*p), sizeof(*pp));
  p = arr;
  //arr = p;
  //p++;
  //arr++;
  printf("%c\n", arr[3]);
  printf("%c\n", p[3]);
  return 0;
}