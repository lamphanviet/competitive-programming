/*****************/
/* LAM PHAN VIET */
/* UVA 10302 - Summation of Polynomials
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
#define maxN 50001
using namespace std;

int64 res[maxN];

main() {
//    FileIn("test"); FileOut("test");
    res[1] = 1;
    FOR (i, 2, maxN-1) {
        res[i] = (int64)i * i * (int64)i;
        res[i] += res[i-1];
    }
    int n;
    while (scanf("%d", &n) != EOF)
        printf("%lld\n", res[n]);
}

/* lamphanviet@gmail.com - 2011 */
