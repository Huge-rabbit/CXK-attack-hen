/*
 * @Author: Huge-rabbit 1372223484@qq.com
 * @Date: 2022-10-22 13:27:37
 * @LastEditors: Huge-rabbit 1372223484@qq.com
 * @LastEditTime: 2022-10-23 13:23:09
 * @FilePath: \PlaneWar-maind:\Teamwork\CXK-attack-hen\221250010\player.c
 * @Description: 
 * 
 * Copyright (c) 2022 by Huge-rabbit 1372223484@qq.com, All Rights Reserved. 
 */
#include"player.h"
#include<math.h>


CXK * Creat_CXK(int x,int y,int w,int h)
{
    CXK *p = malloc(sizeof(CXK));
    p->rect.x = x;
    p->rect.y = y;
    p->rect.w = w;
    p->rect.h = h;

    return p;
}


void CXK_Move(CXK * p,int x,int y)
{
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
}
