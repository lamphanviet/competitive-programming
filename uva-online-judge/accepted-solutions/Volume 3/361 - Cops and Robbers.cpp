/*****************/
/* LAM PHAN VIET */
/* UVa: 361 - Cops and Robbers
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

#define InpFile(f) freopen(f, "r", stdin)
#define OutFile(f) freopen(f, "w", stdout)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORR(i, a, b) for (int i = a; i < b; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) ( i & -i )
#define eps 1e-5
#define INF 500000000
#define maxN 202
using namespace std;

struct Point {
    int x, y;
    Point() {}
    Point(int xx, int yy) { x = xx; y = yy; }
    double dist(Point p) {
        p.x -= x; p.y -= y;
        return sqrt(p.x * p.x + p.y * p.y);
    }
    bool is_on_seg(Point A, Point B) {
        return (fabs(dist(A) + dist(B) - A.dist(B)) < eps);
    }
    bool operator < (const Point &p) const {
        if (y == p.y) return (x > p.x);
        return (y < p.y);
    }
};
int n, m;
Point p1[maxN], p2[maxN];
bool cmp_points, out1, out2;

int ccw(Point p1, Point p2, Point p3) {
    int a1, b1, a2, b2, t;
    a1 = p2.x - p1.x;
    b1 = p2.y - p1.y;
    a2 = p3.x - p2.x;
    b2 = p3.y - p2.y;
    t = a1 * b2 - a2 * b1;
    if (t == 0) return 0;
    return (t > 0) ? -1 : 1;
}

bool lower(Point a, Point b) {
    Point p0;
    if (cmp_points) p0 = p1[0];
    else p0 = p2[0];
    int a1, b1, a2, b2;
    a1 = a.x - p0.x;
    b1 = a.y - p0.y;
    a2 = b.x - p0.x;
    b2 = b.y - p0.y;
    return (a1 * b2 > a2 * b1);
}

int graham_scan(Point *p, int n) {
    if (n <= 2) return n;
    // sort points
    int u = 0;
    REP(i, n)
        if (p[i] < p[u]) u = i;
    swap(p[0], p[u]);
    sort(p + 1, p + n, lower);
    
    // graham_scan
    int m = 2;
    FORR(i, 2, n) {
        bool chosen = true;
        while (m >= 2) {
            int turn = ccw(p[m - 2], p[m - 1], p[i]);
            if (turn < 0) break;
            if (turn == 0) {
                if (p[m - 2].dist(p[m - 1]) < p[m - 2].dist(p[i]))
                    p[m - 1] = p[i];
                chosen = false;
                break;
            }
            m--;
        }
        if (chosen) p[m++] = p[i];
    }
    return m;
}

int tri_area(Point a, Point b, Point c) {
    int area = (a.x - b.x) * (a.y + b.y);
    area += (b.x - c.x) * (b.y + c.y);
    area += (c.x - a.x) * (c.y + a.y);
    return (area > 0) ? area : -area;
}

bool is_inside(Point p0, Point *p, int n) {
    if (cmp_points && out1) return false;
    if (!cmp_points && out2) return false;
    int L = 1, R = n - 1;
    while (L < R) {
        int mid = (L + R) >> 1;
        int turn = ccw(p[0], p[mid], p0);
        if (turn == 0)
            return p0.is_on_seg(p[0], p[mid]);
        if (turn > 0) R = mid;
        else L = mid + 1;
    }
    int total_area = tri_area(p[0], p[R - 1], p[R]);
    if (total_area == 0)
        return (p0.is_on_seg(p[0], p[R - 1]) || p0.is_on_seg(p[R - 1], p[R]) || p0.is_on_seg(p[R], p[0]));
    int sum_area = tri_area(p[R], p[R - 1], p0);
    sum_area += tri_area(p[R - 1], p[0], p0);
    sum_area += tri_area(p[0], p[R], p0);
    return total_area == sum_area;
}

int check(Point p0) {
    cmp_points = true;
    if (is_inside(p0, p1, n)) return 1;
    cmp_points = false;
    if (is_inside(p0, p2, m)) return 2;
    return 3;
}

main() {
//    InpFile("test.inp"); OutFile("test.out");
    int Case = 0, k;
    Point p0;
    while (scanf("%d %d %d", &n, &m, &k) != EOF) {
        if (!n && !m && !k) break;
        REP(i, n) scanf("%d %d", &p1[i].x, &p1[i].y);
        REP(i, m) scanf("%d %d", &p2[i].x, &p2[i].y);
        cmp_points = true;
        out1 = (n <= 2);
        n = graham_scan(p1, n);
        out2 = (m <= 2);
        cmp_points = false;
        m = graham_scan(p2, m);
        printf("Data set %d:\n", ++Case);
        while (k--) {
            scanf("%d %d", &p0.x, &p0.y);
            printf("     Citizen at (%d,%d) is ", p0.x, p0.y);
            int res = check(p0);
            if (res == 1) puts("safe.");
            else if (res == 2) puts("robbed.");
            else puts("neither.");
        }
        putchar('\n');
    }
}

/* lamphanviet@gmail.com - 2011 */
