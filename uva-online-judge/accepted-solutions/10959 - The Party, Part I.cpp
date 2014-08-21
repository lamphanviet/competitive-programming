//*****************
// LAM PHAN VIET **
// UVA 10959 - The Party, Part I
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 1001
#define INF 1000000
int n, d[maxN];
vector<int> adj[maxN];

void BFS() {
   queue<int> Q;
   Q.push(0);
   d[0] = 0;
   while (!Q.empty()) {
      int u = Q.front(); Q.pop();
      for (int i=0; i<adj[u].size(); i++) {
         int v = adj[u][i];
         if (d[v]==INF) {
            d[v] = d[u]+1;
            Q.push(v);
         }
      }
   }
}

main() {
//   freopen("959.inp", "r", stdin); freopen("959.out", "w", stdout);
   int Case, m , u, v;
   scanf("%d", &Case);
   while (Case--) {
      scanf("%d %d", &n, &m);
      For (i, 0, n-1) {
         adj[i].clear();
         d[i] = INF;
      }
      while (m--) {
         scanf("%d %d", &u, &v);
         adj[u].push_back(v);
         adj[v].push_back(u);
      }
      BFS();
      For (i, 1, n-1)
         printf("%d\n", d[i]);
      if (Case) printf("\n");
   }
}

/* lamphanviet@gmail.com - 2011 */
