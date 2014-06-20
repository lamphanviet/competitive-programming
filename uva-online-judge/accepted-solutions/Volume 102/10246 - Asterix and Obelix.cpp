//*****************
// LAM PHAN VIET **
// UVA 10246 - Asterix and Obelix
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define INF 500000000
#define maxN 85
int n, cost[maxN];
int c[maxN][maxN], large[maxN][maxN];

void Floyd() {
    For (k, 1, n)
        For (u, 1, n)
            For (v, 1, n) {
                int tmpcost = c[u][k] + c[k][v];
                int tmplarge = max(large[u][k], large[k][v]);
                if (tmpcost + tmplarge < c[u][v] + large[u][v]) {
                    c[u][v] = c[v][u] = tmpcost;
                    large[u][v] = large[v][u] = tmplarge;
                }
            }
}

main() {
//    freopen("246.inp", "r", stdin); freopen("246.out", "w", stdout);
    int Case = 0, m, q, u, v, w;
    while (scanf("%d %d %d", &n, &m, &q) && (n || m || q)) {
        For (i, 1, n) {
            scanf("%d", &cost[i]);
            For (j, i+1, n) {
                c[i][j] = c[j][i] = INF;
                large[i][j] = large[j][i] = INF;
            }
            c[i][i] = 0;
            large[i][i] = cost[i];
        }
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            c[u][v] = c[v][u] = w;
            large[u][v] = large[v][u] = max(cost[u], cost[v]);
        }
        Floyd(); Floyd();
        if (Case) printf("\n");
        printf("Case #%d\n", ++Case);
        while (q--) {
            scanf("%d %d", &u, &v);
            int ans = -1;
            if (c[u][v]<INF) ans = c[u][v] + large[u][v];
            printf("%d\n", ans);
        }
    }
}

/* lamphanviet@gmail.com - 2011 */
