#include <graphics.h>
#include<iostream>
#include <conio.h>
using namespace std;
int polyfill(float p,float q,int c,int bo)
{
    int r;
    r=getpixel(320+p,240-q);
    if((r!=bo)&&(r!=c))
    {
        putpixel(320+p,240-q,c);
        polyfill(p,(q-1),c,bo);
        polyfill(p+1,q,c,bo);
    }
}
int plyfill(float p,float q,int c,int bo)
{
    int r;
    r=getpixel(320+p,240-(q));
    if((r!=bo)&&(r!=c))
    {
        putpixel(320+p,240-q,c);
        plyfill(p,(q+1),c,bo);
        plyfill(p+1,q,c,bo);
    }
}
int plyfil(float p,float q,int c,int bo)
{
    int r;
    r=getpixel(320+p,240-(q));
    if((r!=bo)&&(r!=c))
    {
        putpixel(320+p,240-q,c);
        plyfil(p,(q+1),c,bo);
        plyfil(p-1,q,c,bo);
    }
}
int plyfll(float p,float q,int c,int bo)
{
    int r;
    r=getpixel(320+p,240-(q));
    if((r!=bo)&&(r!=c))
    {
        putpixel(320+p,240-q,c);
        plyfll(p,(q-1),c,bo);
        plyfll(p-1,q,c,bo);
    }
}
int main()
{
    int gdriver = DETECT, gmode, errorcode;
    int i,n,c,boun;
    float x[20],y[20],a,b,l,m;
    int polyfill(float,float,int,int);
    int plyfill(float,float,int,int);
    int plyfll(float,float,int,int);
    int plyfil(float,float,int,int);
    cout<<"enter the no of vertices : ";
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"enter the coordinates : ";
        cin>>x[i]>>y[i];
    }
    cout<<"enter the color code : ";
    cin>>c;
    cout<<"enter the boundry color : ";
    cin>>boun;
    cout<<"enter an interior pt : ";
    cin>>a>>b;
    x[i]=x[0],y[i]=y[0];
    initgraph(&gdriver, &gmode, NULL);
    setcolor(boun);
    for(i=0; i<n; i++)
        line(320+x[i],240-y[i],320+x[i+1],240-y[i+1]);
    setcolor(WHITE);
    l=a,m=b+1;
    getch();
    polyfill(a,b,c,boun);
    plyfll(a-1,b,c,boun);
    plyfil(l,m,c,boun);
    plyfill(l+1,m,c,boun);
    getch();
}
