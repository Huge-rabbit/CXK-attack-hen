#ifndef PLAYER_H
#define PLAYER_H
#include<SDL2/SDL.h>


typedef struct 
{
    SDL_Rect rect;
}CXK;


CXK * Creat_CXK(int x,int y,int w,int h);

#endif