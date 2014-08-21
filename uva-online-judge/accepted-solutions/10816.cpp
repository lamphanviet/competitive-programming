#include <stdio.h>
#include <iostream>

#define MaxA 10000000

struct Road
{
    float len,tem;
} a[110][110][1000];

int n,m,Trace[110],s,f,kd[110][110];
float dlen[110],dtem[110];
bool Free[110];

float max(float a, float b)
{
    if (a>b) return a;
    return b;
}

void Enter()
{
    int u,v;
    float len,tem;
    for (u=1;u<=n;u++)
    {
        dlen[u]=dtem[u]=MaxA;
        Free[u]=true;
        kd[u][u]=0;
        for (v=u+1;v<=n;v++)
        {
            kd[u][v]=kd[v][u]=0;
        }
    }
    
    scanf("%d %d",&s,&f);
    dlen[s]=dtem[s]=0;
    
    while (m-->0)
    {
        scanf("%d %d %f %f",&u,&v,&tem,&len);
        kd[u][v]=++kd[v][u];
        a[u][v][kd[u][v]].len=a[v][u][kd[u][v]].len=len;
        a[u][v][kd[u][v]].tem=a[v][u][kd[u][v]].tem=tem;
    }
}

void Dijsktra_tem()
{
    int u,v,i,h;
    float mintem;
    while (1)
    {
        u=0; mintem=MaxA;
        for (i=1;i<=n;i++)
            if (Free[i] && dtem[i]<mintem)
                {
                    u=i;
                    mintem=dtem[i];
                }
            
        if (u==0 || u==f) break;
  //      printf("u: %d\n",u);
        Free[u]=false;
        
        for (v=1;v<=n;v++)
            if (Free[v])
                for (h=1;h<=kd[u][v];h++)
                {
                    float tmp=max(dtem[u],a[u][v][h].tem);
                    if (dtem[v]>tmp) dtem[v]=tmp;
                }
    }
}

void Dijsktra_len()
{
    int u,v,i,h;
    float minlen,mintem=dtem[f];
    memset(Free,true,n+5);
    while (1)
    {
        u=0; minlen=MaxA;
        for (i=1;i<=n;i++)
            if (Free[i] &&  dlen[i]<minlen)
                {
                    u=i;
                    minlen=dlen[i];
                }
                
        if (u==0 || u==f) break;
        
        Free[u]=false;
        for (v=1;v<=n;v++)
            if (Free[v])
                for (h=1;h<=kd[u][v];h++)
                {
                    if (a[u][v][h].tem<=mintem && dlen[v]>dlen[u]+a[u][v][h].len)
                    {
                        dlen[v]=dlen[u]+a[u][v][h].len;
                        Trace[v]=u;
                    }
                }
    }
}

void Result()
{
    int tmp[110],u=f,k=0;
    
    while (u!=s)
    {
        tmp[++k]=u;
        u=Trace[u];
    }
    printf("%d",s);
    for (u=k;u>=1;u--)
        printf(" %d",tmp[u]);
    printf("\n");
    
    printf("%.1f %.1f\n",dlen[f],dtem[f]);
}

main()
{
 //   freopen("816inp.txt","r",stdin);
 //   freopen("816out.txt","w",stdout);
    while (scanf("%d %d",&n,&m)==2)
    {
        Enter();
        Dijsktra_tem();  Dijsktra_len();
 //       for (int i=1;i<=n;i++)
//            printf("dtem %f\n",dtem[i]);
        Result();
 //       Print();
    }
}
