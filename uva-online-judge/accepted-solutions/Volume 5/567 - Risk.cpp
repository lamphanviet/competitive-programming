//*****************
// LAM PHAN VIET **
// UVA 567 - Risk
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define INF 1000000000
#define n 20
int a[n+2][n+2];

void Floyd() {
   For (k, 1, 20)
      For (u, 1, 20)
         For (v, 1, 20)
            a[u][v] = min(a[u][v], a[u][k]+a[k][v]);
}

main() {
//   freopen("567.inp", "r", stdin); freopen("567.out", "w", stdout);
   int m, u, v, Case=0;
   while (scanf("%d", &m)!=EOF) {
      For (i, 1, n) {
         a[i][i] = 0;
         For (j, i+1, n)
            a[i][j] = a[j][i] = INF;
      }
      while (m--) {
         scanf("%d", &v);
         a[1][v] = a[v][1] = 1;
      }
      for (u=2; u<n; u++) {
         scanf("%d", &m);
         while (m--) {
            scanf("%d", &v);
            a[u][v] = a[v][u] = 1;
         }
      }
      Floyd();
      printf("Test Set #%d\n", ++Case);
      scanf("%d", &m);
      while (m--) {
         scanf("%d %d", &u, &v);
         printf("%2d to %2d: %d\n", u, v, a[u][v]);
      }
      printf("\n");
   }
}

/* lamphanviet@gmail.com - 2011 */
