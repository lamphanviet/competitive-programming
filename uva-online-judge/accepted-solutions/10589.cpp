#include <stdio.h>
#include <math.h>

int a;

double Dis(double x1, double y1, double x2, double y2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

bool Check(double x, double y) {
    if (Dis(x,y,0,0)>a) return 0;
    if (Dis(x,y,0,a)>a) return 0;
    if (Dis(x,y,a,0)>a) return 0;
    if (Dis(x,y,a,a)>a) return 0;
    return 1;
}

main() {
    int n;
    double x,y;
    while (scanf("%d %d",&n,&a)) {
        if (n==0) break;
        int count=0;
        for (int i=1;i<=n;i++) {
            scanf("%lf %lf",&x,&y);
            if (Check(x,y)) count++;
        }
        double rs = (double)count*a*a/n;
        printf("%.5lf\n",rs);
    }
}
