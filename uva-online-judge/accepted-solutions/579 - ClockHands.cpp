//*****************
// LAM PHAN VIET **
// UVA 579 - ClockHands
// Time limit: 3.000s
//********************************
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
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

main() {
//    FileIn("test"); FileOut("test");
    int h, m;
    double h_angle, m_angle;
    while (scanf("%d:%d", &h, &m)!=EOF) {
        if (!h && !m) break;
        h_angle = 30 * h + m / 2.0;
        m_angle = m * 6;
        double res = h_angle - m_angle;
        if (res < 0) res = - res;
        if (res > 180) res = 360.0 - res;
        printf("%.3lf\n", res);
    }
}

/* lamphanviet@gmail.com - 2011 */
