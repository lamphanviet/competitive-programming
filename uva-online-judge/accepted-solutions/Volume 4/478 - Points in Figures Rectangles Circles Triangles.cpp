/*****************/
/* LAM PHAN VIET */
/* UVa: 478 - Points in Figures: Rectangles, Circles, Triangles
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
#define maxN 15
using namespace std;

struct Point {
    double x, y;
    bool read() {
        if (scanf("%lf %lf", &x, &y) == EOF) return false;
        if (x == 9999.9 && y == 9999.9) return false;
        return true;
    }
    double dist(Point p) {
        p.x -= x; p.y -= y;
        return sqrt(p.x * p.x + p.y * p.y);
    }
};
double tri_area(Point a, Point b, Point c);
struct Figure {
    int type;
    double area;
    Point a, b, c;
    bool rec(Point p) {
        return (a.x < p.x && p.x < b.x && a.y < p.y && p.y < b.y);
    }
    bool cir(Point p) {
        return (p.dist(a) < b.x);
    }
    bool tri(Point p) {
        double s1 = tri_area(a, b, p), s2, s3;
        s2 = tri_area(b, c, p);
        s3 = tri_area(c, a, p);
        return (fabs(area - (s1 + s2 + s3)) < eps && s1 != 0 && s2 != 0 && s3 != 0);
    }
    bool is_contain(Point p) {
        if (type == 1) return rec(p);
        else if (type == 2) return cir(p);
        return tri(p);
    }
} f[maxN];
int n;

double tri_area(Point a, Point b, Point c) {
    double area = (a.x - b.x) * (a.y + b.y);
    area += (b.x - c.x) * (b.y + c.y);
    area += (c.x - a.x) * (c.y + a.y);
    return (area > 0) ? area : -area;
}

void read_input() {
    char ch;
    n = 0;
    while (scanf(" %c", &ch)) {
        if (ch == '*') break;
        f[++n].a.read();
        if (ch == 'r') {
            f[n].type = 1;
            f[n].b.read();
            if (f[n].a.x > f[n].b.x)
                swap(f[n].a.x, f[n].b.x);
            if (f[n].a.y > f[n].b.y)
                swap(f[n].a.y, f[n].b.y);
        }
        else if (ch == 'c') {
            f[n].type = 2;
            scanf("%lf", &f[n].b.x);
        }
        else {
            f[n].type = 3;
            f[n].b.read();
            f[n].c.read();
            f[n].area = tri_area(f[n].a, f[n].b, f[n].c);
        }
    }
}

main() {
//    InpFile("test.inp"); OutFile("test.out");
    read_input();
    Point p0;
    int points_number = 0;
    while (p0.read()) {
        ++points_number;
        bool found = false;
        FOR (i, 1, n)
            if (f[i].is_contain(p0)) {
                printf("Point %d is contained in figure %d\n", points_number, i);
                found = true;
            }
        if (!found) printf("Point %d is not contained in any figure\n", points_number);
    }
}

/* lamphanviet@gmail.com - 2011 */
