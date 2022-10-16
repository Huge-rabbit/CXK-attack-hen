/*
 * @Author: Huge-rabbit 1372223484@qq.com
 * @Date: 2022-10-15 10:36:22
 * @LastEditors: Huge-rabbit 1372223484@qq.com
 * @LastEditTime: 2022-10-16 19:45:52
 * @FilePath: \2022-cpl-coding-1d:\Teamwork\CXK-attack-hen\221250010\game.c
 * @Description: 
 * 
 * Copyright (c) 2022 by Huge-rabbit 1372223484@qq.com, All Rights Reserved. 
 */
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<stdio.h>

#define HEIGHT 600
#define WIDTH 1000

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

    SDL_Window * win = SDL_CreateWindow("cxk",
                                    SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
                                    WIDTH,HEIGHT,
                                    SDL_WINDOW_SHOWN);
    
    SDL_Surface * screen=SDL_GetWindowSurface(win);
    
    SDL_Surface * img = IMG_Load("materials/image/background1.png");
    SDL_Rect src = {0,0,img->w,img->h};
    SDL_BlitSurface(img,&src,screen,&src);

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

    SDL_FreeSurface(img);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}