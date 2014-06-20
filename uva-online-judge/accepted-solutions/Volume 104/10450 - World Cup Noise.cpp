//*****************
// LAM PHAN VIET **
// UVA 10450 - World Cup Noise
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
#define INF 500000000
#define maxN 55
using namespace std;

uint64 f[maxN];

main() {
//    FileIn("test"); FileOut("test");
    f[0] = 1; f[1] = 2;
    FOR (i, 2, 51)
        f[i] = f[i-1] + f[i-2];
    int Case, n;
    scanf("%d", &Case);
    FOR (kk, 1, Case) {
        scanf("%d", &n);
        printf("Scenario #%d:\n", kk);
        printf("%lld\n\n", f[n]);
    }
}

/* lamphanviet@gmail.com - 2011 */
