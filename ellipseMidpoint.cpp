#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
void displayEllipse(int xc, int yc, int x, int y)
{
    putpixel(xc+x,yc+y,WHITE);
    putpixel(xc+x,yc-y,WHITE);
    putpixel(xc-x,yc+y,WHITE);
    putpixel(xc-x,yc-y,WHITE);
}
void myEllipse(int xc, int yc, int a, int b)
{
    int x = a;
    int y = 0;
    displayEllipse(xc,yc,x,y);
    int asq = pow(a,2);
    int bsq = pow(b,2);
    int d = asq + bsq*(.25-a);
    int dn1 = 3 * asq;
    int dnw1 = (3 * asq + 2 * bsq * (1-a));
    while(abs(x*bsq) >= abs (y*asq))
    {
        if(d<=0)
        {
            d += dn1;
            dn1 += 2*asq;
            dnw1 += 2*asq;
        }
        else
        {
            d += dnw1;
            dn1 += 2*asq;
            dnw1 += (2*asq + 2*bsq);
            x--;
        }
        y++;
        displayEllipse(xc,yc,x,y);
    }
    int d2 = bsq*(pow((x-1),2)) + asq*(pow((y+.5),2)) - asq*bsq;
    int dnw2 = bsq*(-2*x + 3) + asq*(2*y+2);
    int dw2 = bsq*(-2*x+3);
    while(x>=0)
    {
        if(d2<=0)
        {
            d2 += dnw2;
            dnw2 += 2*(asq+bsq);
            dw2 += 2*bsq;
            y++;
        }
        else
        {
            d2 += dw2;
            dnw2 += 2*bsq;
            dw2 += 2*bsq;
        }
        x--;
        displayEllipse(xc,yc,x,y);
    }
}
int main()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, NULL);
    myEllipse(100,100,90,40);
    getch();
    closegraph();
}
