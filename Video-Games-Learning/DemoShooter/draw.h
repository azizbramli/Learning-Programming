/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#ifndef _DRAW_H_
#define _DRAW_H_

#include "structs.h"

void    draw_background(SDL_Renderer *, SDL_Texture *, int);
void    draw_entity(SDL_Renderer *, Entity *);

#endif