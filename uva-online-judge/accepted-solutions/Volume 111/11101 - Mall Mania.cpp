/*****************/
/* LAM PHAN VIET */
/* UVA 11101 - Mall Mania
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
#define maxN 100001
using namespace std;

struct Point {
    int x, y;
};
int n, m;
vector<Point> a, b;

main() {
//    FileIn("test"); FileOut("test");
    while (scanf("%d", &n) && n) {
        a.resize(n);
        REP(i, n)
            scanf("%d %d", &a[i].x, &a[i].y);
        scanf("%d", &m);
        b.resize(m);
        REP(i, m)
            scanf("%d %d", &b[i].x, &b[i].y);
        int res = INF;
        if (n * m < maxN)
            REP (i, n)
                REP(j, m)
                    res = min(res, abs(a[i].x - b[j].x) + abs(a[i].y - b[j].y));
        else
            REP(k, maxN) {
                int i = rand() % n, j = rand() % m;
                res = min(res, abs(a[i].x - b[j].x) + abs(a[i].y - b[j].y));
            }
            printf("%d\n", res);
    }
}

/* lamphanviet@gmail.com - 2011 */
