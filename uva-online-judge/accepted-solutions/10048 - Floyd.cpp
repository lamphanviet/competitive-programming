#include <stdio.h>
#include <iostream>

#define INF 1000

int n,s,f,a[205][205];

int max(int a, int b)
{
    if (a>b) return a;
    return b;
}

int min(int a, int b)
{
    if (a<b) return a;
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

void Floyd()
{
    for (int k=1;k<=n;k++)
        for (int u=1;u<=n;u++)
            for (int v=1;v<=n;v++)
                a[u][v] = a[v][u] = min(a[u][v],max(a[u][k],a[v][k]));
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
 //   freopen("48inp.txt","r",stdin);
 //   freopen("48out.txt","w",stdout);
    int m,time=0,ask,k=1;
    scanf("%d %d %d",&n,&m,&ask);
    while (n!=0 && m!=0 && ask!=0)
    {
        Enter(m);
        
        Floyd();
        
        if (k++!=1) printf("\n");
        printf("Case #%d\n",++time);
        while (ask-->0)
        {
            scanf("%d %d",&s,&f);
            if (a[s][f]==INF) printf("no path\n");
            else printf("%d\n",a[s][f]);
//            Print();
        }
        scanf("%d %d %d",&n,&m,&ask);
    }
}
