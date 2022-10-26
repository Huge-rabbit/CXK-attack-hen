#ifndef ENEMY_H
#define ENEMY_H

#include<SDL2/SDL.h>

typedef struct 
{
    SDL_Rect rect;
    SDL_Rect imageRect;
}ENEMY;

ENEMY * Creat_ENEMY(int x,int y,int w,int h);
void EnemyMove(SDL_Renderer * renderer,ENEMY * p);

#endif