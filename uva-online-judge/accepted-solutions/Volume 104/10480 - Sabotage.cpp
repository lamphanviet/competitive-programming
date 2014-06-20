//*****************
// LAM PHAN VIET **
// UVA 10480 - Sabotage
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
#define maxN 55
int n, c[maxN][maxN], f[maxN][maxN];
int Trace[maxN];

bool FindPath() {
    For (i, 1, n) Trace[i] = 0;
    Trace[1] = n+1;
    queue<int> Q; Q.push(1);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        For (v, 1, n)
            if (!Trace[v] && c[u][v]>f[u][v]) {
                Trace[v] = u;
                if (v==2) return true;
                Q.push(v);
            }
    }
    return false;
}

void IncFlow() {
    int Delta = INF, u, v;
    v = 2;
    do {
        u = Trace[v];
        Delta = min(Delta, c[u][v]-f[u][v]);
        v = u;
    } while (v!=1);
    v = 2;
    do {
        u = Trace[v];
        f[u][v] += Delta;
        f[v][u] -= Delta;
        v = u;
    } while (v!=1);
}

void Result() {
    bool Free[n+1], cut[n+1][n+1];
    memset(Free, true, n+1);
    memset(cut, false, sizeof(cut));
    queue<int> Q;
    Q.push(1); Free[1] = false;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        For (v, 1, n) {
            if (Free[v] && c[u][v] && f[u][v]<c[u][v]) {
                Free[v] = false;
                Q.push(v);
            }
        }
    }
    For (i, 1, n)
        For (j, 1, n)
            if (!Free[i] && Free[j] && c[i][j] && f[i][j]==c[i][j])
                printf("%d %d\n", i, j);
}

main() {
//    freopen("test.inp", "r", stdin); freopen("test.out", "w", stdout);
    int m, u, v, w;
    while (scanf("%d %d", &n, &m) && (n || m)) {
        For (i, 1, n)
            For (j, 1, n)
                c[i][j] = f[i][j] = 0;
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            c[u][v] = c[v][u] = w;
        }
        while (FindPath()) IncFlow();
        Result();
        printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
