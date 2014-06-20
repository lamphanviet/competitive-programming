/*****************/
/* LAM PHAN VIET */
/* UVa: 302 - John's trip
/* Time limit: 3.000s
/********************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) ( i & -i )
using namespace std;

struct Canh
{
    int u,v;
} canh[2000];

int n,nc,s,a[50][50],cn[50];
bool FC[2000];

int min(int a, int b)
{
    if (a<b) return a;
    return b;
}

int max(int a, int b)
{
    if (a>b) return a;
    return b;
}

void Khoitao()
{
    memset(FC,true,2000);
    for (int i=1;i<=50;i++)
    {
        cn[i]=0;
        for (int j=i;j<=50;j++)
            a[i][j]=a[j][i]=0;
    }
}

void Enter(int u,int v)
{
    Khoitao();
    int z;
    scanf("%d",&z);
    cn[u]++; cn[v]++;
    a[u][v]=++a[v][u];
    canh[z].u=u; canh[z].v=v;
    
    nc++;
    scanf("%d %d",&u,&v);
    while (u!=0 && v!=0)
    {
        scanf("%d",&z);  
        cn[u]++; cn[v]++;
        a[u][v]=++a[v][u];
        canh[z].u=u; canh[z].v=v;
        
        nc++;
        n=max(n,max(u,v));
        scanf("%d %d",&u,&v);
    }
}

bool CanGoBack(int x, int y)
{
    int Queue[50],front,rear,u,v;
    bool Free[50];
    
    a[x][y]=--a[y][x];
    memset(Free,true,n+5);
    Free[y]=false;
    front=1;
    Queue[1]=y;
    do
    {
        u=Queue[front--];
        for (v=1;v<=n;v++)
            if (Free[v] && a[u][v]>0)
            {
                Queue[++front]=v;
                Free[v]=false;
                if (!Free[x])
                {
                    front=0;
                    break;
                }
            }
    } while (front>0);
    
    a[x][y]=++a[y][x];
//    printf("free %d\n",!Free[x]);
    return (!Free[x]);
}

int Euler()
{
    for (int i=1;i<=n;i++)
        if (cn[i]%2!=0)
        {
            printf("Round trip does not exist.\n");
            return 0;
        }
        
    int cr=s,next,v,count=1,i,k;
    
    do
    {
        next=0;
        for (i=1;i<=nc;i++)
            if (FC[i])
            {
                if (canh[i].u==cr && a[cr][canh[i].v]>0)
                {
                    next=canh[i].v;
                    k=i;
           //         printf("i %4d    \n",i);
                    if (CanGoBack(cr,next)) break;
                }
                else if (canh[i].v==cr && a[cr][canh[i].u]>0)
                {
                    next=canh[i].u;
                    k=i;
          //          printf("i %4d    \n",i);
                    if (CanGoBack(cr,next)) break;
                }
            }

        if (next!=0)
        {
            if (count!=1) printf(" ");
            a[cr][next]=--a[next][cr];
            printf("%d",k);
            FC[i]=false;
            count++;
            cr=next;
        }
    } while (next!=0);
    
    printf("\n");
    return 0;
}

void Print()
{
    int i,j;
    printf("Matran\n");
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
            printf("%4d",a[i][j]);
        printf("\n");
    }
    printf("Canh\n");
    for (i=1;i<=nc;i++)
        printf("%d: %4d %d\n",i,canh[i].u,canh[i].v);
    printf("\n");
}

main()
{
 //   freopen("302inp.txt","r",stdin);
 //   freopen("302out.txt","w",stdout);
    
    int u,v;
    scanf("%d %d",&u,&v);
    while (u!=0 && v!=0)
    {
        s=min(u,v); n=max(u,v); nc=0;
        Enter(u,v);
        Euler();
//        Print();
        printf("\n");
        scanf("%d %d",&u,&v);
    }
}
