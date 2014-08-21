//*****************
// LAM PHAN VIET **
// UVA 11346 - Probability
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define maxN 10000
#define esp 1e-10

main() {
    int Case;
    double area, xa, xb, y, S, ans;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%lf %lf %lf", &xb, &y, &S);
        if (xb*y<=S) ans = 0;
        else if (S!=0) {
            area = S;
            xa = S/y;
            area += S*(log(xb)-log(xa));
            ans = 100.0-area*100.0/(xb*y);
        }
        else ans = 100.0;
        printf("%.6lf%%\n", ans+esp);
    }
}

/* lamphanviet@gmail.com - 2011 */
