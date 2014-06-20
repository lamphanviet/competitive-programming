//*****************
// LAM PHAN VIET **
// UVA 11951 - Area
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxN 105
#define INF 1000000005
int sum[maxN][maxN], n, m, K;

main() {
//    freopen("aa.inp", "r", stdin); freopen("aa.out", "w", stdout);
    int Case, val;
    scanf("%d", &Case);
    for (int kk=1; kk<=Case; kk++) {
        scanf("%d %d %d", &n, &m, &K);
        for (int i=1; i<=n; i++) {
            sum[0][i] = 0;
            for (int j=1; j<=m; j++) {
                scanf("%d", &val);
                sum[i][j] = sum[i-1][j]+val;
            }
        }
        int area = 0, mincost = INF, tmpcost, c1, c2;
        for (int r1 = 1; r1<=n; r1++)
            for (int r2=r1; r2<=n; r2++) {
                c1 = 1; tmpcost = 0;
                for (int c2=1; c2<=m; c2++) {
                    tmpcost += sum[r2][c2] - sum[r1-1][c2];
                    while (c1<=c2 && tmpcost>K) {
                            tmpcost -= sum[r2][c1] - sum[r1-1][c1];
                            c1++;
                        }
                    int tmparea = (r2-r1+1)*(c2-c1+1);
                    if (tmparea > area || (tmparea == area && tmpcost<mincost)) {
                        area = tmparea;
                        mincost = tmpcost;
                    }
                }
            }
        printf("Case #%d: %d %d\n", kk, area, mincost);
    }
}

/* lamphanviet@gmail.com - 2011 */
