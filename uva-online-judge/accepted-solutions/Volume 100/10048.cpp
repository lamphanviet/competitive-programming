#include <stdio.h>
#include <iostream>

#define INF 1000

int n,s,f,a[205][205];

int max(int a, int b)
{
    if (a>b) return a;
    return b;
}

void Enter(int m)
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            a[i][j]=INF;
    int x,y,z;
    while (m-->0)
    {
        scanf("%d %d %d",&x,&y,&z);
        a[x][y]=a[y][x]=z;
    }
}

void F(int u)
{
    for (int v=1;v<=n;v++)
    {
        if (a[u][v]!=INF && v!=f)
        {
            if (max(a[u][v],a[u][f]) < a[v][f])
            {
                a[v][f] = a[f][v] = max(a[u][v],a[u][f]);
                if (v!=s) F(v);
            }
        }
    }
}

void Print()
{
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            printf("%7d",a[i][j]);
        printf("\n");
    }
    printf("\n\n");
}

main()
{
//    freopen("48inp.txt","r",stdin);
//    freopen("48out.txt","w",stdout);
    int m,time=0,ask,k=1;
    scanf("%d %d %d",&n,&m,&ask);
    while (n!=0 && m!=0 && ask!=0)
    {
        Enter(m);
        
        for (f=1;f<=n;f++)
            for (int u=1;u<=n;u++)
                if (a[u][f]!=INF) F(u);
        
        if (k++!=1) printf("\n");
        printf("Case #%d\n",++time);
        while (ask-->0)
        {
            scanf("%d %d",&s,&f);
            if (a[s][f]==INF) printf("no path\n");
            else printf("%d\n",a[s][f]);
  //          Print();
        }
        scanf("%d %d %d",&n,&m,&ask);
    }
}
