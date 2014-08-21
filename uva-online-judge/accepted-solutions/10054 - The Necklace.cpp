/*****************/
/* LAM PHAN VIET */
/* UVA 10054 - The Necklace
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
#define maxM 1005
#define maxN 55
using namespace std;

const int n = 50;
int c[maxN][maxN], deg[maxN];
bool flag[maxN];

void initialize() {
    FOR (i, 1, n) {
        FOR (j, 1, n) c[i][j] = 0;
        deg[i] = 0;
        flag[i] = true;
    }
}

void dfs(int u) {
    flag[u] = false;
    FOR (v, 1, n)
        if (flag[v] && c[u][v]) dfs(v);
}

bool can_go_back(int x, int y) {
    Fill(flag, true);
    queue<int> Q;
    Q.push(y);
    flag[y] = false;
    c[x][y]--, c[y][x]--;
    bool stop = false;
    while (!Q.empty() && !stop) {
        int u = Q.front(); Q.pop();
        FOR (v, 1, n)
            if (flag[v] && c[u][v]) {
                flag[v] = false;
                if (v == x) {
                    stop = true;
                    break;
                }
                Q.push(v);
            }
    }
    c[x][y]++, c[y][x]++;
    return !flag[x];
}

bool solve() {
    FOR (i, 1, n)
        if (deg[i] % 2) return false;

    int s, f;
    FOR (i, 1, n)
        if (deg[i]) {
            s = i; break;
        }
    dfs(s);
    FOR (i, 1, n)
        if (deg[i] && flag[i]) return false;
        
    do {
        f = 0;
        FOR (v, 1, n)
            if (c[s][v]) {
                f = v;
                if (can_go_back(s, f)) break;
            }
        if (!f) break;
        printf("%d %d\n", s, f);
        c[s][f]--, c[f][s]--;
        s = f;
    } while (f);
    return true;
}

main() {
//    FileIn("test"); FileOut("test");
    int Case, m, u, v;
    scanf("%d", &Case);
    FOR (kk, 1, Case) {
        initialize();
        scanf("%d", &m);
        while (m--) {
            scanf("%d %d", &u, &v);
            c[u][v]++, c[v][u]++;
            deg[u]++, deg[v]++;
        }

        printf("Case #%d\n", kk);
        if (!solve()) puts("some beads may be lost");
        if (kk < Case) putchar('\n');
    }
}

/* lamphanviet@gmail.com - 2011 */
