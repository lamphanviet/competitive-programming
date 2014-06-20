#include <iostream>
#include <math.h>

#define MAX 1000000

using namespace std;

int x[260],y[260],n;
double area;
int x1, ya1, x2, y2;
int ax, ay, bx, by, dt;

int max(int a, int b) {
    if (a>b) return a;
    return b;
}

int min(int a, int b) {
    if (a<b) return a;
    return b;
}

void Store(int m) {
    x1=ax; ya1=ay;
    x2=bx; y2=by;
    dt = m;
}

bool Check_Cor() {
    if (ax<x1) return 1;
    else if (ax==x1) {
        if (ay<ya1) return 1;
        else if (ay==ya1) {
            if (bx<x2) return 1;
            else if (bx==x2) {
                if (by<y2) return 1;
            }
        }
    }
    return 0;
}

void SS(int m) {
    double t1,t2;
    t1 = fabs(m-area);
    t2 = fabs(dt-area);
    if (t1<t2) Store(m);
    else if (t1==t2 && Check_Cor()) Store(m);
}

bool Rec(int i, int j, int k) {
    if (x[i]==x[j]) {
        if (x[j]==x[k]) return 0;
        if (y[j]==y[k] || y[i]==y[k]) {
            ax = min(min(x[i],x[j]),x[k]);
            ay = min(min(y[i],y[j]),y[k]);
            bx = max(max(x[i],x[j]),x[k]);
            by = max(max(y[i],y[j]),y[k]);
            return 1;
        }
    }
    else if (y[i]==y[j]) {
        if (y[j]==y[k]) return 0;
        if (x[j]==x[k] || x[i]==x[k]) {
            ax = min(min(x[i],x[j]),x[k]);
            ay = min(min(y[i],y[j]),y[k]);
            bx = max(max(x[i],x[j]),x[k]);
            by = max(max(y[i],y[j]),y[k]);
            return 1;
        }
    }
    else if (x[j]==x[k] && y[i]==y[k]) {
        ax = min(min(x[i],x[j]),x[k]);
        ay = min(min(y[i],y[j]),y[k]);
        bx = max(max(x[i],x[j]),x[k]);
        by = max(max(y[i],y[j]),y[k]);
        return 1;
    }
    else if (y[j]==y[k] && x[i]==x[k]) {
        ax = min(min(x[i],x[j]),x[k]);
        ay = min(min(y[i],y[j]),y[k]);
        bx = max(max(x[i],x[j]),x[k]);
        by = max(max(y[i],y[j]),y[k]);
        return 1;
    }
    return 0;
}

void Find() {
    int i,j,k,tempar;
    dt = MAX;
    for (i=1;i<=n-2;i++)
        for (j=i+1;j<n;j++)
            for (k=j+1;k<=n;k++) {
                if (!Rec(i,j,k)) continue;
                tempar = abs(ax-bx)*abs(ay-by);
  //              printf("dt %d %d %d %d\n",i,j,k,tempar);
                SS(tempar);
            }
}

void Area_Contour() {
    area = 0;
    x[n+1]=x[1]; y[n+1]=y[1];
    for (int i=1;i<=n;i++) {
        area += x[i]*y[i+1]-x[i+1]*y[i];
    }
    area = fabs(area/2);
}

main() {
//    freopen("922.inp","r",stdin);
 //   freopen("922.out","w",stdout);
    
    int kase,i;
    cin >> kase;
    while (kase--) {
        cin >> n;
        for (i=1;i<=n;i++)
            cin >> x[i] >> y[i];
        Area_Contour();
        Find();
        printf("%.1lf %d %d %d %d\n",area,x1,ya1,x2,y2);
    }
}
