#include <stdio.h>
#include <iostream>

struct Edges
{
    unsigned long w;
    int u,v;
} a[25010];

int n,m,Lab[1010],Nlab[1010];
bool Free[1010];

int GetRoot(int v)
{
    while (Lab[v]>0) v=Lab[v];
    return v;
}

void Union(int r1, int r2)
{
    if (Nlab[r1]<=Nlab[r2])
    {
        Lab[r1]=r2;
        Nlab[r2]+=Nlab[r1];
    }
    else
    {
        Lab[r2]=r1;
        Nlab[r1]+=Nlab[r2];
    }
}

void Enter()
{
    for (int i=1;i<=m;i++)
        scanf("%d %d %ld",&a[i].u,&a[i].v,&a[i].w);
    memset(Free,true,n+5);
    for (int i=0;i<n;i++)
    {
        Lab[i]=-(i+1);
        Nlab[i]=1;
    }
}

void Sort_Weight()
{
    Edges temp;
    for (int i=1;i<m;i++)
        for (int j=i+1;j<=m;j++)
            if (a[i].w>a[j].w)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
}

int Run()
{
    int i,j,count=0,r1,r2;
    unsigned long rs[m+5];
    for (i=1;i<=m;i++)
    {
        r1=GetRoot(a[i].u); r2=GetRoot(a[i].v);
        if (r1!=r2) Union(r1,r2);
        else rs[++count]=a[i].w;
    }
    
    if (count==0)
    {
        printf("forest\n");
        return 0;
    }
    
    for (i=1;i<count;i++)
        for (j=i+1;j<=count;j++)
            if (rs[i]>rs[j])
            {
                unsigned long temp=rs[i];
                rs[i]=rs[j];
                rs[j]=temp;
            }
    printf("%ld",rs[1]);
    for (i=2;i<=count;i++)
        printf(" %ld",rs[i]);
    printf("\n");
    return 0;
}

main()
{
//    freopen("747inp.txt","r",stdin);
//    freopen("747out.txt","w",stdout);
    
    scanf("%d %d",&n,&m);
    while (n!=0 && m!=0)
    {
        Enter();
        Sort_Weight();
        Run();
        scanf("%d %d",&n,&m);
    }
}
