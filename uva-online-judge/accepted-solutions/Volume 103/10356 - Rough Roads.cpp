//*****************
// LAM PHAN VIET **
// UVA 10356 - Rough Roads
// Time limit: 6.000s
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
#define maxNN 1005
#define maxN 505
using namespace std;

int n, nn, d[maxNN];
int nheap, heap[maxNN], pos[maxNN];
bool flag[maxNN];
vector<int> adj[maxN], adjW[maxN];

void initialize() {
    nn = n << 1;
    REP(i, n) {
        pos[i] = pos[i + n] = 0;
        d[i] = d[i + n] = INF;
        flag[i] = flag[i + n] = true;
        adj[i].clear(); adjW[i].clear();
    }
}

void heap_update(int v) {
    int child = pos[v];
    if (!child) child = ++nheap;
    int parent = child >> 1;
    while (parent > 0 && d[heap[parent]] > d[v]) {
        heap[child] = heap[parent];
        pos[heap[child]] = child;
        child = parent;
        parent = child >> 1;
    }
    heap[child] = v;
    pos[v] = child;
}

int heap_pop() {
    int pop = heap[1];
    int v = heap[nheap--], r = 1;
    while (r + r <= nheap) {
        int c = r << 1;
        if (c < nheap && d[heap[c + 1]] < d[heap[c]]) c++;
        if (d[heap[c]] >= d[v]) break;
        heap[r] = heap[c];
        pos[heap[r]] = r;
        r = c;
    }
    heap[r] = v;
    pos[v] = r;
    return pop;
}

void dijkstra() {
    d[0] = nheap = 0;
    heap_update(0);
    while (nheap) {
        int u = heap_pop(), k, uu;
        if (u == n - 1) break;
        flag[u] = false;
        if (u >= n)
            k = 0, uu = u - n;
        else
            k = n, uu = u;
        REP(i, adj[uu].size()) {
            int v = adj[uu][i] + k, w = adjW[uu][i];
            if (flag[v] && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                heap_update(v);
            }
        }
    }
}

main() {
//    FileIn("test"); FileOut("test");
    int m, u, v, w, Set = 0;
    while (scanf("%d %d", &n, &m)!=EOF) {
        initialize();
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            adj[u].pb(v); adjW[u].pb(w);
            adj[v].pb(u); adjW[v].pb(w);
        }
        dijkstra();
        printf("Set #%d\n", ++Set);
        if (d[n - 1] != INF) printf("%d\n", d[n - 1]);
        else puts("?");
    }
}

/* lamphanviet@gmail.com - 2011 */
