//*****************
// LAM PHAN VIET **
// UVA 412 - Pi
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
#define Last(i) (i & -i)
#define INF 500000000
#define maxN 55
using namespace std;

int n, a[maxN];

int GCD(int m, int n) {
    int r = m%n;
    while (r) {
        m = n; n = r;
        r = m%n;
    }
    return n;
}

main() {
//    FileIn("test"); FileOut("test");
    while (scanf("%d", &n) && n) {
        int Count = 0;
        REP (i, n) {
            scanf("%d", &a[i]);
            REP (j, i)
                if (GCD(a[i], a[j])==1) Count++;
        }
        n = n*(n-1) / 2;
        if (Count) printf("%.6lf\n", (double)sqrt(6.0*n / (double)Count));
        else puts("No estimate for this data set.");
    }
}

/* lamphanviet@gmail.com - 2011 */
