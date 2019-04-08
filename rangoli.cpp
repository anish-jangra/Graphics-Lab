#include <graphics.h>
#include <algorithm>
#include <bits/stdc++.h>
#include"circle.h"
using namespace std;
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int radius=100;
    myCircle(300,300,100);
    int F=50,S=87;
    pair <int,int> Cen[10]={
        {300+F,300+S},{300-F,300+S},
        {200,300},{300-F,300-S},{300+F,300-S},{400,300}
    };
    for (int i=0;i<6;i++)putpixel(Cen[i].first,Cen[i].second,WHITE);

    arc(Cen[0].first,Cen[0].second,60,180,radius);
    arc(Cen[1].first,Cen[1].second,0,120,radius);
    arc(Cen[2].first,Cen[2].second,300,60,radius);
    arc(Cen[3].first,Cen[3].second,240,360,radius);
    arc(Cen[4].first,Cen[4].second,180,300,radius);
    arc(Cen[5].first,Cen[5].second,120,240,radius);
    getch();
    closegraph();
    return 0;
}
