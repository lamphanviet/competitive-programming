//----------------------------
// LAM PHAN VIET
// UVA 11833 - Route Change
// Time limit: 1s
//----------------------------
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

#define maxN 255
#define INF 1000000
int a[maxN][maxN], n, c, K;
int costc[maxN], d[maxN];

void Dijkstra() {
    bool Free[n+3];
    for (int i=c; i<n; i++) {
        Free[i] = true;
        d[i] = INF;
    }
    d[K] = 0;
    while (1) {
        int tmpmin=INF, u = 0;
        for (int i=c; i<n; i++)
            if (Free[i] && d[i]<tmpmin) {
                u = i; tmpmin = d[i];
            }
        if (u==0) return;
        Free[u] = false;
        for (int v=c; v<n; v++)
            if (Free[v] && d[u]+a[u][v]<d[v])
                d[v] = d[u] + a[u][v];
    }
}

main() {
    int m, p, u, v;
    while (scanf("%d %d %d %d", &n, &m, &c, &K)) {
        if (!n && !m && !c && !K) break;
        for (int i=0; i<n; i++)
            for (int j=i; j<n; j++)
                a[i][j] = a[j][i] = INF;
        while (m--) {
            scanf("%d %d %d", &u, &v, &p);
            a[u][v] = a[v][u] = p;
        }
        costc[c-1]= 0;
        for (int i=c-2; i>=0; i--)
            costc[i] = costc[i+1] + a[i][i+1];
        Dijkstra();
        
        int result = INF;
        for (int i=c; i<n; i++)
            for (int j=0; j<c; j++)
                if (d[i]+costc[j] + a[i][j] < result)
                    result = d[i] + costc[j] + a[i][j];
        printf("%d\n", result);
    }
}
