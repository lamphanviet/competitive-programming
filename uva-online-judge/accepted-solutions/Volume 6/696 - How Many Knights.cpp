//*****************
// LAM PHAN VIET **
// UVA 696 - How Many Knights
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

int solve(int n, int m) {
    if (n == 1) return m;
    if (n == 2) {
        int res = (m / 4) * 4;
        res += min((m % 4), 2) * 2;
        return res;
    }
    return (n * m + 1) / 2;
}

main() {
//    FileIn("test"); FileOut("test");
    int n, m, res;
    while (scanf("%d %d", &n, &m) && (n || m)) {
        if (n > m) res = solve(m, n);
        else res = solve(n, m);
        printf("%d knights may be placed on a %d row %d column board.\n", res, n, m);
    }
}

/* lamphanviet@gmail.com - 2011 */
