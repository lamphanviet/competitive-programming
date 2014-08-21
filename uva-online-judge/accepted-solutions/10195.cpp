#include <stdio.h>
#include <math.h>

double a,b,c,rad,p;

main() {
    while (scanf("%lf %lf %lf",&a,&b,&c)!=EOF) {
        printf("The radius of the round table is: ");
        if (a+b<=c || a+c<=b || b+c<=a) {
            printf("0.000\n");
            continue;
        }
        p=(a+b+c)/2;
        rad=sqrt((p-a)*(p-b)*(p-c)/p);
        printf("%.3lf\n",rad);
    }
}
