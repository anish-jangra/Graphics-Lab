#include<iostream>
#include<graphics.h>
#include<conio.h>
using namespace std;
void displayCircle(int xc, int yc, int x, int y)
{
    putpixel(xc+x,yc+y,WHITE);
    putpixel(xc+x,yc-y,WHITE);
    putpixel(xc-x,yc+y,WHITE);
    putpixel(xc-x,yc-y,WHITE);
    putpixel(xc+y,yc+x,WHITE);
    putpixel(xc-y,yc+x,WHITE);
    putpixel(xc+y,yc-x,WHITE);
    putpixel(xc-y,yc-x,WHITE);
}
void myCircle(int xc, int yc, int R)
{
    int x = 0;
    int y = R;
    int de = 3;
    int se = 5 - 2*R;
    int d = 1-R;
    displayCircle(xc,yc,x,y);
    while(x<=y)
    {
        if(d<=0)
        {
            d += de;
            de += 2;
            se += 2;
        }
        else
        {
            d += se;
            de += 2;
            se += 4;
            y--;
        }
        x++;
        displayCircle(xc,yc,x,y);
    }
}
int main()
{
	int gd = DETECT, gm,x,y,r;
	cout<<"Enter radius of circle: ";
	cin>>r;
	cout<<"Enter co-ordinates of center(x and y): ";
	cin>>x>>y;
    initgraph(&gd, &gm, NULL);
	myCircle(x, y, r);
	getch();
	closegraph();
	return 0;
}

