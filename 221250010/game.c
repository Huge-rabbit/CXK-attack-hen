#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_mixer.h>
#include<stdio.h>

#include"player.h"
#include"resource.h"
#include"mainmenu.h"
#include"enemy.h"

#define HEIGHT 600
#define WIDTH 1000



SDL_Window * win = NULL;
SDL_Renderer * renderer = NULL;

//SDL_Texture * BackgroundImage = NULL;
//SDL_Texture * kun = NULL;

CXK * myCXK = NULL;
ENEMY * enemy1 = NULL;


int main(int argc,char *argv[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING))
    {
        SDL_Log("Can not init SDL_INIT_EVERYTHING,%s",SDL_GetError);
        return 1;
    }

    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,4096);

    win = SDL_CreateWindow("cxk",
                            SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
                            WIDTH,HEIGHT,
                            SDL_WINDOW_SHOWN);
    
    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer,255,0,0,255);

    LoadResource(renderer);


    myCXK = Creat_CXK(WIDTH / 2,HEIGHT / 2,50,61);
    enemy1 = Creat_ENEMY(400,400,120,90);

    

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
        SDL_RenderCopy(renderer,chooseTexture(1),NULL,NULL);//ªÊ÷∆±≥æ∞

        CXK_Update(renderer,myCXK,mousex,mousey);
        EnemyMove(renderer,enemy1);
        
        SDL_RenderPresent(renderer);
        SDL_Delay(20);
    }


    DestroyResource();

    Mix_CloseAudio();
    Mix_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();
    
    return 0;
}