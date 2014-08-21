//*****************
// LAM PHAN VIET **
// UVA 11374 - Airport Express
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
#define INF 500000000
#define maxN 505
using namespace std;

int n, s, t, ds[maxN], dt[maxN], traces[maxN], tracet[maxN];
int nheap, heap[maxN], pos[maxN];
vector<int> adj[maxN], adjW[maxN];
bool isfree[maxN];
int cost_min, cs, ct;   // result

void update_heap(int v, int *d) {
    int child = pos[v];
    if (!child) child = ++nheap;
    int parent = child/2;
    while (parent > 0 && d[heap[parent]] > d[v]) {
        heap[child] = heap[parent];
        pos[heap[child]] = child;
        child = parent;
        parent = child/2;
    }
    heap[child] = v;
    pos[v] = child;
}

int pop_heap(int *d) {
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

void dijkstra(int start, int *d, int *trace) {
    FOR (i, 1, n) {
        pos[i] = trace[i] = 0;
        d[i] = INF;
        isfree[i] = true;
    }
    d[start] = nheap = 0;
    update_heap(start, d);
    while (nheap) {
        int u = pop_heap(d);
        isfree[u] = false;
        REP(i, adj[u].size()) {
            int v = adj[u][i], w = adjW[u][i];
            if (isfree[v] && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                trace[v] = u;
                update_heap(v, d);
            }
        }
    }
}

void check(int u, int v, int w) {
    int cost = ds[u] + w + dt[v];
    if (cost < cost_min) {
        cost_min = cost;
        cs = u; ct = v;
    }
}

void result() {
    vector<int> stations;
    int u = cs;
    if (u==-1) u = t;
    stations.pb(u);
    while (u!=s) {
        u = traces[u];
        stations.pb(u);
    }
    printf("%d", stations.back());
    for (int i = stations.size()-2; i >= 0; i--)
        printf(" %d", stations[i]);
    if (cs != -1) {
        stations.clear();
        stations.pb(ct);
        while (ct != t) {
            ct = tracet[ct];
            stations.pb(ct);
        }
        REP(i, stations.size())
            printf(" %d", stations[i]);
        printf("\n%d\n", cs);
    }
    else if (cs==-1) puts("\nTicket Not Used");
    printf("%d\n", cost_min);
}

main() {
//    FileIn("test"); FileOut("test");
    int m, u, v, w;
    bool line = false;
    while (scanf("%d %d %d", &n, &s, &t)!=EOF) {
        FOR (i, 1, n)
            adj[i].clear(), adjW[i].clear();
        scanf("%d", &m);
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            adj[u].pb(v); adjW[u].pb(w);
            adj[v].pb(u); adjW[v].pb(w);
        }
        dijkstra(s, ds, traces);
        dijkstra(t, dt, tracet);
        scanf("%d", &m);
        cost_min = ds[t]; cs = -1;
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            check(u, v, w); check(v, u, w);
        }
        if (line) puts(""); line = true;
        result();
    }
}


/* lamphanviet@gmail.com - 2011 */
