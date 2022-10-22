#include"player.h"

CXK * Creat_CXK(int x,int y,int w,int h)
{
    CXK *p = malloc(sizeof(CXK));
    p->rect.x = x;
    p->rect.y = y;
    p->rect.w = w;
    p->rect.h = h;

    return p;
}