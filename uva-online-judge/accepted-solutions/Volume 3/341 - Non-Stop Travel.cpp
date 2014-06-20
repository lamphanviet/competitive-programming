//*****************
// LAM PHAN VIET **
// UVA 341 - Non-Stop Travel
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 12
#define INF 5000000
int n, a[maxN][maxN], s, f;
int d[maxN], Trace[maxN];
bool Free[maxN];

void Dijkstra() {
    d[s] = 0;
    while (1) {
        int u = 0, tmpmin = INF;
        For (i, 1, n)
            if (Free[i] && d[i]<tmpmin) {
                tmpmin = d[i]; u = i;
            }
        if (u==0 || u==f) return;
        Free[u] = false;
        For (v, 1, n)
            if (Free[v] && d[u]+a[u][v]<d[v]) {
                d[v] = d[u]+a[u][v];
                Trace[v] = u;
            }
    }
}

main() {
//    freopen("341.inp", "r", stdin); freopen("341.out", "w", stdout);
    int Case = 0, delaytime, v, m;
    while (scanf("%d", &n) && n) {
        For (u, 1, n) {
            For (i, 1, n) a[u][i] = INF;
            scanf("%d", &m);
            while (m--) {
                scanf("%d %d", &v, &delaytime);
                a[u][v] = delaytime;
            }
            d[u] = INF;
            Free[u] = true;
        }
        scanf("%d %d", &s, &f);
        Dijkstra();
        printf("Case %d: Path =", ++Case);
        vector<int> ans;
        ans.push_back(f);
        do {
            f = Trace[f];
            ans.push_back(f);
        } while (f!=s);
        for (int i=ans.size()-1; i>=0; i--) printf(" %d", ans[i]);
        printf("; %d second delay\n", d[ans[0]]);
    }
}

/* lamphanviet@gmail.com - 2011 */
