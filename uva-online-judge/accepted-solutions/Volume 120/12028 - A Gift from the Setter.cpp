//*****************
// LAM PHAN VIET **
// UVA 12028 - A Gift from the Setter
// Time limit: 2.000s
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
#define MOD 1000007
#define maxN 100001
using namespace std;

int k, c, n;
uint64 a[maxN];

main() {
//    FileIn("test"); FileOut("test");
    int Case;
    scanf("%d", &Case);
    FOR (kk, 1, Case) {
        scanf("%lld %lld %lld %lld", &k, &c, &n, &a[0]);
        FOR (i, 1, n-1)
            a[i] = (k * a[i-1] + c)%MOD;
        sort(a, a+n);
        uint64 res = 0, last = 0;
        FOR (i, 1, n-1) {
            uint64 dif = a[i] - a[i-1];
            last += dif * (uint64)(i);
            res += last;
        }
        printf("Case %d: %lld\n", kk, res);
    }
}

/* lamphanviet@gmail.com - 2011 */
