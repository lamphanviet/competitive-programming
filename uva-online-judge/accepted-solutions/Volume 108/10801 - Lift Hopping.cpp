//*****************
// LAM PHAN VIET **
// UVA 10801 - Lift Hopping
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 101
#define INF 1000000
int n, K, Time[7];
bool a[7][maxN];

int Dijkstra() {
    int d[maxN], Free[maxN], changeTime = 0;
    For (i, 0, maxN-1) {
        d[i] = INF;
        Free[i] = true;
    }
    d[0] = 0;
    while (1) {
        int u = -1, tmpmin = INF;
        For (i, 0, maxN-1)
            if (Free[i] && d[i]<tmpmin) {
                tmpmin = d[i]; u = i;
            }
        if (u==-1 || u==K) break;
        Free[u] = false;
        For (i, 1, n) {
            if (!a[i][u]) continue;
            For (v, 1, maxN-1)
                if (Free[v] && a[i][v]) {
                    int cost = d[u] + Time[i]*abs(u-v) + changeTime;
                    d[v] = min(d[v], cost);
                }
        }
        changeTime = 60;
    }
    return d[K];
}

main() {
//    freopen("801.inp", "r", stdin); freopen("801.out", "w", stdout);
    char s[500];
    while (scanf("%d %d", &n, &K)!=EOF) {
        For (i, 1, n) {
            scanf("%d", &Time[i]);
            memset(a[i], false, maxN);
        }
        getchar();
        For (i, 1, n) {
            gets(s);
            int len = strlen(s), j = 0, elv;
            while (j<len) {
                while (j<len && s[j]==' ') j++;
                if (j<len) {
                    sscanf(s+j, "%d", &elv);
                    a[i][elv] = true;
                }
                while (j<len && s[j]!=' ') j++;
            }
        }
        int ans = Dijkstra();
        if (ans==INF) puts("IMPOSSIBLE");
        else printf("%d\n", ans);
    }
}

/* lamphanviet@gmail.com - 2011 */
