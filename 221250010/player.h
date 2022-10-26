#ifndef PLAYER_H
#define PLAYER_H
#include<SDL2/SDL.h>
#include<math.h>
#include"resource.h"

#define CXK_SPEED 10

typedef struct 
{
    SDL_Rect rect;
    SDL_Rect imageRect;
}CXK;


CXK * Creat_CXK(int x,int y,int w,int h);
void CXK_Update(SDL_Renderer * renderer,CXK * p,int x,int y);

#endif