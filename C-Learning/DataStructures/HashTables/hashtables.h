/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#ifndef _HASHTABLES_H_
#define _HASHTABLES_H_

#include "structs.h"

void  display(HashTable *, unsigned int);
void  init(HashTable *, unsigned int);
void  insert(HashTable *, PL *, hash_f);
int   search(HashTable *, char *, hash_f);

#endif
