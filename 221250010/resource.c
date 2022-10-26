#include"resource.h"


SDL_Texture * BackgroundImage = NULL;
SDL_Texture * kun = NULL;
SDL_Texture * menuImage = NULL;
SDL_Texture * hen1 = NULL;


Mix_Music * music = NULL;

void LoadResource(SDL_Renderer * renderer)
{
    BackgroundImage = IMG_LoadTexture(renderer,"materials/image/background1.png");
    kun = IMG_LoadTexture(renderer,"materials/image/cxk1.png");
    menuImage = IMG_LoadTexture(renderer,"materials/image/menuImage.png");
    hen1 = IMG_LoadTexture(renderer,"materials/image/hen1.png");

    music = Mix_LoadMUS("materials/music/JustMimeticEnzyme.mp3");
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
        

    



    case 101:
        return hen1;
    default:
        return NULL;
    }
}

Mix_Music * chooseMusic(int a)
{
    switch (a)
    {
    case 1:
        return music;
        break;
    
    default:
        break;
    }
}

void DestroyResource()
{
    SDL_DestroyTexture(BackgroundImage);
    SDL_DestroyTexture(kun);
    SDL_DestroyTexture(menuImage);
    SDL_DestroyTexture(hen1);

}