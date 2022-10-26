/*
 * @Author: Huge-rabbit 1372223484@qq.com
 * @Date: 2022-10-23 21:21:03
 * @LastEditors: Huge-rabbit 1372223484@qq.com
 * @LastEditTime: 2022-10-25 21:32:51
 * @FilePath: \PlaneWar-maind:\Teamwork\CXK-attack-hen\221250010\resource.c
 * @Description: 
 * 
 * Copyright (c) 2022 by Huge-rabbit 1372223484@qq.com, All Rights Reserved. 
 */
#include"resource.h"


SDL_Texture * BackgroundImage = NULL;
SDL_Texture * kun = NULL;
SDL_Texture * menuImage = NULL;


void LoadResource(SDL_Renderer * renderer)
{
    BackgroundImage = IMG_LoadTexture(renderer,"materials/image/background1.png");
    kun = IMG_LoadTexture(renderer,"materials/image/cxk1.png");
    menuImage = IMG_LoadTexture(renderer,"materials/image/menuImage.png");
}

SDL_Texture * chooseTexture(int a)
{
    switch (a)
    {
    case 1:
        return BackgroundImage;

    case 2:
        return kun;
    

    case 3:
        return menuImage;
        
    default:
        return NULL;
    }
}

void DestroyResource()
{
    SDL_DestroyTexture(BackgroundImage);
    SDL_DestroyTexture(kun);
    SDL_DestroyTexture(menuImage);

}