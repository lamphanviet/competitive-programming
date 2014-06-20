//*****************
// LAM PHAN VIET **
// UVA 280 - Vertex
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
#define maxN 101
using namespace std;

int n, Count;
vector<int> adj[maxN];
bool Free[maxN];

void Visit(int u) {
    REP (i, adj[u].size())
        if (Free[adj[u][i]]) {
            Count++;
            Free[adj[u][i]] = false;
            Visit(adj[u][i]);
        }
}

main() {
//    FileIn("test"); FileOut("test");
    int m, u, v;
    while (scanf("%d", &n) && n) {
        FOR (i, 1, n) adj[i].clear();
        while (scanf("%d", &u) && u) {
            while (scanf("%d", &v) && v)
                adj[u].pb(v);
        }
        for (scanf("%d", &m); m--; ) {
            memset(Free, true, n+1);
            scanf("%d", &u);
            Count = 0;
            Visit(u);
            printf("%d", n - Count);
            FOR (i, 1, n)
                if (Free[i]) printf(" %d", i);
            printf("\n");
        }
        
    }
}

/* lamphanviet@gmail.com - 2011 */
