#include"player.h"



CXK * Creat_CXK(int x,int y,int w,int h)
{
    CXK *p = malloc(sizeof(CXK));
    p->imageRect.x = x;
    p->imageRect.y = y;
    p->imageRect.w = w;
    p->imageRect.h = h;

    p->rect.w = 5;
    p->rect.h = 5;
    p->rect.x = x;
    p->rect.y = y;

    return p;
}


void CXK_Update(SDL_Renderer * renderer,CXK * p,int x,int y)
{
    p->imageRect.x = p->rect.x - p->imageRect.w / 2;
    p->imageRect.y = p->rect.y - p->imageRect.h / 2;


    if(p->rect.x > x)
    {
        p->rect.x--;
    }else if(p->rect.x < x)
    {
        p->rect.x++;
    }
    if(p->rect.y > y)
    {
        p->rect.y--;
    }else if(p->rect.y < y)
    {
        p->rect.y++;
    }
    SDL_RenderCopy(renderer,chooseTexture(2),NULL,&p->imageRect);
    SDL_RenderDrawRect(renderer,&p->rect);
}
