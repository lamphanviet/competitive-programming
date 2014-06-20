//----------------------------
// LAM PHAN VIET
// UVA 11909 - Soya Milk
// Time limit: 1s
//----------------------------
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

#define PI 2*acos(0)

double l, w, h, alpha;

main() {
    while (scanf("%lf", &l)!=EOF) {
        scanf("%lf %lf %lf", &w, &h, &alpha);
        alpha = alpha *PI/180.0;
        double c = l * tan(alpha);
        double result;
        if (c<=h)
            result = l*w*(h - c/2);
        else {
            c = h * tan(PI/2 - alpha);
            result = h*w*c/2;
        }
        printf("%.3lf mL\n", result);
    }
}
