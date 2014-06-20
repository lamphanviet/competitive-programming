/*****************/
/* LAM PHAN VIET */
/* UVA 477 - Points in Figures: Rectangles and Circles
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
#define maxN 10000
using namespace std;

struct Point {
    double x, y;
};
Point a[maxN], b[maxN];
bool type[maxN];

bool isRec(Point a, Point b, Point c) {
    return ((a.x < c.x && c.x < b.x) && (a.y < c.y && c.y < b.y));
}

bool isCir(Point a, Point b, double r) {
    double x = a.x - b.x, y = a.y - b.y;
    double d = sqrt(x * x + y * y);
    return (d < r);
}

main() {
//    FileIn("test"); FileOut("test");
    char q;
    int n = 0;
    double x1, y1, x2, y2;
    while (scanf("%c", &q) != EOF) {
        if (q == '*') break;
        n++;
        if (q == 'r') {
            scanf("%lf %lf %lf %lf ", &x1, &y1, &x2, &y2);
            a[n].x = min(x1, x2);
            a[n].y = min(y1, y2);
            b[n].x = max(x1, x2);
            b[n].y = max(y1, y2);
            type[n] = true;
        }
        else {
            scanf("%lf %lf %lf ", &a[n].x, &a[n].y, &b[n].x);
            type[n] = false;
        }
    }
    Point p;
    int Case = 1;
    while (scanf("%lf %lf", &p.x, &p.y) != EOF) {
        if (p.x == 9999.9 && p.y == 9999.9) break;
        int count_inside = 0;
        FOR (i, 1, n)
            if ((type[i] && isRec(a[i], b[i], p)) || (!type[i] && isCir(a[i], p, b[i].x))) {
                count_inside++;
                printf("Point %d is contained in figure %d\n", Case, i);
            }
        if (!count_inside)
            printf("Point %d is not contained in any figure\n", Case);
        Case++;
    }
}

/* lamphanviet@gmail.com - 2011 */
