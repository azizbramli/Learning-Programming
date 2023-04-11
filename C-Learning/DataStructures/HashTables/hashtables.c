/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtables.h"

void            init(HashTable *ht, unsigned int size)
{
  ht->size = size;
  ht->keys = calloc(size, sizeof(PL *));
}

void            insert(HashTable *ht, PL *player, hash_f hash)
{
  PL            *tmp = NULL;
  unsigned int  code = hash(player->name, strlen(player->name)) % ht->size;

  tmp = ht->keys[code];
  if (tmp == NULL) {
    ht->keys[code] = player;
  } else {
    player->next    = tmp;
    ht->keys[code]  = player;
  }
}

int             search(HashTable *ht, char *key, hash_f hash)
{
  int           elo  = -1;
  unsigned int  code    = hash(key, strlen(key)) % ht->size;
  PL            *player = ht->keys[code];

  while (player != NULL) {
    if(strncmp(player->name, key, strlen(key)) == 0) {
      elo = player->elo;
    }
    player = player->next;
  }
  return elo;
}

void            display(HashTable *ht, unsigned int size)
{
  PL  *player = NULL;

  for (int i = 0; i < size; i++) {
    player = ht->keys[i];
    printf("%s[[%-3d]]%s", PINK, i, EMPTY);
    while (player != NULL) {
      printf("%s->", BLUE);
      printf("(%s, %d)%s", player->name, player->elo, EMPTY);
      player = player->next;
    }
    putchar('\n');
  }
}
