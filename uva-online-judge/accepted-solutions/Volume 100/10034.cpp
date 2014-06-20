//----------------------------
// LAM PHAN VIET
// UVA 10034
// Time limit: 3s
//----------------------------
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define INF 10000000
#define maxN 101
typedef struct Point {
    double x,y;
};
int n,Trace[maxN];
double a[maxN][maxN],d[maxN];
Point p[maxN];
bool Free[maxN];

double D(int i, int j) {
    double t1=p[i].x-p[j].x, t2=p[i].y-p[j].y;
    return sqrt(t1*t1+t2*t2);
}

void Distance() {
    for (int i=1;i<=n;i++) {
        a[i][i]=0.0;
        for (int j=i+1;j<=n;j++) 
            a[i][j]=a[j][i]=D(i,j);
    }
}

void Prim() {
    int i,k,u,v;
    double min;
    d[1] = 0;
    for (k=1;k<=n;k++) {
        u=0; min=INF;
        for (i=1;i<=n;i++)
            if (Free[i] && d[i]<min) {
                u=i; min=d[i];
            }
        if (u==0) break;
    
        Free[u]=false;
        for (v=1;v<=n;v++)
            if (Free[v] && d[v]>a[u][v]) {
                d[v]=a[u][v];
                Trace[v]=u;
            }
    }
}

void Result() {
    double rs=0;
    for (int v=2;v<=n;v++)
        rs += a[v][Trace[v]];
    printf("%.2lf\n",rs);
}

main() {
    int Case;
    bool Line = false;
    scanf("%d",&Case);
    while (Case--) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            scanf("%lf %lf",&p[i].x,&p[i].y);
            d[i]=INF; Free[i]=true;
        }
        Distance();
        Prim();
        
        if (Line) printf("\n");
        Line=true;
        Result();
    }
}
