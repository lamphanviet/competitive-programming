//*****************
// LAM PHAN VIET **
// UVA 11749 - Poor Trade Advisor
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 501
#define INF -2147483648
class Node {
public:
   int p, w;
   Node(int pp, int ww) { p=pp; w=ww; }
};
int n, Max;
vector<Node> adj[maxN];
bool Free[maxN];

int DFS(int u) {
   int Count = 1;
   for (int i=0, size=adj[u].size(); i<size; i++) {
      int v = adj[u][i].p, w = adj[u][i].w;
      if (!Free[v] || w!=Max) continue;
      Free[v] = false;
      Count += DFS(v);
   }
   return Count;
}

main() {
 //  freopen("749.inp", "r", stdin); freopen("749.out", "w", stdout);
   int m, u, v, w;
   while (scanf("%d %d", &n, &m) && (n || m)) {
      For (i, 1, n) {
         adj[i].clear(); Free[i] = true;
      }
      Max = INF;
      while (m--) {
         scanf("%d %d %d", &u, &v, &w);
         adj[u].push_back(Node(v, w));
         adj[v].push_back(Node(u, w));
         Max = max(Max, w);
      }
      int ans = 0;
      For (i, 1, n)
         if (Free[i]) {
            Free[i] = false;
            ans = max(ans, DFS(i));
         }
      printf("%d\n", ans);
   }
}

/* lamphanviet@gmail.com - 2011 */
