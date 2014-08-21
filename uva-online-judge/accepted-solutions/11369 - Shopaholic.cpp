//*****************
// LAM PHAN VIET **
// UVA 11369 - Shopaholic
// Time limit: 1.000s
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
#define maxN 20002
using namespace std;

int n, a[maxN];

bool cmp(int a, int b) { return ( a > b ); }

main() {
//    FileIn("test"); FileOut("test");
    int Case;
    for (scanf("%d", &Case); Case--; ) {
        scanf("%d", &n);
        FOR (i, 1, n) scanf("%d", &a[i]);
        sort(a + 1, a + n + 1, cmp);
        int Cost = 0;
        for (int i=3; i<=n; i+=3)
            Cost += a[i];
        printf("%d\n", Cost);
    }
}

/* lamphanviet@gmail.com - 2011 */
