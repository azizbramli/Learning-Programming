/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me>
 *
 */

#ifndef _STRUCTS_H_
#define _STRUCTS_H_

#include "constants.h"

typedef unsigned int (*hash_f)(const char *, unsigned int);

typedef struct  PA
{
  int           elo;
  char          name[SIZE_NAME];
}               PA;

typedef struct  PL
{
  int           elo;
  char          name[SIZE_NAME];
  struct        PL *next;
}               PL;

union           Player
{
  PA            *pa;
  PL            *pl;
};

typedef struct
{
  unsigned int  size;
  PL            **keys;
}               HashTable;

#endif
