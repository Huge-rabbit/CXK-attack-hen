/*
 * @Author: Huge-rabbit 1372223484@qq.com
 * @Date: 2022-10-15 10:36:22
 * @LastEditors: Huge-rabbit 1372223484@qq.com
 * @LastEditTime: 2022-10-19 17:07:03
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


SDL_Window * win = NULL;
SDL_Surface * screen=NULL;
SDL_Renderer * renderer = NULL;
SDL_Surface * img = NULL;
SDL_Texture * kun = NULL;





int main(int argc,char *argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Can not init video,%s",SDL_GetError);
        return 1;
    }

    win = SDL_CreateWindow("cxk",
                            SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
                            WIDTH,HEIGHT,
                            SDL_WINDOW_SHOWN);
    
    screen=SDL_GetWindowSurface(win);
    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    
    img = IMG_LoadTexture(renderer,"materials/image/background1.png");
    kun = IMG_LoadTexture(renderer,"materials/image/cxk1.png");

    SDL_Rect place = {0,200,50,61};

    

    int goout = 1;
    while(goout)
    {   
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                goout = 0;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_UP:
                    place.y-=5;
                    break;
                case SDLK_LEFT:
                    place.x-=5;
                    break;
                case SDLK_RIGHT:
                    place.x+=5;
                    break;
                case SDLK_DOWN:
                    place.y+=5;
                    break;
                default:
                    break;
                }
                break;


            default:
                break;
            }
            
        }
        //SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,img,NULL,NULL);
        SDL_RenderCopy(renderer,kun,NULL,&place);
        
        SDL_RenderPresent(renderer);
        //SDL_UpdateWindowSurface(win);
        SDL_Delay(20);
    }

    SDL_FreeSurface(img);
    SDL_FreeSurface(kun);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}