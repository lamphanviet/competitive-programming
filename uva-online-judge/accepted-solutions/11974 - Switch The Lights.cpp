/*****************/
/* LAM PHAN VIET */
/* UVA 11974 - Switch The Lights
/* Time limit: 5.000s
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
#define maxN 16
#define maxM 101
using namespace std;

int n, m, swt[maxM];
int d[bit(maxN)];

void bfs() {
    queue<int> Q;
    Q.push(bit(n) - 1);
    d[bit(n) - 1] = 0;
    while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        FOR(i, 1, m) {
            int xx = x ^ swt[i];
            if (d[xx] == INF) {
                d[xx] = d[x] + 1;
                if (!xx) return;
                Q.push(xx);
            }
        }
    }
}

main() {
//    FileIn("test"); FileOut("test");
    int Case, val;
    scanf("%d", &Case);
    FOR (kk, 1, Case) {
        scanf("%d %d", &n, &m);
        FOR (i, 1, m) {
            swt[i] = 0;
            REP(j, n) {
                scanf("%d", &val);
                swt[i] = (swt[i] << 1) + val;
            }
        }
        REP(i, bit(n)) d[i] = INF;
        bfs();
        printf("Case %d: ", kk);
        if (d[0] == INF) puts("IMPOSSIBLE");
        else printf("%d\n", d[0]);
    }
}

/* lamphanviet@gmail.com - 2011 */
