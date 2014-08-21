// 10065 - Useless Tile Packers
#include <iostream>
#include <math.h>

using namespace std;

struct Point {
    int x, y;
} p[105];

double Theta(Point a, Point b) {
    int dx, dy, ax, ay;
    dx = b.x - a.x;   ax = abs(dx);
    dy = b.y - a.y;   ay = abs(dy);
    double t;
    if (dx==0 && dy==0) t = 0;
    else t = (double)dy/(ax + ay);
    if (dx<0) t = 2-t;
    else if (dy<0) t += 4;
    return t*90.0;
}

double Area(Point p[], int n) {
    p[n+1] = p[1];
    double area = 0;
    for (int i=1; i<=n; i++)
        area += p[i].x*p[i+1].y - p[i+1].x*p[i].y;
    return fabs(area/2.0);
}

main() {
//    freopen("065.inp", "r", stdin); freopen("065.out", "w", stdout);
    int n, m, i, u, kase=0;
    while (cin >> n && n) {
        for (i=1; i<=n; i++)
            scanf("%d %d", &p[i].x, &p[i].y);
        double area1 = Area(p, n);
        
        double minangle, v; Point t;
        for (i=1, u=1; i<=n; i++)
            if (p[i].y < p[u].y || (p[i].y==p[u].y && p[i].x>p[u].x)) u = i;
        p[n+1] = p[u]; m = 0; minangle = 0;
        do {
            m++;
            t = p[m]; p[m] = p[u]; p[u] = t;
            v = minangle; minangle = 360.0; u = n+1;
            for (i=m+1; i<=n+1; i++) {
                double tempa = Theta(p[m], p[i]);
                if (tempa<minangle && tempa>v) {
                    u = i; minangle = tempa;
                }
            }
        } while (u!=n+1);
        double area2 = Area(p, m);
        printf("Tile #%d\n", ++kase);
        printf("Wasted Space = %.2lf %%\n\n", (area2-area1)*100.0/area2);
    }
}
