/*****************/
/* LAM PHAN VIET */
/* UVA 117 - The Postal Worker Rings Once
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
#define maxN 30
using namespace std;

int n = 26, s, t, deg[maxN], c[maxN][maxN];
char road[maxN];

int dijkstra() {
    int d[maxN];
    bool flag[maxN];
    REP(i, n)
        d[i] = INF, flag[i] = true;
    d[s] = 0;
    while (1) {
        int u = 0, cost_min = INF;
        REP(i, n)
            if (flag[i] && d[i] < cost_min) {
                cost_min = d[i]; u = i;
            }
        if (u == t) return d[t];
        flag[u] = false;
        REP(v, n)
            if (flag[v] && d[v] > d[u] + c[u][v])
                d[v] = d[u] + c[u][v];
    }
    return 0;
}

main() {
//    FileIn("test"); FileOut("test");
    int len, u, v;
    while (gets(road)) {
        REP(i, n) {
            deg[i] = 0;
            REP(j, n)
                c[i][j] = INF;
        }
        int res = 0;
        do {
            if (strcmp(road, "deadend") == 0) break;
            len = strlen(road);
            u = road[0] - 'a';
            v = road[len-1] - 'a';
            deg[u]++, deg[v]++;
            c[u][v] = c[v][u] = min(c[u][v], len);
            res += len;
        } while (gets(road));
        int odd_count = 0;
        REP(i, n)
            if (deg[i] % 2) {
                odd_count++;
                if (odd_count == 1) s = i;
                else if (odd_count == 2) t = i;
            }
        if (odd_count) res += dijkstra();
        printf("%d\n", res);
    }
}

/* lamphanviet@gmail.com - 2011 */
