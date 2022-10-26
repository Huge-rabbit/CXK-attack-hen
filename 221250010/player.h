#ifndef PLAYER_H
#define PLAYER_H
#include<SDL2/SDL.h>

#define CXK_SPEED 10

typedef struct 
{
    SDL_Rect rect;
}CXK;


CXK * Creat_CXK(int x,int y,int w,int h);
void CXK_Move(CXK * p,int x,int y);

#endif