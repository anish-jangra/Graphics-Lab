#include<iostream>
#include<conio.h>
#include<graphics.h>
using namespace std;
void put_pixel(int x, int y, int col)
{
    putpixel(x+320, 240-y, col);
}
void brsnhm_line(int x1, int y1, int x2, int y2)
{
    setcolor(RED);
    line(320,0,320,480);
    setcolor(BLUE);
    line(0,240,640,240);
    setcolor(WHITE);
    int xa, ya,xb,yb;
    if(x1<x2)
    {
        xa=x1;
        ya=y1;
        xb=x2;
        yb=y2;
    }
    else
    {
        xa=x2;
        ya=y2;
        xb=x1;
        yb=y1;
    }
    int dx,dy;
    dx=xb-xa;
    dy=yb-ya;
    int d;
    float x=xa, y=ya;
    put_pixel(xa,ya,15);
    float m = 1.0*dy/dx;
    if(m>=0 && m<=1)
    {
        d=2*dy-dx;
        while(x<xb)
        {
            if(d<0)
            {
                d+=2*dy;
                x++;
            }
            else
            {
                d+=2*(dy-dx);
                x++;
                y++;
            }
            put_pixel(x,y,15);
        }
    }
    else if(m>1)
    {
        d=2*dx-dy;
        while(x<xb)
        {
            if(d<0)
            {
                d+=2*dx;
                y++;
            }
            else
            {
                d+=2*(dx-dy);
                x++;
                y++;
            }
            put_pixel(x,y,15);
        }
    }
    else if(m>=-1 && m<0)
    {
        d=-2*dy-dx;
        while(x<xb)
        {
            if(d<0)
            {
                d-=2*dy;
                x++;
            }
            else
            {
                d-=2*(dx+dy);
                y--;
                x++;
            }
            put_pixel(x,y,15);
        }
    }
    else if(m<-1)
    {
        d = -2*dx-dy;
        while(x<xb)
        {
            if(d>0)
            {
                d-= 2*dx;
                y--;
            }
            else
            {
                d-= 2*(dx+dy);
                y--;
                x++;
            }
            put_pixel(x,y,15);
        }
    }
}
int main()
{
    int x1,y1,x2,y2;
    cout<<"Enter x1,y1 : ";
    cin>>x1>>y1;
    cout<<"Enter x2,y2 : ";
    cin>>x2>>y2;
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, NULL);
    brsnhm_line(x1,y1,x2,y2);
    getch();
    closegraph();
}
