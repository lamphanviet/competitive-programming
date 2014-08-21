//*****************
// LAM PHAN VIET **
// UVA 10986 - Sending email - (Dijkstra Heap)
// Time limit: 4s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 20001
#define INF (1<<30)
int n, S, T, nHeap;
int Pos[maxN], Heap[maxN], d[maxN];
vector<int> adj[maxN], adjTime[maxN];
bool Free[maxN];

void Init() {
    For (i, 0, n-1) {
        adj[i].clear(); adjTime[i].clear();
        d[i] = INF;
        Pos[i] = 0;
        Free[i] = true;
    }
    d[S] = 0;
    nHeap = 0;
}

void UpdateHeap(int v) {
    int child = Pos[v];
    if (child==0) child = ++nHeap;
    int parent = child/2;
    while (parent>0 && d[Heap[parent]]>d[v]) {
        Heap[child] = Heap[parent];
        Pos[Heap[child]] = child;
        child = parent;
        parent = child/2;
    }
    Heap[child] = v;
    Pos[v] = child;
}

int PopHeap() {
    int pop = Heap[1];
    int v = Heap[nHeap--], r = 1;
    while (r+r<=nHeap) {
        int c= r+r;
        if (c<nHeap && d[Heap[c+1]]<d[Heap[c]]) c++;
        if (d[v]<=d[Heap[c]]) break;
        Heap[r] = Heap[c];
        Pos[Heap[r]] = r;
        r = c;
    }
    Heap[r] = v;
    Pos[v] = r;
    return pop;
}

void Dijkstra() {
    UpdateHeap(S);
    do {
        int u = PopHeap();
        if (u==T) break;
        Free[u] = false;
        for (int i=0, size=adj[u].size(); i<size; i++) {
            int v = adj[u][i];
            if (!Free[v] || d[u]+adjTime[u][i]>=d[v]) continue;
            d[v] = d[u] + adjTime[u][i];
            UpdateHeap(v);
        }
    } while (nHeap!=0);
}

main() {
//    freopen("986.inp", "r", stdin); freopen("986.out", "w", stdout);
    int Case, m, u, v, w;
    scanf("%d", &Case);
    For (kk, 1, Case) {
        scanf("%d %d %d %d", &n, &m, &S, &T);
        Init();
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back(v); adjTime[u].push_back(w);
            adj[v].push_back(u); adjTime[v].push_back(w);
        }
        Dijkstra();
        printf("Case #%d: ", kk);
        if (d[T]==INF) puts("unreachable");
        else printf("%d\n", d[T]);
    }
}

/* lamphanviet@gmail.com - 2011 */
