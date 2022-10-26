#ifndef RESOURCE_H
#define RESOURCE_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_mixer.h>


void LoadResource(SDL_Renderer * render);
SDL_Texture * chooseTexture(int a);
Mix_Music * chooseMusic(int a);
void DestroyResource();

#endif