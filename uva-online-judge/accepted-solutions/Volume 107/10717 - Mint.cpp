//*****************
// LAM PHAN VIET **
// UVA 10717 - Mint
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
#define INF 2000000000
#define maxN 55
using namespace std;

int n, a[maxN], k;
uint64 x, y;

int GCD(int m, int n) {
    if (m%n) return GCD(n, m%n);
    return n;
}

int LCM(int m, int n) {
    return (int)(m*(uint64)n/GCD(m, n));
}

void Solve() {
    x = 0; y = INF;
    FOR (i, 1, n-3)
        FOR (j, i+1, n-2)
            FOR (u, j+1, n-1)
                FOR (v, u+1, n) {
                    uint64 lcm = LCM(a[i], LCM(a[j], LCM(a[u], a[v])));
                    if (k%lcm==0) {
                        x = y = k;
                        return;
                    }
                    int p = k/lcm;
                    x = max(p*lcm, x);
                    y = min((p+1)*lcm, y);
                }
}

main() {
//    FileIn("test"); FileOut("test");
    int m;
    while (scanf("%d %d", &n, &m) && (n || m)) {
        FOR (i, 1, n) scanf("%d", &a[i]);
        while (m--) {
            scanf("%d", &k);
            Solve();
            printf("%lld %lld\n", x, y);
        }
    }
}

/* lamphanviet@gmail.com - 2011 */
