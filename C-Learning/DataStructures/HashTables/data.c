/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void      get_data(char *filename, union Player *players, int nb)
{
  FILE    *file   = NULL;
  char    *token  = NULL;

  if ((file = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "Error args.\n");
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < nb; i++) {
    char line[SIZE_LINE] = { 0 };
    fgets(line, SIZE_LINE, file);
    token = strtok(line, ",");
    players[i].pl = calloc(1, sizeof(PL));
    strncpy(players[i].pl->name, token, strlen(token));
    token = strtok(NULL, ",");
    players[i].pl->elo = strtol(token, NULL, 10);
    token = NULL;
  }
}
