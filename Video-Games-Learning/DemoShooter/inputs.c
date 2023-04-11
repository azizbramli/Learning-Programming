/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#include "structs.h"

static void     handle_keyDown(SDL_KeyboardEvent *event, Game *game) {
    if (event->repeat == 0) {
        if (event->keysym.scancode == SDL_SCANCODE_UP) {
            game->player->vely = -SPEED_PLAYER;
        }
        if (event->keysym.scancode == SDL_SCANCODE_DOWN) {
            game->player->vely = SPEED_PLAYER;
        }
        if (event->keysym.scancode == SDL_SCANCODE_LEFT) {
            game->player->velx = -SPEED_PLAYER;
        }
        if (event->keysym.scancode == SDL_SCANCODE_RIGHT) {
            game->player->velx = SPEED_PLAYER;
        }
    }
}

static void     handle_keyUp(SDL_KeyboardEvent *event, Game *game) {
    if (event->repeat == 0) {
        if (event->keysym.scancode == SDL_SCANCODE_UP) {
            game->player->vely = 0;
        }
        if (event->keysym.scancode == SDL_SCANCODE_DOWN) {
            game->player->vely = 0;
        }
        if (event->keysym.scancode == SDL_SCANCODE_LEFT) {
            game->player->velx = 0;
        }
        if (event->keysym.scancode == SDL_SCANCODE_RIGHT) {
            game->player->velx = 0;
        }
    }
}

void            get_inputs(SDL_Event *event, Game *game) {
    while (SDL_PollEvent(event)) {
        switch (event->type) {
            case SDL_QUIT:
                game->end = true;
                break;
            case SDL_KEYDOWN:
                handle_keyDown(&(event->key), game);
                break;
            case SDL_KEYUP:
                handle_keyUp(&(event->key), game);
                break;
            default:
                break;
        }
    }
}
