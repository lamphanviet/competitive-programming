//*****************
// LAM PHAN VIET **
// UVA 762 - We Ship Cheap
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <queue>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define INF 1000000000
int n;
vector<int> NewVector;
vector< vector<int> > adj;
vector<string> name;
map<string, int> Index;

void ReadInput(int m) {
   char s1[5], s2[5];
   int u, v;
   Index.clear();
   adj.clear(); adj.push_back(NewVector);
   name.clear(); name.push_back("Accepted!");
   
   n = 0;
   gets(s1);
   while (m--) {
      scanf("%s %s", &s1, &s2);
      u = Index[s1]; v = Index[s2];
      if (u==0) {
         u = Index[s1] = ++n;
         name.push_back(s1);
         adj.push_back(NewVector);
      }
      if (v==0) {
         v = Index[s2] = ++n;
         name.push_back(s2);
         adj.push_back(NewVector);
      }
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
}

void Solve_BFS(int s, int f) {
   if (!s || !f) {
      puts("No route");
      return;
   }
   int d[n+1], Trace[n+1], u, v;
   For (i, 1, n) d[i] = INF;
   queue<int> Queue;
   Queue.push(s);
   d[s] = 0;
   while (!Queue.empty()) {
      u = Queue.front(); Queue.pop();
      if (u==f) break;
      for (int i=0; i<adj[u].size(); i++) {
         v = adj[u][i];
         if (d[v]==INF) {
            Queue.push(v);
            d[v] = d[u]+1;
            Trace[v] = u;
            if (v==f) break;
         }
      }
   }
   
   if (d[f]==INF) {
      puts("No route");
      return;
   }
   
   u = Trace[f];
   while (f!=s) {
      cout << name[f] << " " << name[u] << endl;
      f = u;
      u = Trace[u];
   }
}

main() {
//   freopen("762.inp", "r", stdin); freopen("762.out", "w", stdout);
   int m, u, v;
   bool Line = false;
   while (scanf("%d", &m)!=EOF) {
      ReadInput(m);
      char s1[5], s2[5];
      scanf("%s %s", &s1, &s2);
      u = Index[s1]; v = Index[s2];
      if (Line) printf("\n"); Line = true;
      Solve_BFS(v, u);
   }
}

/* lamphanviet@gmail.com - 2011 */
