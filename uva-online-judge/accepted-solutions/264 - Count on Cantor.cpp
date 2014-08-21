/*****************/
/* LAM PHAN VIET */
/* UVA 264 - Count on Cantor
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
#define maxN 10000001
using namespace std;

int x[maxN], y[maxN];

void precal() {
    x[1] = y[1] = 1;
    int direct = 1;
    FOR (n, 2, maxN-1) {
        if (x[n-1] == 1 && direct == 1) {
            x[n] = 1;
            y[n] = y[n-1] + 1;
            direct = -1;
        }
        else if (y[n-1] == 1 && direct == -1) {
            x[n] = x[n-1] + 1;
            y[n] = 1;
            direct = 1;
        }
        else {
            x[n] = x[n-1] - direct;
            y[n] = y[n-1] + direct;
        }
    }
}

main() {
//    FileIn("test"); FileOut("test");
    int n;
    precal();
    while (scanf("%d", &n) != EOF)
        printf("TERM %d IS %d/%d\n", n, x[n], y[n]);
}

/* lamphanviet@gmail.com - 2011 */
