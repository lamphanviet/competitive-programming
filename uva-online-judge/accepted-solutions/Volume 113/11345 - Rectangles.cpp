//*****************
// LAM PHAN VIET **
// UVA 11345 - Rectangles
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define INF 10000000

main() {
//    freopen("345.inp", "r", stdin); freopen("345.out", "w", stdout);
    int kk, kase, ok, ans, n;
    int x1, x2, y1, y2, sx, fx, sy, fy;
    cin >> kase;
    for (kk=1; kk<=kase; kk++) {
        scanf("%d", &n);
        sx=sy=-INF; fx=fy=INF; ok = 1;
        while (n--) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            if (ok) {
                sx = max(sx, x1); sy = max(sy, y1);
                fx = min(fx, x2); fy = min(fy, y2);
                if (sx>=fx || sy>=fy) ok=0;
            }
        }
        if (!ok) ans = 0;
        else ans = (fx-sx)*(fy-sy);
        printf("Case %d: %d\n", kk, ans);
    }
}

/* lamphanviet@gmail.com - 2011 */
