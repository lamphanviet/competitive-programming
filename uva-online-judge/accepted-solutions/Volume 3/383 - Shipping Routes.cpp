//*****************
// LAM PHAN VIET **
// UVA 383 - Shipping Routes
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <string>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 32
#define INF 50
int n, d[maxN];
bool a[maxN][maxN];
char name[maxN][3];
map<string, int> Index;

void Solve(int s, int f, int mul) {
   For (i, 1, n) d[i] = INF;
   d[s] = 0;
   queue<int> Q;
   Q.push(s);
   while (!Q.empty()) {
      int u = Q.front(); Q.pop();
      For (v, 1, n)
         if (a[u][v] && d[v]==INF) {
            d[v] = d[u]+1;
            if (v==f) {
               printf("$%d\n", d[v]*mul*100);
               return;
            }
            Q.push(v);
         }
   }
   puts("NO SHIPMENT POSSIBLE");
}

main() {
 //  freopen("383.inp", "r", stdin); freopen("383.out", "w", stdout);
   int Case, m, q, u, v;
   char s1[3], s2[3];
   scanf("%d", &Case);
   puts("SHIPPING ROUTES OUTPUT");
   For (kk, 1, Case) {
      scanf("%d %d %d", &n, &m, &q);
      Index.clear();
      getchar();
      For (i, 1, n) {
         scanf("%s", &name[i]);
         Index[name[i]] = i;
         memset(a[i], false, n+1);
         a[i][i] = true;
      }
      while (m--) {
         scanf("%s %s", &s1, &s2);
         u = Index[s1]; v = Index[s2];
         a[u][v] = a[v][u] = true;
      }
      printf("\nDATA SET  %d\n\n", kk);
      while (q--) {
         scanf("%d %s %s", &m, &s1, &s2);
         u = Index[s1]; v = Index[s2];
         Solve(u, v, m);
      }
   }
   puts("\nEND OF OUTPUT");
}

/* lamphanviet@gmail.com - 2011 */
