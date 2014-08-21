/*****************/
/* LAM PHAN VIET */
/* UVa: 10263 - Railway
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
#define INF 500000000
#define eps 1e-7
#define maxN 10000
using namespace std;

class Point {
public:
    double x, y;
    Point() {}
    Point(double xx, double yy) { x = xx; y = yy; }
    double dist(Point p) {
        p.x -= x; p.y -= y;
        return sqrt(p.x * p.x + p.y * p.y);
    }
    bool is_on_seg(Point a, Point b) {
        return (fabs(dist(a) + dist(b) - a.dist(b)) < eps);
    }
};
class Line {
public:
    double a, b, c;
    Line() {}
    Line(Point p0, Point u, bool vec) {
        a = u.x;
        b = u.y;
        c = -(u.x * p0.x + u.y * p0.y);
    }
    Line(Point A, Point B) {
        a = A.y - B.y;
        b = B.x - A.x;
        c = A.x * B.y - A.y * B.x;
    }
    Point get_intersect(Line line) {
        double d, dx, dy;
        d = a * line.b - line.a * b;
        dx = b * line.c - line.b * c;
        dy = c * line.a - line.c * a;
        return Point(dx / d, dy / d);
    }
};
int n;
Point p[maxN];

main() {
//    FileIn("test"); FileOut("test");
    Point p0, res;
    double min_dist, dist;
    while (scanf("%lf %lf", &p0.x, &p0.y) != EOF) {
        scanf("%d", &n);
        scanf("%lf %lf", &p[0].x, &p[0].y);
        min_dist = p0.dist(p[0]);
        res = p[0];
        
        bool solve = false;
        FOR (i, 1, n) {
            scanf("%lf %lf", &p[i].x, &p[i].y);
            if (solve) continue;
            
            if (p0.is_on_seg(p[i - 1], p[i])) {
                res = p0;
                solve = true;
                continue;
            }
            
            Line line = Line(p[i - 1], p[i]);
            Point vec(p[i - 1].x - p[i].x, p[i - 1].y - p[i].y);
            Point intersect = line.get_intersect(Line(p0, vec, true));
            if (intersect.is_on_seg(p[i - 1], p[i]))
                dist = p0.dist(intersect);
            else {
                dist = p0.dist(p[i]);
                intersect = p[i];
            }
            
            if (dist < min_dist) {
                min_dist = dist;
                res = intersect;
            }
        }
        
        printf("%.4lf\n", res.x);
        printf("%.4lf\n", res.y);
    }
}

/* lamphanviet@gmail.com - 2011 */
