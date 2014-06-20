//*****************
// LAM PHAN VIET **
// UVA 10301 - Rings and Glue
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
int n;
bool cnt[maxN][maxN], Free[maxN];
double x[maxN], y[maxN], r[maxN];

bool isEdge(int i, int j) {
   double a = x[i]-x[j];
   double b = y[i]-y[j];
   double d = sqrt(a*a + b*b);
   if (d<r[i]+r[j]) {
      if (d>=max(r[i], r[j])) return true;
      if (d==0) return (r[i]==r[j]);
      return (d+min(r[i], r[j]) > max(r[i], r[j]));
   }
   return false;
}

int DFS(int u) {
   int Count = 1;
   For (v, 1, n)
      if (Free[v] && cnt[u][v]) {
         Free[v] = false;
         Count += DFS(v);
      }
   return Count;
}

main() {
//   freopen("301.inp", "r", stdin); freopen("301.out", "w", stdout);
   while (scanf("%d", &n) && n!=-1) {
      For (i, 1, n) {
         scanf("%lf %lf %lf", &x[i], &y[i], &r[i]);
         memset(cnt[i], false, n+1);
         Free[i] = true;
      }
      For (i, 1, n)
         For (j, i+1, n) {
            if (isEdge(i, j))
               cnt[i][j] = cnt[j][i] = true;
         }
      int ans = 0;
      For (i, 1, n)
         if (Free[i]) {
            Free[i] = false;
            ans = max(ans, DFS(i));
         }
      printf("The largest component contains %d ring", ans);
      if (ans==1) puts(".");
      else puts("s.");
   }
}

/* lamphanviet@gmail.com - 2011 */
