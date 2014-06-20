#include <stdio.h>
#include <math.h>

double a, b, c, S, V, R;
const double MyPi = 2 * acos(0);

int main () {
    while(scanf("%lf%lf%lf",&a, &b, &c) == 3){
        double p = (a + b + c) / 2.0;
        double Area = sqrt(p * (p - a) * (p - b) * (p - c));
        double r = Area / p;
        R = r * r * MyPi;
        V = Area - R;
        double RR = a * b * c / (4.0 * Area);
        double Area2 = RR * RR * MyPi;
        S = Area2 - Area;
        printf("%.4lf %.4lf %.4lf\n", S, V, R);
        }
    return 0;
    }
