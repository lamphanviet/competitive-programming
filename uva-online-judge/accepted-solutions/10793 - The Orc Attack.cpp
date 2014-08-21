//*****************
// LAM PHAN VIET **
// UVA 10793 - The Orc Attack
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
#define INF 50000000
#define maxN 101
int n, c[maxN][maxN];

main() {
 //   freopen("793.inp", "r", stdin); freopen("793.out", "w", stdout);
    int Case, m, u, v, cost;
    scanf("%d", &Case);
    For (kk, 1, Case) {
        scanf("%d %d", &n, &m);
        For (i, 1, n) {
            c[i][i] = 0;
            For (j, i+1, n)
                c[i][j] = c[j][i] = INF;
        }
        while (m--) {
            scanf("%d %d %d", &u, &v, &cost);
            c[u][v] = c[v][u] = min(c[u][v], cost);
        }
        For (k, 1, n)
            For (u, 1, n)
                For (v, 1, n)
                    c[u][v] = min(c[u][v], c[u][k]+c[k][v]);
        int ans = INF;
        For (i, 6, n) {
            int tmp = c[i][1];
            if (tmp!=INF) {
                cost = c[i][1];
                For (j, 2, 5)
                    if (c[i][j]!=cost) {
                        tmp = INF;
                        break;
                    }
            }
            if (tmp!=INF) For (j, 6, n)
                tmp = max(tmp, c[i][j]);
            ans = min(ans, tmp);
        }
        if (ans==INF) ans = -1;
        printf("Map %d: %d\n", kk, ans);
    }
}

/* lamphanviet@gmail.com - 2011 */
