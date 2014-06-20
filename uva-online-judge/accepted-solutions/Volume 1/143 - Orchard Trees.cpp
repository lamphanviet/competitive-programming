//*****************
// LAM PHAN VIET **
// UVA 143 - Orchard Trees
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

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 5
using namespace std;

struct Point {
    double x, y;
};
Point p[maxN];
double area, x_min, x_max, y_min, y_max;

bool stop() {
    FOR (i, 1, 3)
        if (p[i].x || p[i].y) return false;
    return true;
}

double triangle_area(Point a, Point b, Point c) {
    double area = (a.x*b.y - a.y*b.x + b.x*c.y - b.y*c.x + c.x*a.y - c.y*a.x) / 2.0;
    if (area < 0) return -area;
    return area;
}

int inside_check(Point p0) {
    double area0 = triangle_area(p[1], p[2], p0);
    area0 += triangle_area(p[1], p0, p[3]);
    area0 += triangle_area(p0, p[2], p[3]);
    return (area0 <= area + 1e-7)? 1: 0;
}

int solve() {
    int res = 0;
    area = triangle_area(p[1], p[2], p[3]);
    if (x_min > (int)x_min) x_min++;
    if (y_min > (int)y_min) y_min++;
    x_min = max((int)x_min, 1); x_max = min((int)x_max, 99);
    y_min = max((int)y_min, 1); y_max = min((int)y_max, 99);
    Point p0;
    FOR (i, (int)x_min, x_max)
        FOR (j, (int)y_min, y_max) {
            p0.x = i; p0.y = j;
            res += inside_check(p0);
    }
    return res;
}

main() {
//    FileIn("test"); FileOut("test");
    Point p0;
    while (true) {
        x_min = y_min = 100;
        x_max = y_max = 0;
        FOR (i, 1, 3) {
            scanf("%lf %lf", &p[i].x, &p[i].y);
            x_min = min(x_min, p[i].x);
            x_max = max(x_max, p[i].x);
            y_min = min(y_min, p[i].y);
            y_max = max(y_max, p[i].y);
        }
        if (stop()) break;
        printf("%4d\n", solve());
    }
}

/* lamphanviet@gmail.com - 2011 */
