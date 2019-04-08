#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
const int LEFT = 0;
const int BOTTOM = 2;
const int RIGHT = 4;
const int TOP = 8;
const int xw_min = 100;
const int yw_min = 10;
const int xw_max = 260;
const int yw_max = 90;
int genCode(double x, double y)
{
    int code = 0;
    if(x<xw_min){
        code = code|LEFT;
    }
    if(y<yw_min){
        code = code|BOTTOM;
    }
    if(x>xw_max){
        code = code|RIGHT;
    }
    if(y>yw_max){
        code = code|TOP;
    }
    return code;
}
void drawRectangle()
{
    line(xw_min,yw_min,xw_max,yw_min);
    line(xw_max,yw_min,xw_max,yw_max);
    line(xw_max,yw_max,xw_min,yw_max);
    line(xw_min,yw_max,xw_min,yw_min);
}
void clipLine(int x1,int y1, int x2, int y2)
{
    int code1 = genCode(x1,y1);
    int code2 = genCode(x2,y2);
    bool accept = false;

    while (true)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            break;
        }
        else
        {
            int code_out;
            double x, y;
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;
            if (code_out & TOP)
            {
                x = x1 + (x2 - x1) * (yw_max - y1) / (y2 - y1);
                y = yw_max;
            }
            else if (code_out & BOTTOM)
            {
                x = x1 + (x2 - x1) * (yw_min - y1) / (y2 - y1);
                y = yw_min;
            }
            else if (code_out & RIGHT)
            {
                y = y1 + (y2 - y1) * (xw_max - x1) / (x2 - x1);
                x = xw_max;
            }
            else if (code_out & LEFT)
            {
                y = y1 + (y2 - y1) * (xw_min - x1) / (x2 - x1);
                x = xw_min;
            }
            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = genCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = genCode(x2, y2);
            }
        }
    }
    if (accept){
        line(x1,y1,x2,y2);
    }
}
int main()
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm,NULL);
    drawRectangle();
    int x1 = 200,y1=5,x2=300,y2=70;
    clipLine(x1,y1,x2,y2);
    getch();
    closegraph();
}
