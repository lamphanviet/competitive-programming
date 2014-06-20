//*****************
// LAM PHAN VIET **
// UVA 10806 - Dijkstra, Dijkstra.
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
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define INF 500000000
#define maxN 101
int n, c[maxN][maxN];
int Trace[maxN];

int Dijkstra(int K) {
    int d[n+1];
    bool Free[n+1];
    For (i, 1, n) {
        d[i] = INF; Free[i] = true;
    }
    d[1] = 0;
    while (1) {
        int u = 0, Min = INF;
        For (i, 1, n) {
            if (K==1 && !Free[i]) continue;
            if (d[i]<Min) {
                Min = d[i]; u = i;
            }
        }
        if (u==0) return INF;
        if (u==n) return d[u];
        Free[u] = false;
        For (v, 1, n) {
            if (K==1 && !Free[v]) continue;
            if (c[u][v]!=INF && d[u]+c[u][v]<d[v]) {
                Trace[v] = u;
                d[v] = d[u] + c[u][v];
            }
        }
    }
    return INF;
}

int Ford_Bellman() {
    int d[n+1];
    For (i, 1, n) d[i] = INF;
    d[1] = 0;
    bool Stop;
    do {
        Stop = true;
        For (u, 1, n)
            For (v, 1, n)
                if (d[v] > d[u]+c[u][v]) {
                    d[v] = d[u] + c[u][v];
                    Stop = false;
                }
    } while (!Stop);
    return d[n];
}

main() {
 //   freopen("test.inp", "r", stdin); freopen("test.out", "w", stdout);
    int m, u, v, cost;
    while (scanf("%d", &n) && n) {
        For (i, 1, n)
            For (j, 1, n) c[i][j] = INF;
        scanf("%d", &m);
        while (m--) {
            scanf("%d %d %d", &u, &v, &cost);
            c[u][v] = c[v][u] = cost;
        }
        cost = Dijkstra(1);
        if (cost<INF) {
            v = n;
            do {
                u = Trace[v];
                c[v][u] = -c[u][v];
                c[u][v] = INF;
                v = u;
            } while (v!=1);
            cost += Ford_Bellman();
        }
        if (cost>=INF) puts("Back to jail");
        else printf("%d\n", cost);
    }
}

/* lamphanviet@gmail.com - 2011 */
