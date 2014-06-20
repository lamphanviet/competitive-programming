/*****************/
/* LAM PHAN VIET */
/* UVa: 920 - Sunny Mountains
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
#define maxN 105
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
    bool operator < (const Point &p) const {
        if (x == p.x) return (y < p.y);
        return (x < p.x);
    }
} p[maxN];;
class Line {
public:
    double a, b, c;
    Line() {}
    Line(Point A, Point B) {
        a = A.y - B.y;
        b = B.x - A.x;
        c = A.x * B.y - B.x * A.y;
    }
    double get_x0(double y0) {
        return (b * y0 + c) / (-a);
    }
};

main() {
//    FileIn("test"); FileOut("test");
    int Case, n;
    for (scanf("%d", &Case); Case--; ) {
        scanf("%d", &n);
        REP(i, n) scanf("%lf %lf", &p[i].x, &p[i].y);
        sort(p, p + n);
        double result = 0;
        double x0 = 0, y0 = 0;
        for (int i = n - 2; i >= 0; i--)
            if (p[i].y > y0) {
                x0 = Line(p[i], p[i + 1]).get_x0(y0);
                result += p[i].dist(Point(x0, y0));
                y0 = p[i].y;
            }
        printf("%.2lf\n", result);
    }
}

/* lamphanviet@gmail.com - 2011 */
