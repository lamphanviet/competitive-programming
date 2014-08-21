//*****************
// LAM PHAN VIET **
// UVA 10009 - All Roads Lead Where?
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 30
#define INF 1000000
int n, c[maxN][maxN], Trace[maxN][maxN];
int Index[100];
char name[maxN];

void ReadInput(int m) {
   For (i, 'A', 'Z') Index[i] = 0;
   For (i, 1, maxN-1) {
      c[i][i] = 0;
      Trace[i][i] = i;
      For (j, i+1, maxN-1) {
         c[i][j] = c[j][i]= INF;
         Trace[i][j] = j;
         Trace[j][i] = i;
      }
   }
   char s1[50], s2[50];
   int u, v;
   gets(s1);
   n = 0;
   while (m--) {
      scanf("%s %s", &s1, &s2);
      u = Index[s1[0]]; v = Index[s2[0]];
      if (u==0) {
         u = Index[s1[0]] = ++n;
         name[u] = s1[0];
      }
      if (v==0) {
         v = Index[s2[0]] = ++n;
         name[v] = s2[0];
      }
      c[u][v] = c[v][u] = 1;
   }
}

void Floyd() {
   For (k, 1, n)
      For (u, 1, n)
         For (v, 1, n) {
            int cost = c[u][k]+c[k][v];
            if (cost<c[u][v]) {
               c[u][v] = cost;
               Trace[u][v] = Trace[u][k];
            }
         }
}

void Solve(int u, int v) {
   printf("%c", name[u]);
   while (u!=v) {
      u = Trace[u][v];
      printf("%c", name[u]);
   }
   printf("\n");
}

main() {
//   freopen("009.inp", "r", stdin); freopen("009.out", "w", stdout);
   int Case, m, q, u, v;
   scanf("%d", &Case);
   while (Case--) {
      scanf("%d %d", &m, &q);
      ReadInput(m);
      Floyd();
      char s1[50], s2[50];
      while (q--) {
         scanf("%s %s", &s1, &s2);
         u = Index[s1[0]]; v = Index[s2[0]];
         Solve(u, v);
      }
      if (Case) printf("\n");
   }
}

/* lamphanviet@gmail.com - 2011 */
