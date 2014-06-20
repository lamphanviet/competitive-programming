/*****************/
/* LAM PHAN VIET */
/* UVA 438 - The Circumference of the Circle
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

double get_distance(Point a, Point b) {
    double x = a.x - b.x;
    double y = a.y - b.y;
    return sqrt(x * x + y * y);
}

main() {
//    FileIn("test"); FileOut("test");
    Point A, B, C;
    double a, b, c, p, S, r;
    while (scanf("%lf %lf", &A.x, &A.y) != EOF) {
        scanf("%lf %lf", &B.x, &B.y);
        scanf("%lf %lf", &C.x, &C.y);
        a = get_distance(B, C);
        b = get_distance(A, C);
        c = get_distance(A, B);
        p = (a + b + c) / 2;
        S = sqrt(p * (p-a) * (p-b) * (p-c));
        r = (a * b * c) / (4.0 * S);
        printf("%.2lf\n", 2.0 * PI * r);
    }
}

/* lamphanviet@gmail.com - 2011 */
