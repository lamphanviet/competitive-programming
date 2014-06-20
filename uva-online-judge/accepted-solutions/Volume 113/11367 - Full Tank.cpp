/*****************/
/* LAM PHAN VIET */
/* UVA 11367 - Full Tank?
/* Time limit: 2.000s
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
#define maxN 1001
#define maxC 101
using namespace std;

struct Node {
    int city, fuel;
};
int n, price[maxN], d[maxN][maxC];
int nheap, pos[maxN][maxC];
Node heap[maxN * maxC];
vector<int> adj[maxN], adjW[maxN];
bool flag[maxN][maxC];

void heap_update(int city, int fuel) {
    int child = pos[city][fuel];
    if (!child) child = ++nheap;
    int parent = child >> 1;
    while (parent > 0 && d[heap[parent].city][heap[parent].fuel] > d[city][fuel]) {
        heap[child] = heap[parent];
        pos[heap[child].city][heap[child].fuel] = child;
        child = parent;
        parent = child >> 1;
    }
    heap[child].city = city;
    heap[child].fuel = fuel;
    pos[city][fuel] = child;
}

Node heap_pop() {
    Node pop = heap[1], v = heap[nheap--];
    int r = 1;
    while (r << 1 <= nheap) {
        int c = r << 1;
        if (c < nheap && d[heap[c+1].city][heap[c+1].fuel] < d[heap[c].city][heap[c].fuel]) c++;
        if (d[heap[c].city][heap[c].fuel] >= d[v.city][v.fuel]) break;
        heap[r] = heap[c];
        pos[heap[r].city][heap[r].fuel] = r;
        r = c;
    }
    heap[r] = v;
    pos[v.city][v.fuel] = r;
    return pop;
}

void dijkstra(int s, int t, int C) {
    REP(i, n)
        FOR (j, 0, C) {
            d[i][j] = INF;
            pos[i][j] = 0;
            flag[i][j] = true;
        }
    d[s][0] = nheap = 0;
    heap_update(s, 0);
    int u, fuel;
    while (nheap) {
        Node u_node = heap_pop();
        u = u_node.city, fuel = u_node.fuel;
        if (u == t) break;
        REP(i, adj[u].size()) {
            int v = adj[u][i], w = adjW[u][i];
            if (fuel >= w) {
                if (flag[v][fuel - w] && d[v][fuel-w] > d[u][fuel]) {
                    d[v][fuel - w] = d[u][fuel];
                    heap_update(v, fuel - w);
                }
            }
            else {
                int cost = d[u][fuel] + price[u] * (w - fuel);
                if (w <= C && flag[v][0] && d[v][0] > cost) {
                    d[v][0] = cost;
                    heap_update(v, 0);
                }
            }
        }
        
        if (fuel < C && flag[u][fuel+1] && d[u][fuel+1] > d[u][fuel] + price[u]) {
            d[u][fuel + 1] = d[u][fuel] + price[u];
            heap_update(u, fuel + 1);
        }
    }
    
    if (u == t && d[u][fuel] < INF)
        printf("%d\n", d[u][fuel]);
    else puts("impossible");
}

main() {
//    FileIn("test"); FileOut("test");
    int m, u, v, w;
    while (scanf("%d %d", &n, &m) != EOF) {
        REP(i, n) scanf("%d", &price[i]);
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            adj[u].pb(v); adjW[u].pb(w);
            adj[v].pb(u); adjW[v].pb(w);
        }
        scanf("%d", &m);
        while (m--) {
            scanf("%d %d %d", &w, &u, &v);
            dijkstra(u, v, w);
        }
    }
}

/* lamphanviet@gmail.com - 2011 */
