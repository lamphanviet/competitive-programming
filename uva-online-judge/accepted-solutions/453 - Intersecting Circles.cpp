/*****************/
/* LAM PHAN VIET */
/* UVa: 453 - Intersecting Circles
/* Time limit: 3.000s
/********************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
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
#define sqr(x) (x * x)
#define Last(i) ( i & -i )
#define eps 1e-4
#define maxN 10000
using namespace std;

struct Point {
    double x, y;
    double dist(Point p) {
        p.x -= x; p.y -= y;
        return sqrt(p.x * p.x + p.y * p.y);
    }
    bool operator == (const Point &p) const { return (x == p.x && y == p.y); }
    bool operator < (const Point &p) const {
        if (fabs(x - p.x) < eps)
            return y < p.y;
        return x < p.x;
    }
};
Point c1, c2, p1, p2;
double r1, r2;

int solve2(double a, double b, double c, double &x1, double &x2) {
    double delta = b * b - 4 * a * c;
    if (delta + eps < 0) return -1;
    if (fabs(delta) < eps) {
        x1 = -b / (2 * a);
        return 1;
    }
    delta = sqrt(delta);
    x1 = (-b + delta) / (2 * a);
    x2 = (-b - delta) / (2 * a);
    return 2;
}

int solve() {
    if (c1 == c2) {
        if (r1 == r2 && r1 != 0) return 0;
        p1 = c1;
        return 1;
    }
    double d = c1.dist(c2);
    if (r1 + r2 == d) {
        if (r1 == 0) {
            p1 = c1;
            return 1;
        }
        else if (r2 == 0) {
            p1 = c2;
            return 1;
        }
    }
    if (r1 + r2 + eps < d) return -1;
    
    double a, b, c;
    a = 2 * (c1.x - c2.x);
    b = 2 * (c1.y - c2.y);
    c = -(c1.x * c1.x) - (c1.y * c1.y) + r1 * r1;
    c += c2.x * c2.x + c2.y * c2.y - (r2 * r2);
    if (!(fabs(a) < eps)) {
        double x, y, z;
        x = (sqr(b) / sqr(a)) + 1;
        y = 2 * ((b * c / sqr(a)) + (c1.x * b / a) - c1.y);
        z = sqr(c) / sqr(a) + (2 * c1.x * c / a) + sqr(c1.x) + sqr(c1.y) - sqr(r1);
        int res = solve2(x, y, z, p1.y, p2.y);
        if (res < 0) return -1;
        p1.x = (c + b * p1.y) / (-a);
        if (res == 1) return 1;
        p2.x = (c + b * p2.y) / (-a);
        return 2;
    }
    else {
        double x, y, z;
        x = (sqr(a) / sqr(b)) + 1;
        y = 2 * ((a * c / sqr(b)) + (c1.y * a / b) - c1.x);
        z = sqr(c) / sqr(b) + (2 * c1.y * c / b) + sqr(c1.y) + sqr(c1.x) - sqr(r1);
        int res = solve2(x, y, z, p1.x, p2.x);
        if (res < 0) return -1;
        p1.y = (c + a * p1.x) / (-b);
        if (res == 1) return 1;
        p2.y = (c + a * p2.x) / (-b);
        return 2;
    }
    return 2;
}

main() {
//    FileIn("test"); FileOut("test");
    while (scanf("%lf %lf %lf", &c1.x, &c1.y, &r1) != EOF) {
        scanf("%lf %lf %lf", &c2.x, &c2.y, &r2);
        int result = solve();
        if (result == -1) puts("NO INTERSECTION");
        else if (result == 0) puts("THE CIRCLES ARE THE SAME");
        else {
            if (result == 2 && p2 < p1) swap(p1, p2);
            printf("(%.3lf,%.3lf)", p1.x + eps, p1.y + eps);
            if (result == 2)
                printf("(%.3lf,%.3lf)", p2.x + eps, p2.y + eps);
            putchar('\n');
        }
    }
}

/* lamphanviet@gmail.com - 2011 */
