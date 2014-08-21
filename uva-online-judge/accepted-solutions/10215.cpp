#include <stdio.h>
#include <math.h>

double a,b;

double min(double x, double y) {
    if (x<y) return x;
    else return y;
}

double TT(double x) {
    return (a-2*x)*(b-2*x)*x;
}

main() {
    double x1,x2,delta;
    while (scanf("%lf %lf",&a,&b)!=EOF) {
        delta = 4*(a+b)*(a+b)-12*a*b;
        delta = sqrt(delta);
        x1 = (2*(a+b)-delta)/12;
        x2 = (2*(a+b)+delta)/12;
        
        if (TT(x1)>TT(x2)) printf("%.3lf",x1+1e-7);
        else printf("%.3lf",x2+1e-7);
        
        printf(" 0.000 %.3lf\n",min(a/2,b/2)+1e-7);
    }
}
