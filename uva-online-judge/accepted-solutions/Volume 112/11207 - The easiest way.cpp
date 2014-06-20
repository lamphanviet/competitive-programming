/*****************/
/* LAM PHAN VIET */
/* UVa: 11207 - The easiest way
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
#define maxN 10000
using namespace std;

main() {
//    FileIn("test"); FileOut("test");
    int n, res;
    double x, y, max_size;
    while (scanf("%d", &n) && n) {
        max_size = -1;
        FOR (i, 1, n) {
            scanf("%lf %lf", &x, &y);
            if (x < y) swap(x, y);
            double size = min(x, y) / 2;
            size = max(size, min(x / 4, y));
            if (size > max_size)
                max_size = size, res = i;
        }
        printf("%d\n", res);
    }
}

/* lamphanviet@gmail.com - 2011 */
