#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
void midPoint(int X1, int Y1, int X2, int Y2)
{
    int dx = X2 - X1;
    int dy = Y2 - Y1;
    int d = dy - (dx/2);
    int x = X1, y = Y1;
    putpixel(x,y,WHITE);
    while (x < X2)
    {
        x++;
        if (d < 0)
            d = d + dy;
        else
        {
            d += (dy - dx);
            y++;
        }
        putpixel(x,y,WHITE);
    }
}
int main()
{
    int X1 = 20, Y1 = 20, X2 = 80, Y2 = 50;
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, NULL);
    midPoint(X1, Y1, X2, Y2);
    getch();
    closegraph();
}
