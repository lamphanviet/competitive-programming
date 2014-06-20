//*****************
// LAM PHAN VIET **
// UVA 10938 - Flea circus
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
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 5005
using namespace std;

int n, T[maxN], L[maxN], P[maxN][20];
vector<int> adj[maxN];

void build_tree(int u, int p, int lvl) {
    if (T[u]) return;
    T[u] = p;
    L[u] = lvl;
    REP(i, adj[u].size())
        build_tree(adj[u][i], u, lvl + 1);
}

void build_array() {
    FOR (i, 1, n) {
        P[i][0] = T[i];
        for (int j = 1; bit(j) < n; j++)
            P[i][j] = -1;
    }
    P[1][0] = -1;
    for (int j = 1; bit(j) < n; j++)
        FOR (i, 1, n)
            if (P[i][j - 1] != -1)
                P[i][j] = P[ P[i][j - 1] ][j - 1];
}

int LCA(int u, int v) {
    int Log = 0;
    for (; bit(Log) <= L[u]; Log++);
    Log--;
    for (int i = Log; i >= 0; i--)
        if (L[u] - bit(i) >= L[v])
            u = P[u][i];
            
    if (u == v) return u;
    
    for (int i = Log; i >= 0; i--)
        if (P[u][i]!= -1 && P[u][i] != P[v][i])
            u = P[u][i], v = P[v][i];
    return T[u];
}

int ancester(int u, int length) {
    int Log = 0;
    for (; bit(Log) <= L[u]; Log++);
    Log--;
    for (int i = Log; i >= 0; i--)
        if (length - bit(i) >= 0)
            u = P[u][i], length -= bit(i);
    return u;
}

void solve(int u, int v) {
    if (L[u] < L[v]) swap(u, v);
    int lca_level = L[LCA(u, v)];
    int length = L[u] + L[v] - (lca_level << 1);
    if (length % 2) {
        u = ancester(u, length >> 1);
        v = T[u];
        if (u > v) swap(u, v);
        printf("The fleas jump forever between %d and %d.\n", u, v);
    }
    else printf("The fleas meet at %d.\n", ancester(u, length >> 1));
}

main() {
//    FileIn("test"); FileOut("test");
    int m, u, v;
    while (scanf("%d", &n) && n) {
        FOR (i, 1, n) {
            adj[i].clear();
            T[i] = 0;
        }
        FOR (i, 2, n) {
            scanf("%d %d", &u, &v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        build_tree(1, n + 1, 0);
        build_array();
        scanf("%d", &m);
        while (m--) {
            scanf("%d %d", &u, &v);
            solve(u, v);
        }
    }
}

/* lamphanviet@gmail.com - 2011 */
