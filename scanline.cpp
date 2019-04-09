#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

struct point
{
    int x,y;
    point(int x_,int y_){x=x_;y=y_;}
    point(){};
    bool operator < (point other)
    {
        return y<other.y;
    }
};

struct node
{
    int ymax;
    float x;
    float m_;
    node(){}
    node (float x_,int ymax_,float m__){x=x_;ymax=ymax_;m_=m__;}
    bool operator < (node other)
    {
        return x<other.x;
    }
};


int n;
point vertices[50];
vector <node> AET, GET[1000];

int main()
{
    cin>>n;
    for (int i=0;i<n;i++)///enter in cyclic order
    {
        cin>>vertices[i].x>>vertices[i].y;
    }

    for (int i=0;i<n;i++)
    {
        point A=vertices[i],B=vertices[(i+1)%n];
        if (A.y>B.y)swap(A,B);

        float m_=(B.x-A.x)*(1.0)/(B.y-A.y+0.000001);
        GET[A.y].push_back(node(A.x,B.y,m_));
    }
    for (int i=0;i<1000;i++)sort(GET[i].begin(),GET[i].end());

    int y=0;
    initwindow(700,700);
    while(y<700)
    {
        vector<node> temp;
        for (auto element:AET)
        {
            if (y<element.ymax)
            {
                node z=element;
                z.x+=element.m_;
                temp.push_back(z);
            }
        }
        for (auto x:GET[y])temp.push_back(x);
        sort(temp.begin(),temp.end());AET=temp;
        int parity=1;
        for (int i=0;i<((int)AET.size())-1;i++)
        {
            if (parity)
            {
                line(round(AET[i].x),y,AET[i+1].x,y);
            }
            parity^=1;
        }
        y++;
    }

    getch();
    closegraph();




}

/*
5
200 200
100 300
300 400
600 100
300 300
*/
/*
4
200 200
300 200
300 300
200 300
*/
