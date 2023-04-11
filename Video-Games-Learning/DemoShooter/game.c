/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */

#include "draw.h"
#include "inputs.h"
#include "structs.h"


static void         move_player(Entity *player)
{
    player->x += player->velx;
    player->y += player->vely;
}

static void         update_player(Entity *player)
{
    move_player(player);
}

static void         render(Game *game, int offset)
{
    SDL_RenderClear(game->ren);
    draw_background(game->ren, game->levels[game->curr_level].tex, offset);
    draw_entity(game->ren, game->player);
    SDL_RenderPresent(game->ren);
}

static void         run_level(SDL_Event *event, Game *game)
{
    int             offset = 0;

    Mix_PlayMusic(game->levels[game->curr_level].music, 1);
    while (!game->levels[game->curr_level].end && !game->end) {
        get_inputs(event, game);
        update_player(game->player);
        render(game, offset);
        offset -= OFFSET;
        SDL_Delay(DELAY);
    }
    Mix_FreeMusic(game->levels[game->curr_level].music);
}

void                run(Game *game) {
    SDL_Event       event; 

    while (!game->end) {
        run_level(&event, game);
        game->curr_level++;
    }
}
