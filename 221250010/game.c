/*
 * @Author: Huge-rabbit 1372223484@qq.com
 * @Date: 2022-10-15 10:36:22
 * @LastEditors: Huge-rabbit 1372223484@qq.com
 * @LastEditTime: 2022-10-15 10:38:28
 * @FilePath: \2022-cpl-coding-1d:\Teamwork\CXK-attack-hen\221250010\game.c
 * @Description: 
 * 
 * Copyright (c) 2022 by Huge-rabbit 1372223484@qq.com, All Rights Reserved. 
 */
#include<SDL2/SDL.h>
#include<stdio.h>

#define HEIGHT 400
#define WIDTH 400

void update()
{
    printf("R\n");
}

int main(int argc,char *argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Can not init video,%s",SDL_GetError);
        return 1;
    }

    SDL_Window * win = SDL_CreateWindow("hill",
                                    SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
                                    WIDTH,HEIGHT,
                                    SDL_WINDOW_SHOWN);
    
    SDL_Surface * screen=SDL_GetWindowSurface(win);

    while(1)
    {   
        SDL_Event event;
        if(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                break;
            }
        }

        update();
        SDL_UpdateWindowSurface(win);

    }

    SDL_DestroyWindow(win);
    return 0;
}