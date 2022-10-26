/*
 * @Author: Huge-rabbit 1372223484@qq.com
 * @Date: 2022-10-15 10:36:22
 * @LastEditors: Huge-rabbit 1372223484@qq.com
 * @LastEditTime: 2022-10-25 22:09:18
 * @FilePath: \PlaneWar-maind:\Teamwork\CXK-attack-hen\221250010\game.c
 * @Description: 
 * 
 * Copyright (c) 2022 by Huge-rabbit 1372223484@qq.com, All Rights Reserved. 
 */
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<stdio.h>

#include"player.h"
#include"resource.h"
#include"mainmenu.h"

#define HEIGHT 600
#define WIDTH 1000



SDL_Window * win = NULL;
SDL_Renderer * renderer = NULL;

//SDL_Texture * BackgroundImage = NULL;
//SDL_Texture * kun = NULL;

CXK * myCXK = NULL;



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
    
    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    
    LoadResource(renderer);


    myCXK = Creat_CXK(WIDTH / 2,HEIGHT / 2,50,61);

    int goout = 1;
    int mousex = 0;
    int mousey = 0;
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
            case SDL_MOUSEMOTION:
                mousex = event.motion.x;
                mousey = event.motion.y;
                
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_m:
                    EnterMainMenu(renderer);
                    break;
                case SDLK_w:
                    myCXK->rect.y-=5;
                    break;
                case SDLK_a:
                    myCXK->rect.x-=5;
                    break;
                case SDLK_d:
                    myCXK->rect.x+=5;
                    break;
                case SDLK_s:
                    myCXK->rect.y+=5;
                    break;
                default:
                    break;
                }
                break;


            default:
                break;
            }
            
        }
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,chooseTexture(1),NULL,NULL);//»æÖÆ±³¾°

        CXK_Move(myCXK,mousex,mousey);
        SDL_RenderCopy(renderer,chooseTexture(2),NULL,&myCXK->rect);
        
        SDL_RenderPresent(renderer);
        //SDL_UpdateWindowSurface(win);
        SDL_Delay(20);
    }


    DestroyResource();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();
    
    return 0;
}