/*****************/
/* LAM PHAN VIET */
/* UVa: 10849 - Move the bishop
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

bool ok(int x, int y, int n) {
    return (x >= 1 && x <= n && y >= 1 && y <= n);
}

main() {
//    FileIn("test"); FileOut("test");
    int Case, test, n;
    int x0, y0, x, y;
    for (scanf("%d", &Case); Case--; ) {
        for (scanf("%d %d", &test, &n); test--; ) {
            scanf("%d %d", &x0, &y0);
            scanf("%d %d", &x, &y);
            bool a = (x0 + y0) & 1;
            bool b = (x + y) & 1;
            if (((a && b) || (!a && !b)) && ok(x, y, n) && ok(x0, y0, n)) {
                if (x0 == x && y0 == y)
                    putchar('0');
                else if ((x0 + y0 == x + y) || (x0 - y0 == x - y))
                    putchar('1');
                else putchar('2');
                putchar('\n');
            }
            else puts("no move");
        }
    }
}

/* lamphanviet@gmail.com - 2011 */
