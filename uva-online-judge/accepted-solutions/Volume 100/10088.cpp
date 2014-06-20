#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long long x[1010],y[1010];
int n;

long long Gcd(long long a, long long b) {
    if (b==0) return a;
    if (a%b==0) return b;
    return Gcd(b,a%b);
}

double Result() {
    int i,j;
    double A,b;
    long long dx,dy;
    A=b=0;
    for (i=0;i<n;i++) {
        j=(i+1)%n;
        A+=(x[i]*y[j]-x[j]*y[i]);
        dx=x[j]-x[i];
        dy=y[j]-y[i];
        b+=Gcd(abs(dx),abs(dy));
    }
    A=fabs(A);
    return (A/2-b/2+1);
}

main() {
//    freopen("088.inp","r",stdin);
//    freopen("088.out","w",stdout);
    while (scanf("%d",&n)) {
        if (n==0) break;
        for (int i=0;i<n;i++)
            scanf("%lld %lld",&x[i],&y[i]);
        printf("%.0lf\n",Result());
    }
}
