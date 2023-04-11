/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#ifndef _STRUCTS_H_
#define _STRUCTS_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <stdbool.h>

#define             SCREEN_WIDTH    1280
#define             SCREEN_HEIGHT   720
#define             PLAYER_WIDTH    97
#define             PLAYER_HEIGHT   37
#define             NB_LEVELS       8
#define             SPEED_PLAYER    10
#define             DELAY           33
#define             OFFSET          4

enum                STATE           { ALIVE, DEAD };

typedef struct      {
    int             x;
    int             y;
    int             velx;
    int             vely;
    int             lives;
    enum STATE      state;
    SDL_Texture     *tex;
}                   Entity;

typedef struct      {
    bool            end;
    int             num;
    SDL_Texture     *tex;
    Mix_Music       *music;
}                   Level;

typedef struct      {
    bool            end;
    int             curr_level;
    Level           levels[NB_LEVELS];
    SDL_Window      *win;
    SDL_Renderer    *ren;
    Entity          *player;
}                   Game;

#endif
