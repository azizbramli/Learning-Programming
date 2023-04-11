/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#include <stdlib.h>
#include "log.h"
#include "structs.h"

static SDL_Texture  *init_texture(SDL_Renderer *ren, const char *file)
{
    SDL_Texture     *tex = NULL;

    tex = IMG_LoadTexture(ren, file);
    if (tex == NULL) {
        log_error(stderr, "IMG_LoadTexture", "", SDL_Quit);
        exit(EXIT_FAILURE);
    }
    return tex;
}

static void         init_sdl()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        log_error(stderr, "SDL_Init", SDL_GetError(), NULL);
        exit(EXIT_FAILURE);
    }
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
}

static void         init_renderer(Game *game)
{
    game->ren = NULL;

    if ((game->ren = SDL_CreateRenderer(game->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)) == NULL) {
        log_error(stderr, "SDL_CreateRenderer", SDL_GetError(), SDL_Quit);
        exit(EXIT_FAILURE);
    }
}

static void         init_window(Game *game)
{
    game->win = NULL;

    if ((game->win = SDL_CreateWindow("R-Type", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN)) == NULL) {
        log_error(stderr, "SDL_CreateWindow", SDL_GetError(), SDL_Quit);
        exit(EXIT_FAILURE);
    }
}

static void         init_player(Game *game)
{
    if ((game->player = calloc(1, sizeof(Entity))) == NULL) {
        log_error(stderr, "Failed Init Player.", SDL_GetError(), SDL_Quit);
        exit(EXIT_FAILURE);
    }
    game->player->x     = 280;
    game->player->y     = 360;
    game->player->velx  = 0;
    game->player->vely  = 0;
    game->player->lives = 3;
    game->player->state = ALIVE;
    game->player->tex   = init_texture(game->ren, "assets/images/RType-SMS-R9-1.png");
}

static void         init_levels(Game *game)
{
    for (int i = 0; i < NB_LEVELS; i++) game->levels[i].end = false;
    for (int i = 0; i < NB_LEVELS; i++) game->levels[i].num = i;
    game->levels[0].tex = init_texture(game->ren, "assets/images/background_1.png");
}

void                init_audio(Game *game)
{
    int flags       = MIX_INIT_MP3;

    if (flags != Mix_Init(flags)) {
        log_error(stderr, "Failed Initialize Mixer.", Mix_GetError(), SDL_Quit);
        exit(EXIT_FAILURE);
    }

    Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
    game->levels[0].music = Mix_LoadMUS("assets/sons/snd_stage_1.mp3");
}

void                init(Game *game)
{
    init_sdl();
    init_window(game);
    init_renderer(game);
    init_player(game);
    init_levels(game);
    init_audio(game);
    game->curr_level    = 0;
    game->end           = false;
}

void                quit(Game *game)
{
    game->end = true;
    SDL_Quit();
}
