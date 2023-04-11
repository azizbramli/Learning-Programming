/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */


#include "init.h"
#include "game.h"
#include "structs.h"

int         main(void)
{
  Game      game;

  init(&game);
  run(&game);
  quit(&game);

  return 0;
}
