//*****************
// LAM PHAN VIET **
// UVA 10330 - Power Transmission
// Time limit: 3.000s
//********************************
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define INF 500000000
#define maxN 205
int n, c[maxN][maxN], f[maxN][maxN];
int Trace[maxN], s, t;

void ReadInput() {
    int m, m1, m2, u, v, w;
    For (i, 1, n) {
        scanf("%d", &w);
        c[i][i+n] = w;
    }
    scanf("%d", &m);
    while (m--) {
        scanf("%d %d %d", &u, &v, &w);
        c[u+n][v] = w;
    }
    scanf("%d %d", &m1, &m2);
    s = n+n+1; t = s+1;
    while (m1--) {
        scanf("%d", &u);
        c[s][u] = INF;
    }
    while (m2--) {
        scanf("%d", &u);
        c[u+n][t] = INF;
    }
    n = t;
}

bool FindPath() {
    For (i, 1, n) Trace[i] = 0;
    Trace[s] = n+1;
    queue<int> Q; Q.push(s);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        For (v, 1, n)
            if (!Trace[v] && f[u][v]<c[u][v]) {
                Trace[v] = u;
                if (v==t) return true;
                Q.push(v);
            }
    }
    return false;
}

void IncFlow() {
    int Delta = INF, u, v;
    v = t;
    do {
        u = Trace[v];
        Delta = min(Delta, c[u][v]-f[u][v]);
        v = u;
    } while (v!=s);
    v = t;
    do {
        u = Trace[v];
        f[u][v] += Delta;
        f[v][u] -= Delta;
        v = u;
    } while (v!=s);
}

main() {
//    freopen("test.inp", "r", stdin); freopen("test.out", "w", stdout);
    while (scanf("%d", &n)!=EOF) {
        For (i, 1, maxN-1)
            For (j, 1, maxN-1) c[i][j] = f[i][j] = 0;
        ReadInput();
        while (FindPath()) IncFlow();
        int MaxFlow = 0;
        For (i, 1, n)
            if (f[s][i]>0) MaxFlow += f[s][i];
        printf("%d\n", MaxFlow);
    }
}

/* lamphanviet@gmail.com - 2011 */
