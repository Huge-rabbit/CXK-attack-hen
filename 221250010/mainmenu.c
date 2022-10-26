/*
 * @Author: Huge-rabbit 1372223484@qq.com
 * @Date: 2022-10-25 21:23:22
 * @LastEditors: Huge-rabbit 1372223484@qq.com
 * @LastEditTime: 2022-10-26 13:06:02
 * @FilePath: \PlaneWar-maind:\Teamwork\CXK-attack-hen\221250010\mainMenu.c
 * @Description: 
 * 
 * Copyright (c) 2022 by Huge-rabbit 1372223484@qq.com, All Rights Reserved. 
 */

#include"mainmenu.h"

int EnterMainMenu(SDL_Renderer * renderer)
{
    
    SDL_Rect menurect = {300,150,400,275};
    //Mix_Music * music = Mix_LoadMUS("materials/music/JustMimeticEnzyme.mp3");
    Mix_PlayMusic(chooseMusic(1),1);
    Mix_VolumeMusic(100);
    while(1)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_m:
                    Mix_VolumeMusic(0);
                    return 0;
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
        SDL_RenderCopy(renderer,chooseTexture(3),NULL,&menurect);//ªÊ÷∆≤Àµ•

        SDL_RenderPresent(renderer);
        SDL_Delay(20);
    }
}

