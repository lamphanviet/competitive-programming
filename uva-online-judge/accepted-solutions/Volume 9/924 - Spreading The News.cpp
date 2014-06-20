//*****************
// LAM PHAN VIET **
// UVA 924 - Spreading The News
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
#define INF 5000
#define maxN 2505
int n, d[maxN], maxsize, firstday;
vector<int> adj[maxN];

void ReadInput() {
   int m, v;
   scanf("%d", &n);
   For (i, 0, n-1) {
      scanf("%d", &m);
      while (m--) {
         scanf("%d", &v);
         adj[i].push_back(v);
      }
   }
}

void BFS(int u) {
   For (i, 0, n) d[i] = INF;
   queue<int> Queue;
   Queue.push(u); d[u] = 0;
   while (!Queue.empty()) {
      u = Queue.front(); Queue.pop();
      for (int i=0; i<adj[u].size(); i++) {
         int v = adj[u][i];
         if (d[v]==INF) {
            d[v] = d[u]+1;
            Queue.push(v);
         }
      }
   }
}

main() {
//   freopen("924.inp", "r", stdin); freopen("924.out", "w", stdout);
   int m, u;
   ReadInput();
   scanf("%d", &m);
   while (m--) {
      scanf("%d", &u);
      if (adj[u].size()>0) {
         BFS(u);
         maxsize = 0; firstday = -1;
         sort(d, d+n);
         int len = 1;
         For (i, 1, n)
            if (d[i-1]==d[i]) len++;
            else {
               if (d[i-1]!=INF && len>maxsize) {
                  maxsize = len;
                  firstday = d[i-1];
               }
               len = 1;
            }
         if (firstday==0) firstday++;
         printf("%d %d\n", maxsize, firstday);
      }
      else puts("0");
   }
}

/* lamphanviet@gmail.com - 2011 */
