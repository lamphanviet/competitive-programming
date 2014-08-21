//*****************
// LAM PHAN VIET **
// UVA 988 - Many Paths, One Destination
// Time limit: 3.000s
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
#define maxN 2000
using namespace std;

int n, d[maxN];
bool Free[maxN];
vector<int> adj[maxN];
vector<int> sortedNode;

void DFS(int u) {
    Free[u] = false;
    REP (i, adj[u].size()) {
        int v = adj[u][i];
        if (Free[v]) DFS(v);
    }
    sortedNode.pb(u);
}

main() {
//    FileIn("test"); FileOut("test");
    bool Line = false;
    while (scanf("%d", &n)!=EOF) {
        REP (i, n) {
            adj[i].clear();
            Free[i] = true; d[i] = 0;
            int m, j;
            scanf("%d", &m);
            while (m--) {
                scanf("%d", &j);
                adj[i].pb(j);
            }
        }
        sortedNode.clear();
        DFS(0);
        d[0] = 1;
        int ans = 0;
        for (int i=sortedNode.size()-1; i>=0; i--) {
            int u = sortedNode[i];
            REP (j, adj[u].size())
                d[adj[u][j]] += d[u];
            if (!adj[u].size()) ans += d[u];
        }
        if (Line) printf("\n"); Line = true;
        printf("%d\n", ans);
    }
}

/* lamphanviet@gmail.com - 2011 */
