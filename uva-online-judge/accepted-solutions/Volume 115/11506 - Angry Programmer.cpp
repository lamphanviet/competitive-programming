//*****************
// LAM PHAN VIET **
// UVA 11506 - Angry Programmer
// Time limit: 3.000s
//********************************
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define INF 500000000
#define maxN 105
int n, c[maxN][maxN], f[maxN][maxN];
int Trace[maxN];

bool FindPath() {
    For (i, 1, n) Trace[i] = 0;
    queue<int> Q; Q.push(1);
    Trace[1] = n+1;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        For (v, 1, n)
            if (!Trace[v] && f[u][v]<c[u][v]) {
                Trace[v] = u;
                if (v==n) return true;
                Q.push(v);
            }
    }
    return false;
}

void IncFlow() {
    int Delta = INF, u, v;
    v = n;
    do {
        u = Trace[v];
        Delta = min(Delta, c[u][v]-f[u][v]);
        v = u;
    } while (v!=1);
    v = n;
    do {
        u = Trace[v];
        f[u][v] += Delta;
        f[v][u] -= Delta;
        v = u;
    } while (v!=1);
}

main() {
//    freopen("test.inp", "r", stdin); freopen("test.out", "w", stdout);
    int m, u, v, w;
    while (scanf("%d %d", &n, &m) && (n || m)) {
        For (i, 1, n+n+2)
            For (j, 1, n+n+2) c[i][j] = f[i][j] = 0;
        For (i, 2, n-1) {
            scanf("%d %d", &u, &w);
            c[u][u+n] = w;
        }
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            c[u+n][v] = w;
            c[v+n][u] = w;
        }
        c[1][n+1] = c[n][n+n] = INF;
        n += n;
        while (FindPath()) IncFlow();
        int MaxFlow = 0;
        For (v, 1, n)
            if (f[1][v]>0) MaxFlow += f[1][v];
        printf("%d\n", MaxFlow);
    }
}

/* lamphanviet@gmail.com - 2011 */
