/*****************/
/* LAM PHAN VIET */
/* UVa: 313 - Intervals
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
#include <set>
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
#define eps 1e-10
#define sqr(x) (x * x)
#define INF 500000000
#define maxN 100
using namespace std;

struct Point {
    double x, y;
    Point() {}
    Point(double xx, double yy) { x = xx; y = yy; }
    double dist(Point p) {
        p.x -= x; p.y -= y;
        return sqrt(p.x * p.x + p.y * p.y);
    }
    bool operator < (const Point &p) const {
        if (x == p.x) return y < p.y;
        return x < p.x;
    }
};
struct Line {
    double a, b, c;
    Line() {}
    Line(Point A, Point B) {
        a = A.y - B.y;
        b = B.x - A.x;
        c = A.x * B.y - B.x * A.y;
    }
    double get_x(double y) { return (b * y + c) / (-a); }
};
double r1, r2;
vector<Point> seg;

void solve2(double a, double b, double c, double &x1, double &x2) {
    double delta = sqrt(sqr(b) - 4 * a * c);
    x1 = (-b + delta) / (2 * a);
    x2 = (-b - delta) / (2 * a);
}

int find_intersection(Point p, Point c1, Point c2) {
    double a, b, c;
    a = 2 * (c1.x - c2.x);
    b = 2 * (c1.y - c2.y);
    c = -(c1.x * c1.x) - (c1.y * c1.y) + r1 * r1;
    c += c2.x * c2.x + c2.y * c2.y - (r2 * r2);
    
    double x, y, z;
    x = (sqr(a) / sqr(b)) + 1;
    y = 2 * ((a * c / sqr(b)) + (c1.y * a / b) - c1.x);
    z = sqr(c) / sqr(b) + (2 * c1.y * c / b) + sqr(c1.y) + sqr(c1.x) - sqr(r1);
    Point p1, p2;
    solve2(x, y, z, p1.x, p2.x);
    p1.y = (c + a * p1.x) / (-b);
    p2.y = (c + a * p2.x) / (-b);
    
    Point new_seg;
    Line line = Line(p, p1);
    new_seg.x = line.get_x(0);
    line = Line(p, p2);
    new_seg.y = line.get_x(0);
    if (new_seg.x > new_seg.y)
        swap(new_seg.x, new_seg.y);
    seg.pb(new_seg);
}

void result() {
    sort(all(seg));
    int m = 1;
    for (int i = 1; i < seg.size(); i++)
        if (seg[i].x > seg[m - 1].y)
            seg[m++] = seg[i];
        else
            seg[m - 1].y = max(seg[m - 1].y, seg[i].y);
    
    REP(i, m)
        printf("%.2lf %.2lf\n", seg[i].x - eps, seg[i].y - eps);
    putchar('\n');
}

main() {
 //   InpFile("test.inp"); OutFile("test.out");
    int n;
    Point p, c;
    while (scanf("%d", &n) && n) {
        seg.clear();
        scanf("%lf %lf", &p.x, &p.y);
        while (n--) {
            scanf("%lf %lf %lf", &c.x, &c.y, &r1);
            r2 = c.dist(p) / 2.0;
            find_intersection(p, c, Point((p.x + c.x) / 2.0, (p.y + c.y) / 2.0));
        }
        result();
    }
}

/* lamphanviet@gmail.com - 2011 */
