//*****************
// LAM PHAN VIET **
// UVA 10067 - Playing with Wheels
// Time limit: 5s
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
#define maxN 10000
int change[8][4] = {{1,0,0,0},{-1,0,0,0},{0,1,0,0},{0,-1,0,0},{0,0,1,0},{0,0,-1,0},{0,0,0,1},{0,0,0,-1}};
string Start, End;
map<string, int> Index;

int BFS() {
   if (Start==End) return 0;
   if (Index[End]==-1) return -1;
   queue<string> Q;
   queue<int> Qidx;
   Q.push(Start); Qidx.push(1);
   while (!Q.empty()) {
      string u = Q.front(); Q.pop();
      int idxu = Qidx.front(); Qidx.pop();
      For (k, 0, 7) {
         string v = u;
         for (int i=0; i<4; i++) {
            v[i] += change[k][i];
            if (v[i]<'0') v[i] = '9';
            else if (v[i]>'9') v[i] = '0';
         }
         int idx = Index[v];
         if (idx!=0) continue;
         if (v==End) return idxu;
         idx = Index[v] = idxu + 1;
         Q.push(v); Qidx.push(idx);
      }
   }
   return -1;
}

main() {
//   freopen("067.inp", "r", stdin); freopen("067.out", "w", stdout);
   int Case, val, m;
   scanf("%d", &Case);
   while (Case--) {
      Start = End = ""; Index.clear();
      For (i, 1, 4) {
         scanf("%d", &val); Start += val+48;
      }
      For (i, 1, 4) {
         scanf("%d", &val); End += val+48;
      }
      scanf("%d", &m);
      while (m--) {
         string tmp = "";
         For (i, 1, 4) {
            scanf("%d", &val); tmp += val+48;
         }
         Index[tmp] = -1;
      }
      Index[Start]=1;
      printf("%d\n", BFS());
   }
}

/* lamphanviet@gmail.com - 2011 */
