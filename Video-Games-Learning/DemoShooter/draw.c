/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#include "draw.h"

void                draw_background(SDL_Renderer *ren, SDL_Texture *bg, int offset)
{
    SDL_Rect        dest = (SDL_Rect) {offset, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

    SDL_QueryTexture(bg, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(ren, bg, NULL, &dest);
}

void                draw_entity(SDL_Renderer *ren, Entity *p)
{
    SDL_Rect        dest = (SDL_Rect) {p->x, p->y, PLAYER_WIDTH, PLAYER_HEIGHT};

    SDL_RenderCopy(ren, p->tex, NULL, &dest);
}
