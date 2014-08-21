//*****************
// LAM PHAN VIET **
// UVA 10892 - LCM Cardinality
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
#define maxN 10000
using namespace std;

int64 GCD(int64 m, int64 n) { return n ? GCD(n, m%n): m; }

int64 LCM(int64 m, int64 n) {
    return (m*n / GCD(m, n));
}

main() {
//    FileIn("test"); FileOut("test");
    int n, nn, Count;
    vector<int> factor;
    while (scanf("%d", &n) && n) {
        factor.clear();
        nn = (int)sqrt(n);
        for (int i=1; i<=nn; i++)
            if (n%i==0) {
                factor.pb(i); factor.pb(n/i);
            }
        if (nn*nn==n) factor.pop_back();
        nn = factor.size();
        Count = 0;
        REP (i, nn)
            FOR (j, i, nn-1)
                if (LCM(factor[i], factor[j])==n) Count++;
        printf("%d %d\n", n, Count);
    }
}

/* lamphanviet@gmail.com - 2011 */
