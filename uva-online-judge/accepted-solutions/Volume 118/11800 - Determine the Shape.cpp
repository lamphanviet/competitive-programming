//----------------------------
// LAM PHAN VIET
// UVA 11800 - Determine the Shape
// Time limit: 1s
//----------------------------
#include <stdio.h>
#include <iostream>
#include <math.h>

struct Point
{
    int x,y;
} p[5];

int a,b,c,d;
long c1,c2,c3,c4,cheo1,cheo2;

void Inp()
{
    for (int i=1;i<=4;i++)
        scanf("%d %d",&p[i].x,&p[i].y);
}

bool Check_songsong(int d1, int c1, int d2, int c2)
{
    float  v1x,v1y,v2x,v2y;
    v1x = p[d1].x-p[c1].x;
    v1y = p[d1].y-p[c1].y;
    
    v2x = p[d2].x-p[c2].x;
    v2y = p[d2].y-p[c2].y;
    
    if ((-(v1x*v2y) + (v1y*v2x)) == 0) return true;
    
    return false;
}

void Xep()
{
    long tmp1,tmp2,tmpx,tmpy;
    tmp1 = -(p[b].y-p[a].y);
    tmp2 = p[b].x-p[a].x;
    
    tmpx = (p[c].x-p[a].x)*tmp1 + (p[c].y-p[a].y)*tmp2;
    tmpy = (p[d].x-p[a].x)*tmp1 + (p[d].y-p[a].y)*tmp2;
    
    if ((tmpx>0 && tmpy<0) || (tmpx<0 && tmpy>0)) { a=1; b=3; c=2; d=4; }
    else
    {
        tmp1 = -(p[d].y-p[a].y);
        tmp2 = p[d].x-p[a].x;
    
        tmpx = (p[b].x-p[a].x)*tmp1 + (p[b].y-p[a].y)*tmp2;
        tmpy = (p[c].x-p[a].x)*tmp1 + (p[c].y-p[a].y)*tmp2;
    
        if ((tmpx>0 && tmpy<0) || (tmpx<0 && tmpy>0))
        {
            tmp1=c;
            c=d;
            d=tmp1;
        }
    }
}

void TinhKC()
{
    c1 = (long)(pow(p[a].x-p[b].x,2)+pow(p[a].y-p[b].y,2));
    c2 = (long)(pow(p[b].x-p[c].x,2)+pow(p[b].y-p[c].y,2));
    c3 = (long)(pow(p[c].x-p[d].x,2)+pow(p[c].y-p[d].y,2));
    c4 = (long)(pow(p[d].x-p[a].x,2)+pow(p[d].y-p[a].y,2));
    cheo1 = (long)(pow(p[a].x-p[c].x,2)+pow(p[a].y-p[c].y,2));
    cheo2 = (long)(pow(p[b].x-p[d].x,2)+pow(p[b].y-p[d].y,2));
}

int Run()
{
    a=1; b=2; c=3; d=4;
    Xep();
    TinhKC();
    
    if (c1==c3 && c2==c4)
    {
        if (c1==c2)
        {
            if (cheo1==cheo2) return 1;
            else return 3;
        }
        else
        {
            if (cheo1==cheo2) return 2;
            else return 4;
        }
    }
    else if (Check_songsong(a,b,c,d) || Check_songsong(b,c,d,a)) return 5;

    return 6;
}

main()
{
 //   freopen("ginp.txt","r",stdin);
//    freopen("gout.txt","w",stdout);
    
    int numcase,k;
    scanf("%d",&numcase);
    for (int t=1;t<=numcase;t++)
    {
        Inp();
        k=Run();
        printf("Case %d: ",t);
        switch (k)
        {
            case 1: printf("Square\n"); break;
            case 2: printf("Rectangle\n"); break;
            case 3: printf("Rhombus\n"); break;
            case 4: printf("Parallelogram\n"); break;
            case 5: printf("Trapezium\n"); break;
            case 6: printf("Ordinary Quadrilateral\n"); break;
        }
 //       printf("abcd %d %d %d %d\n",a,b,c,d);
//        printf("canh %d %d %d %d\n",c1,c2,c3,c4);
 //       printf("cheo %d %d\n\n",cheo1,cheo2);
    }
}
