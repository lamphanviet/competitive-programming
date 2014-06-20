//Ngay 7/7/2010 -  Mot ngay that la buon

#include <stdio.h>
#include <math.h>

#define MaxA 10000000

struct Points {
    int x,y;
} p[505];

int s,n,Trace[505];
float a[505][505],d[505];
bool Free[505];

void TinhD() {
    int i,j;
    float t1,t2;
    for (i=1;i<=n;i++) {
        a[i][i]=0; Free[i]=true;
        d[i]=MaxA;
        for (j=i+1;j<=n;j++) {
            t1 = p[i].x-p[j].x;
            t2 = p[i].y-p[j].y;
            
            a[i][j]=a[j][i]=sqrt(t1*t1+t2*t2);
        }
    }
    d[1]=0;
}

void Enter() {
    scanf("%d %d",&s,&n);
    for (int i=1;i<=n;i++)
        scanf("%d %d",&p[i].x,&p[i].y);
    TinhD();
}

float Run()
{
    float min;
    int u,v,i,k;
    for (k=1;k<=n;k++) {
        u=0; min=MaxA;
        for (i=1;i<=n;i++)
            if (Free[i] && d[i]<min) {
                u=i;
                min=d[i];
            }
        
        Free[u]=false;
        for (v=1;v<=n;v++)
            if (Free[v] && d[v]>a[u][v]) {
                d[v]=a[u][v];
                Trace[v]=u;
            }
    }
    
    for (u=1;u<n;u++)
        for (v=u+1;v<=n;v++)
            if (d[u]>d[v]) {
                float temp=d[u];
                d[u]=d[v];
                d[v]=temp;
            }
 //   for (i=1;i<=n;i++)
 //       printf("d[%d] %.2f\n",i,d[i]);
        
    
    return d[n-s+1];
}

main() {
//    freopen("369inp.txt","r",stdin);
//    freopen("369out.txt","w",stdout);
    int time;
    scanf("%d",&time);
    while (time-->0) {
        Enter();
        printf("%.2f\n",Run());
    }
}
