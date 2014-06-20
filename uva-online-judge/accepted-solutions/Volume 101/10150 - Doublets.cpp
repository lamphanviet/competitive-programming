//*****************
// LAM PHAN VIET **
// UVA 10150 - Doublets
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <queue>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 25145
int d[maxN], Trace[maxN], n;
char name[maxN][17];
int len[maxN];
vector<int> adj[maxN];
map<string, int> Index;

bool isDoublet(char *s1, int n1, char *s2, int n2) {
   if (n1!=n2) return false;
   int Count = 0;
   For (i, 0, n1-1)
       if (s1[i]!=s2[i]) {
            if (++Count>1) return false;
         }
   return true;
}

void ReadDictionary() {
   For (i, 1, maxN-1) d[i] = 0;
   n = 0;
   while (gets(name[n+1]) && strlen(name[n+1])!=0) {
 //     if (Index[name[n+1]]!=0) continue;
      n++;
      Index[name[n]] = n;
      len[n] = strlen(name[n]);
      For (i, 1, n-1)
         if (isDoublet(name[i], len[i], name[n], len[n])) {
            adj[i].push_back(n);
            adj[n].push_back(i);
         }
   }
}

void Result(int s, int f, bool solved) {
   if (!solved) {
      puts("No solution."); return;
   }
   puts(name[f]);
   while (f!=s) {
      f = Trace[f];
      puts(name[f]);
   }
}

void Solve_BFS(int s, int f, int k) {
   queue<int> Queue;
   Queue.push(s);// d[s] = k;
   bool found = false;
   while (!Queue.empty() && !found) {
      int u = Queue.front(); Queue.pop();
      for (int i=0; i<adj[u].size() && !found; i++) {
         int v = adj[u][i];
         if (d[v]!=k) {
            d[v] = k;
            Trace[v] = u;
            Queue.push(v);
            if (v==f) found = true;
         }
      }
   }
   if (d[f]==k) Result(s, f, true);
   else Result(s, f, false);
}

main() {
//   freopen("150.inp", "r", stdin); freopen("150.out", "w", stdout);
   char s1[17], s2[17];
   int u, v, Count=0;
   ReadDictionary();
   while (scanf("%s %s", &s1, &s2)!=EOF) {
      if (Count++) printf("\n");
      if (strlen(s1)!=strlen(s2)) {
         Result(1, 1, false); continue;
      }
      u = Index[s1]; v = Index[s2];
      if (!u || !v) Result(1, 1, false);
      else Solve_BFS(v, u, Count);
   }
}

/* lamphanviet@gmail.com - 2011 */
