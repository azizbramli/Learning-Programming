/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "hash_functions.h"
#include "hashtables.h"

int             main(int argc, char *argv[])
{
  int           size                = strtoul(argv[1], NULL, 10);
  int           nb                  = strtoul(argv[2], NULL, 10);
  union Player  players[NB_RECORDS] = { 0 };
  PL            *player             = { 0 };
  HashTable     ht_linked           = { 0 };

  get_data(argv[NB_ARGS], players, nb);
  init(&ht_linked, size);
  display(&ht_linked, size);

  for (int i = 0; i < nb; i++) {
    insert(&ht_linked, players[i].pl, elf_hash);
  }

  printf("--------------------\n");
  display(&ht_linked, size);
  printf("--------------------\n");

  int elo = 0;

  printf((elo = search(&ht_linked, "Carlsen", elf_hash)) != 0 ? "%-25s%d\n" : "Player not found", "Carlsen", elo);
  printf((elo = search(&ht_linked, "Anand", elf_hash)) != 0 ? "%-25s%d\n" : "Player not found", "Anand", elo);
  printf((elo = search(&ht_linked, "Nakamura", elf_hash)) != 0 ? "%-25s%d\n" : "Player not found", "Nakamura", elo);
  printf((elo = search(&ht_linked, "Caruana", elf_hash)) != 0 ? "%-25s%d\n" : "Player not found", "Caruana", elo);
  return 0;
}
