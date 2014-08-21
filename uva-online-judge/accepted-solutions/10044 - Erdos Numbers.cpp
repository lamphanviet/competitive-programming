//*****************
// LAM PHAN VIET **
// UVA 10044 - Erdos Numbers
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define KeyName "Erdos, P."
#define INF 1000000
int n;
vector<int> VectorInt;
vector< vector<int> > adj;
vector<string> name;
map<string, int> Index;

void ReadInput(int m) {
   name.clear(); name.push_back(KeyName);
   adj.clear(); adj.push_back(VectorInt);
   Index.clear(); Index[KeyName] = 1;
   n = 1;
   char s[10000]; string nm;
   gets(s);
   while (m--) {
      gets(s);
      int len = strlen(s), k = 0;
      vector<int> list;
      while (k<len) {
         nm = "";
         while (k<len && s[k]==' ') k++;
         if (k>=len) break;
         while (s[k]!=',') nm += s[k++];
         nm += s[k++];
         while (s[k]!=',' && s[k]!=':') nm += s[k++];
         
         int u = Index[nm];
         if (u==0) {
            u = Index[nm] = ++n;
            adj.push_back(VectorInt);
            name.push_back(nm);
         }
         list.push_back(u-1);
         if (k>=len || s[k]==':') break;
         k++;
      }
      For (i, 0, list.size()-1)
         For (j, i+1, list.size()-1) {
            adj[list[i]].push_back(list[j]);
            adj[list[j]].push_back(list[i]); 
         }
   }
}

void SolveBFS(int u) {
   if (u==-1) {
      puts("infinity"); return;
   }
   vector<int> d(name.size(), INF);
   d[u] = 0;
   queue<int> Q; Q.push(u);
   while (!Q.empty()) {
      u = Q.front(); Q.pop();
      for (int i=0; i<adj[u].size(); i++) {
         int v = adj[u][i];
         if (d[v]==INF) {
            d[v] = d[u]+1;
            if (v==0) { // == Erdos
               printf("%d\n", d[v]); return;
            }
            Q.push(v);
         }
      }
   }
   puts("infinity");
}

main() {
//   freopen("044.inp", "r", stdin); freopen("044.out", "w", stdout);
   int Case, m1, m2;
   char s[100];
   scanf("%d", &Case);
   For (kk, 1, Case) {
      scanf("%d %d", &m1, &m2);
      ReadInput(m1);
      printf("Scenario %d\n", kk);
      while (m2--) {
         gets(s);
         printf("%s ", s);
         SolveBFS(Index[s]-1);
      }
   }
}

/* lamphanviet@gmail.com - 2011 */
