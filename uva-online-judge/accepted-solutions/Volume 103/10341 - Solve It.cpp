// 10341 - Solve It
#include <iostream>
#include <math.h>
#define EPS 1e-7

using namespace std;

double p, q, r, s, t, u;

double f(double x) {
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double ans() {
    double lo = 0, hi = 1, x;
    while (lo+EPS<hi) {
        x = (lo+hi)/2;
        if (f(x)*f(lo)>0) lo = x;
        else hi = x;
    }
    return (lo+hi)/2.0;
}

main() {
    while (scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u)!=EOF) {
        if (f(0)*f(1)>0) printf("No solution\n");
        else printf("%.4lf\n", ans());
    }
}
