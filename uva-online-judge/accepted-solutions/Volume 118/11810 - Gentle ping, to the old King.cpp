#include <stdio.h>
#include <iostream>

#define INF 10000000

int n,nprm,a[20][20];
bool If_Prm[20];

int min(int a, int b)
{
    if (a<b) return a;
    return b;
}

void Khoitao()
{
    for (int i=0;i<n;i++)
    {
        If_Prm[i]=false;
        a[i][i]=0;
        for (int j=i+1;j<n;j++)
            a[i][j]=a[j][i]=INF;
    }
}

void Inp(int m)
{
    int i,u,v,c;
    
    while (nprm-->0)
    {
        scanf("%d",&i);
        If_Prm[i]=true;
    }
    
    while (m-->0)
    {
        scanf("%d %d %d",&u,&v,&c);
        a[u][v]=a[v][u]=c;
    }
}

void Floyd()
{
    for (int k=0;k<n;k++)
        for (int u=0;u<n;u++)
            for (int v=0;v<n;v++)
            {
                a[u][v]=a[v][u]=min(a[u][v],a[u][k]+a[v][k]);
            }
}

int TinhTime()
{
    int sum=0,tmp,i,j;
    for (i=0;i<n;i++)
    {
        tmp=0;
        for (j=0;j<n;j++)
            if (If_Prm[j]) tmp+=a[i][j];
        sum+=tmp;
    }
    return sum;
}

void Print()
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
            printf("%4d",a[i][j]);
        printf("\n");
    }
    printf("\n");
}

main()
{
 //   freopen("ginp.txt","r",stdin);
 //   freopen("gout.txt","w",stdout);
    
    int numcase,m,rs;
    scanf("%d",&numcase);
    for (int t=1;t<=numcase;t++)
    {
        scanf("%d %d %d",&n,&m,&nprm);
        Khoitao(); Inp(m);
        Floyd(); 
        rs=TinhTime();
        printf("Case %d: %d\n",t,rs);
 //       Print();
    }
}
