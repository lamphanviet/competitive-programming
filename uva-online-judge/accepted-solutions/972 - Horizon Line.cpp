/*****************/
/* LAM PHAN VIET */
/* UVa: 972 - Horizon Line
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
#define INF 500000000
#define maxN 102
using namespace std;

int n, m;
double fy[maxN], fx[maxN];
double gy[maxN], gx[maxN];

double check(double x1, double x2, double y0, double *y, double *x, int n) {
    double res = INF;
    REP(i, n)
        if (!(x2 <= x[i] || x[i + 1] <= x1))
            res = min(res, max(y[i + 1], y0));
    return res;
}

main() {
//    InpFile("test.inp"); OutFile("test.out");
    while (scanf("%d ", &n) != EOF) {
        fy[0] = fx[0] = 0;
        FOR (i, 1, n) {
            scanf("%lf %lf", &fy[i], &fx[i]);
            fx[i] += fx[i - 1];
        }
        scanf("%d", &m);
        gy[0] = gx[0] = 0;
        FOR (i, 1, m) {
            scanf("%lf %lf", &gy[i], &gx[i]);
            gx[i] += gx[i - 1];
        }
        double result = INF;
        FOR (i, 1, n)
            result = min(result, check(fx[i - 1], fx[i], fy[i], gy, gx, m));
        printf("%.3lf\n", result);
    }
}

/* lamphanviet@gmail.com - 2011 */
