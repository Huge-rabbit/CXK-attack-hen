#ifndef RESOURCE_H
#define RESOURCE_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>



void LoadResource(SDL_Renderer * render);
SDL_Texture * chooseTexture(int a);
void DestroyResource();

#endif