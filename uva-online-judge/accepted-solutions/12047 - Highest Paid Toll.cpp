//*****************
// LAM PHAN VIET **
// UVA 12047 - Highest Paid Toll
// Time limit: 1.000s
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
#define INF 500000000
#define maxN 10001
using namespace std;

int n, s, t, P;
int64 ds[maxN], dt[maxN];
int nheap, heap[maxN], pos[maxN];
vector<int> adj[maxN], adjW[maxN];
vector<int> adj_r[maxN], adjW_r[maxN];

void heap_update(int v, int64 *d) {
    int child = pos[v];
    if (!child) child = ++nheap;
    int parent = child / 2;
    while (parent > 0 && d[heap[parent]] > d[v]) {
        heap[child] = heap[parent];
        pos[heap[child]] = child;
        child = parent;
        parent = child / 2;
    }
    heap[child] = v;
    pos[v] = child;
}

int heap_pop(int64 *d) {
    int popheap = heap[1];
    int v = heap[nheap--], r = 1;
    while (r + r <= nheap) {
        int c = r + r;
        if (c < nheap && d[heap[c+1]] < d[heap[c]]) c++;
        if (d[heap[c]] >= d[v]) break;
        heap[r] = heap[c];
        pos[heap[r]] = r;
        r = c;
    }
    heap[r] = v;
    pos[v] = r;
    return popheap;
}

void dijkstra(int start, int64 *d, vector<int> a[], vector<int> aW[]) {
    bool Free[n+1];
    FOR (i, 1, n) {
        d[i] = INF;
        pos[i] = 0;
        Free[i] = true;
    }
    d[start] = nheap = 0;
    heap_update(start, d);
    
    while (nheap) {
        int u = heap_pop(d);
        Free[u] = false;
        REP(i, a[u].size()) {
            int v = a[u][i], w = aW[u][i];
            if (Free[v] && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                heap_update(v, d);
            }
        }
    }
}

int solve() {
    dijkstra(s, ds, adj, adjW);
    if (ds[t] > P) return -1;
    dijkstra(t, dt, adj_r, adjW_r);
    if (dt[s] > P) return -1;
    
    int res = -1, f = 0;
    FOR (u, 1, n)
        REP(i, adj[u].size()) {
            int v = adj[u][i], w = adjW[u][i];
            int64 cost = ds[u] + w + dt[v];
            if (cost <= P && w > res) {
                res = w; f = 1;
            }
        }
    return res;
}

main() {
//    FileIn("test"); FileOut("test");
    int Case, m, u, v, w;
    for (scanf("%d", &Case); Case--; ) {
        scanf("%d %d %d %d %d", &n, &m, &s, &t, &P);
        FOR (i, 1, n) {
            adj[i].clear(); adj_r[i].clear();
            adjW[i].clear(); adjW_r[i].clear();
        }
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            adj[u].pb(v); adjW[u].pb(w);
            adj_r[v].pb(u); adjW_r[v].pb(w);
        }
        printf("%d\n", solve());
    }
}

/* lamphanviet@gmail.com - 2011 */
