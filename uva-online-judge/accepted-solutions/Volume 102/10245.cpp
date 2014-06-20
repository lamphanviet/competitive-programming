#include <stdio.h>
#include <math.h>

double x[10010],y[10010];
int n;

void Enter() {
    for (int i=1;i<=n;i++)
        scanf("%lf %lf",&x[i],&y[i]);
}

double Run() {
    int i,j;
    double distance,mindis=1000000000;
    for (i=1;i<n;i++)
        for (j=i+1;j<=n;j++) {
            distance=(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]);
            if (distance<mindis) mindis=distance;
        }
    return mindis;
}

main() {
    while (scanf("%d",&n)) {
        if (n==0) break;
        Enter();
        double rs=Run();
        rs=sqrt(rs);
        if (rs>=10000) printf("INFINITY\n");
        else printf("%.4lf\n",rs);
    }
}
