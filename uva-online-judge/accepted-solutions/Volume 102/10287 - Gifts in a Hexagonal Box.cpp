//*****************
// LAM PHAN VIET **
// UVA 10287 - Gifts in a Hexagonal Box
// Time limit: 3.000s
//********************************
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

const double can3 = sqrt(3);

main() {
    double r1,r2,r3,r4,a;
    while (cin >> a) {
        r1 = a*can3/2;
        r2 = a*can3/(can3+2.0);
        r3 = r1/2;
        
        double a1,b,c,delta;
        a1 = 5.0/3.0;
        b = 7.0*a/can3;
        c = -(a*a*7.0/4.0);
        delta = sqrt(b*b-4*a1*c);
        r4 = (-b+delta)/(2.0*a1);
        printf("%.10lf %.10lf %.10lf %.10lf\n",r1,r2,r3,r4);
    }
}
