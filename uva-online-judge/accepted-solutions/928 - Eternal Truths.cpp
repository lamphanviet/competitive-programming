//*****************
// LAM PHAN VIET **
// UVA 928 - Eternal Truths
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 301
#define INF 1000000000
class Node {
public:
   int x, y, k;
   Node() { x=y=0; k=3; }
   Node(int i, int j, int kk=1) {
      x = i; y = j; k = kk;
   }
};
int n, m;
int d[maxN][maxN][4];
Node Start, End;
char s[maxN][maxN];

bool isOK(int i, int j) {
   return (i>=0 && i<n && j>=0 && j<m);
}

void BFS() {
   d[Start.x][Start.y][1] = 0;
   queue<Node> Q; Q.push(Start);
   while (!Q.empty()) {
      Node u = Q.front(); Q.pop();
      int i, j; bool ok;
      // Down
      i = u.x; j = u.y; ok = true;
      for (int t=1; t<=u.k && ok; t++)
         if (!isOK(i+t, j) || s[i+t][j]=='#') ok = false;
      if (ok && d[i][j][u.k]+1<d[i+u.k][j][(u.k%3)+1]) {
         int t = (u.k%3)+1;
         d[i+u.k][j][t] = d[i][j][u.k]+1;
         Q.push(Node(i+u.k, j, t));
      }
      // Up
      i = u.x; j = u.y; ok = true;
      for (int t=1; t<=u.k && ok; t++)
         if (!isOK(i-t, j) || s[i-t][j]=='#') ok = false;
      if (ok && d[i][j][u.k]+1<d[i-u.k][j][(u.k%3)+1]) {
         int t = (u.k%3)+1;
         d[i-u.k][j][t] = d[i][j][u.k]+1;
         Q.push(Node(i-u.k, j, t));
      }
      // Right
      i = u.x; j = u.y; ok = true;
      for (int t=1; t<=u.k && ok; t++)
         if (!isOK(i, j+t) || s[i][j+t]=='#') ok = false;
      if (ok && d[i][j][u.k]+1<d[i][j+u.k][(u.k%3)+1]) {
         int t = (u.k%3)+1;
         d[i][j+u.k][t] = d[i][j][u.k]+1;
         Q.push(Node(i, j+u.k, t));
      }
      // Left
      i = u.x; j = u.y; ok = true;
      for (int t=1; t<=u.k && ok; t++)
         if (!isOK(i, j-t) || s[i][j-t]=='#') ok = false;
      if (ok && d[i][j][u.k]+1<d[i][j-u.k][(u.k%3)+1]) {
         int t = (u.k%3)+1;
         d[i][j-u.k][t] = d[i][j][u.k]+1;
         Q.push(Node(i, j-u.k, t));
      }
   }
}

main() {
//   freopen("928.inp", "r", stdin); freopen("928.out", "w", stdout);
   int Case;
   scanf("%d", &Case);
   while (Case--) {
      scanf("%d %d", &n, &m); gets(s[0]);
      For (i, 0, n-1) {
         gets(s[i]);
         For (j, 0, m-1) {
            d[i][j][1] = d[i][j][2] = d[i][j][3] = INF;
            if (s[i][j]=='S') Start = Node(i, j, 1);
            else if (s[i][j]=='E') End = Node(i, j, 1);
         }
      }
      BFS();
      int ans = INF;
      For (i, 1, 3)
         ans = min(ans, d[End.x][End.y][i]);
      if (ans==INF) puts("NO");
      else printf("%d\n", ans);
   }
}

/* lamphanviet@gmail.com - 2011 */
