#include <stdio.h>
#include <math.h>

double D,V,PI,d,k;

main() {
    PI=2*acos(0.0);
    k=1.0/3;
    while (scanf("%lf %lf",&D,&V)) {
        if (D==0 && V==0) break;
        double d=pow(D*D*D-6*V/PI,k);
        printf("%.3lf\n",d);
    }
}
