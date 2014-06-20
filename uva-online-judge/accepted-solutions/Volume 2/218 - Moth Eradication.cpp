/*****************/
/* LAM PHAN VIET */
/* UVa: 218 - Moth Eradication
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
#define INF 500000000
#define maxN 10000
using namespace std;

struct Point {
    double x, y;
    bool operator < (const Point &p) const {
        return (y < p.y || (y == p.y && x > p.x));
    }
    double dist(Point p) {
        p.x -= x; p.y -= y;
        return (p.x * p.x + p.y * p.y);
    }
} p[maxN];
int n;

int ccw(Point p1, Point p2, Point p3) {
    double a1, b1, a2, b2, t;
    a1 = p2.x - p1.x;
    b1 = p2.y - p1.y;
    a2 = p3.x - p2.x;
    b2 = p3.y - p2.y;
    t = a1 * b2 - a2 * b1;
    if (fabs(t) < eps) return 0;
    return (t > 0) ? -1 : 1;
}

bool cmp(Point p1, Point p2) {
    double a1, b1, a2, b2, t;
    a1 = p1.x - p[0].x;
    b1 = p1.y - p[0].y;
    a2 = p2.x - p[0].x;
    b2 = p2.y - p[0].y;
    t = a1 * b2 - a2 * b1;
    if (fabs(t) >= eps) return t > 0;
    return (p[0].dist(p1) < p[0].dist(p2));
}

void graham_scan() {
    if (n <= 2) return;
    sort(p + 1, p + n, cmp);
    int m = n - 1;
    while (m > 0 && ccw(p[0], p[m], p[m - 1]) == 0) m--;
    if (m) reverse(p + m, p + n);
    
    m = 2;
    for (int i = 2; i < n; i++) {
        while (m >= 2) {
            int turn = ccw(p[m - 2], p[m - 1], p[i]);
            if (turn <= 0) break;
            m--;
        }
        p[m++] = p[i];
    }
    n = m;
}

main() {
//    FileIn("test"); FileOut("test");
    int Case = 0;
    while (scanf("%d", &n) && n) {
        int u = 0;
        REP(i, n) {
            scanf("%lf %lf", &p[i].x, &p[i].y);
            if (p[i] < p[u]) u = i;
        }
        swap(p[u], p[0]);
        graham_scan();
        double perimeter = 0;
        if (Case) putchar('\n');
        printf("Region #%d:\n", ++Case);
        printf("(%.1lf,%.1lf)", p[0].x, p[0].y);
        for (int i = n - 1; i >= 0; i--) {
            printf("-(%.1lf,%.1lf)", p[i].x, p[i].y);
            perimeter += sqrt(p[i].dist(p[(i + 1) % n]));
        }
        printf("\nPerimeter length = %.2lf\n", perimeter);
    }
}

/* lamphanviet@gmail.com - 2011 */
