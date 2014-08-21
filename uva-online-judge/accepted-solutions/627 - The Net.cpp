//*****************
// LAM PHAN VIET **
// UVA 627 - The Net
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 303
#define INF 1000000000
int n, a[maxN][maxN], Trace[maxN][maxN];

void ReadInput() {
   For (i, 1, n) {
      a[i][i] = 0;
      Trace[i][i] = i;
      For (j, i+1, n) {
         a[i][j] = a[j][i] = INF;
         Trace[i][j] = j;
         Trace[j][i] = i;
      }
   }
   int m, len, u, v, j;
   char s[maxN];
   gets(s);
   For (i, 1, n) {
      gets(s); len = strlen(s);
      j = 0;
      sscanf(s, "%d", &u);
      while (j<len && s[j]!='-') j++;
      while (j<len) {
         j++;
         if (j<len) {
            sscanf(s+j, "%d", &v);
            a[i][v] = 1;
            while (j<len && s[j]!=',') j++;
         }
      }
   }
}

void Floyd() {
   For (k, 1, n)
      For (u, 1, n)
         For (v, 1, n) {
            int cost = a[u][k]+a[k][v];
            if (cost<a[u][v]) {
               a[u][v] = cost;
               Trace[u][v] = Trace[u][k];
            }
         }
}

void Solve(int u, int v) {
   if (a[u][v]==INF) {
      puts("connection impossible");
      return;
   }
   printf("%d", u);
   while (u!=v) {
      u = Trace[u][v];
      printf(" %d", u);
   }
   printf("\n");
}

main() {
//   freopen("627.inp", "r", stdin); freopen("627.out", "w", stdout);
   int m, u, v;
   while (scanf("%d", &n)!=EOF) {
      ReadInput();
      Floyd();
      puts("-----");
      scanf("%d", &m);
      while (m--) {
         scanf("%d %d", &u, &v);
         Solve(u, v);
      }
   }
}

/* lamphanviet@gmail.com - 2011 */
