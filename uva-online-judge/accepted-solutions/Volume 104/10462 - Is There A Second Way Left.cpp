//*****************
// LAM PHAN VIET **
// UVA 10462 - Is There A Second Way Left
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
#define maxN 102
using namespace std;

int n, d[maxN];
vector<int> adj[maxN], adjW[maxN], adjE[maxN];
vector<int> Edge[maxN];
bool Free[maxN];

int Prim(int x) {
    FOR (i, 1, n) {
        d[i] = INF;
        Free[i] = true;
    }
    d[1] = 0;
    while (1) {
        int Min = INF, u = 0;
        FOR (i, 1, n)
            if (Free[i] && d[i]<Min) {
                Min = d[i]; u = i;
            }
        if (u==0) break;
        Free[u] = false;
        REP (i, adj[u].size()) {
            int v = adj[u][i], w = adjW[u][i], e = adjE[u][i];
            if (Free[v] && e!=x && d[v] >= w) {
                if (x==-1) {
                    if (d[v] > w) Edge[v].clear();
                    Edge[v].pb(e);
                }
                d[v] = w;
            }
        }
    }
    int Cost = 0;
    FOR (i, 1, n)
        if (d[i]<INF) Cost += d[i];
        else return -1;
    return Cost;
}

int Solve() {
    int Min = Prim(-1), SMin = INF;
    if (Min==-1) return -1;
    FOR (i, 1, n) {
        REP (j, Edge[i].size()) {
            int tmp = Prim(Edge[i][j]);
            if (tmp>=0) SMin = min(tmp, SMin);
        }
    }
    if (SMin==INF) return -2;
    else return SMin;
}

main() {
//    FileIn("test"); FileOut("test");
    int Case, m, u, v, w;
    scanf("%d", &Case);
    FOR (kk, 1, Case) {
        scanf("%d %d", &n, &m);
        FOR (i, 1, n) {
            adj[i].clear(); adjW[i].clear(); adjE[i].clear();
            Edge[i].clear();
        }
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            adj[u].pb(v); adjW[u].pb(w); adjE[u].pb(m+1);
            adj[v].pb(u); adjW[v].pb(w); adjE[v].pb(m+1);
        }
        int ans = Solve();
        printf("Case #%d : ", kk);
        if (ans == -1) puts("No way");
        else if (ans == -2) puts("No second way");
        else printf("%d\n", ans);
    }
}

/* lamphanviet@gmail.com - 2011 */
