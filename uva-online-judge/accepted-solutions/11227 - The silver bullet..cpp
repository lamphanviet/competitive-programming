/*****************/
/* LAM PHAN VIET */
/* UVa: 11227 - The silver bullet.
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
#define Last(i) ( i & -i )
#define eps 1e-7
#define maxN 101
using namespace std;

class Point {
public:
    double x, y, theta;
    Point() {}
    Point(double xx, double yy) { x = xx; y = yy; }
    void cal_theta(Point p) {
        double dx, dy, ax, ay;
        dx = p.x - x; ax = fabs(dx);
        dy = p.y - y; ay = fabs(dy);
        if (fabs(dx) < eps && fabs(dy) < eps) theta = 0;
        else theta = dy / (ax + ay);
        if (dx < 0) theta = 2 - theta;
        else theta = 4 + theta;
        theta *= 90;
        if (theta >= 180.0) theta -= 180;
    }
    bool operator < (const Point &p) const {
        if (x == p.x) return (y < p.y);
        return (x < p.x);
    }
    bool operator == (const Point &p) const {
        return (x == p.x && y == p.y);
    }
} p[maxN];
int n;

bool cmp(Point a, Point b) { return a.theta < b.theta; }

int erase_same() {
    int m = 1;
    sort(p, p + n);
    for (int i = 1; i < n; i++)
        if (!(p[i] == p[i - 1])) p[m++] = p[i];
    return m;
}

main() {
 //   FileIn("test"); FileOut("test");
    int Case;
    scanf("%d", &Case);
    FOR (test, 1, Case) {
        scanf("%d", &n);
        REP(i, n) scanf("%lf %lf", &p[i].x, &p[i].y);
        n = erase_same();
        printf("Data set #%d", test);
        if (n == 1) puts(" contains a single gnu.");
        else {
            int result = 0;
            for (int i = 0; i + 1 < n; i++) {
                for (int j = i + 1; j < n; j++)
                    p[j].cal_theta(p[i]);
                sort(p + i + 1, p + n, cmp);
                int Count = 1;
                for (int j = i + 2; j < n; j++)
                    if (fabs(p[j].theta - p[j - 1].theta) < eps)
                        Count++;
                    else {
                        result = max(result, Count);
                        Count = 1;
                    }
                result = max(result, Count);
            }
            printf(" contains %d gnus, out of which a maximum of %d are aligned.\n", n, result + 1);
        }
    }
}

/* lamphanviet@gmail.com - 2011 */
