#include"enemy.h"

ENEMY * Creat_ENEMY(int x,int y,int w,int h)
{
    ENEMY *p = malloc(sizeof(ENEMY));
    p->imageRect.x = x;
    p->imageRect.y = y;
    p->imageRect.w = w;
    p->imageRect.h = h;

    p->rect.w = w;
    p->rect.h = h;
    p->rect.x = x;
    p->rect.y = y;
    return p;
}

void EnemyMove(SDL_Renderer * renderer,ENEMY * p)
{
    p->imageRect.x = p->rect.x - p->imageRect.w / 2;
    p->imageRect.y = p->rect.y - p->imageRect.h / 2;
    SDL_RenderCopy(renderer,chooseTexture(101),NULL,&p->imageRect);
}
