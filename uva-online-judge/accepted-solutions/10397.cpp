#include <stdio.h>
#include <math.h>
#include <iostream>

#define maxA 1000000

struct Buildings
{
    int x,y;
} bd[755];

int n,Trace[755];
double a[755][755],d[755];
bool Free[755];

void TinhD()
{
    for (int i=1;i<=n;i++)
    {
        a[i][i] = 0;
        for (int j=i+1;j<=n;j++)
        {
            double t1 = bd[i].x-bd[j].x;
            double t2 = bd[i].y-bd[j].y;
            a[i][j] = a[j][i] = sqrt( t1*t1 + t2*t2 );
        }
    }
}

void Enter()
{
    int i,m,u,v;
    for (i=1;i<=n;i++)
        scanf("%d %d",&bd[i].x,&bd[i].y);
    TinhD();
    scanf("%d",&m);
    while (m-->0)
    {
        scanf("%d %d",&u,&v);
        a[u][v] = a[v][u]=0;
    }
    
    d[1]=0;
    for (i=2;i<=n;i++) d[i]=maxA;
    memset(Free,true,n+3);
}

void Prim()
{
    int k,u,v,i;
    double min;
    for (k=1;k<=n;k++)
    {
        u=0; min=maxA;
        for (i=1;i<=n;i++)
            if (Free[i] && d[i]<min)
            {
                u=i;
                min=d[i];
            }
        Free[u]=false;
        for (v=1;v<=n;v++)
            if (Free[v] && a[u][v]<d[v])
            {
                d[v]=a[u][v];
                Trace[v]=u;
            }
    }
}

void Result()
{
    double len=0;
    for (int v=2;v<=n;v++)
    {
 //       printf("(%d, %d) = %.2f\n",Trace[v],v,a[Trace[v]][v]);
        len += a[Trace[v]][v];
    }
    printf("%.2f\n",len);
}
/*
void Print()
{
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            printf("%5.2f",a[i][j]);
        printf("\n");
    }
    printf("\n");
}
*/
main()
{
 //   freopen("397inp.txt","r",stdin);
 //   freopen("397out.txt","w",stdout);
    
    while (scanf("%d",&n)!=EOF)
    {
        Enter();
   //     Print();
        Prim();
        Result();
    }
}
