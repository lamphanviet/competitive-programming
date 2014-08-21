//*****************
// LAM PHAN VIET **
// UVA 11966 - Galactic Bonding
// Time limit: 2s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define maxN 1005
int n;
double x[maxN], y[maxN], a[maxN][maxN], D;
bool Free[maxN];

double Dis(double x1, double y1, double x2, double y2) {
    double k1 = x1-x2;
    double k2 = y1-y2;
    return sqrt(k1*k1 + k2*k2);
}

void DFS(int u) {
    Free[u] = false;
    for (int v=0; v<n; v++)
        if (Free[v] && a[u][v]<=D) {
            DFS(v);
        }
}

main() {
//    freopen("pp.inp", "r", stdin); freopen("pp.out", "w", stdout);
    int Case;
    scanf("%d", &Case);
    for (int kk=1; kk<=Case; kk++) {
        scanf("%d %lf", &n, &D);
        for (int i=0; i<n; i++) {
            scanf("%lf %lf", &x[i], &y[i]);
            Free[i] = true;
        }
        for (int i=0; i<n; i++) {
            a[i][i] = 0;
            for (int j=i+1; j<n; j++)
                a[i][j] = a[j][i] = Dis(x[i], y[i], x[j], y[j]);
        }
        int Count = 0;
        for (int i=0; i<n; i++)
            if (Free[i]) {
                Count++;
                DFS(i);
            }
        printf("Case %d: %d\n", kk, Count);
    }
}

/* lamphanviet@gmail.com - 2011 */
