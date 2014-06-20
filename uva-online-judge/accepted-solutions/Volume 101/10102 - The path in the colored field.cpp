//*****************
// LAM PHAN VIET **
// UVA 10102 - The path in the colored field
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 1001
class Node {
public:
   int x, y;
   Node() {}
   Node(int a, int b) { x=a; y=b; }
};
int n;
char s[maxN][maxN];
int a[maxN][maxN];

bool isOK(int u, int v) {
   return (u>=0 && u<n && v>=0 && v<n);
}

int BFS(int u1, int v1, int k) {
   queue<Node>Queue;
   Queue.push(Node(u1, v1));
   a[u1][v1] = k;
   while (!Queue.empty()) {
      Node nodu = Queue.front(); Queue.pop();
      int u = nodu.x, v = nodu.y;
      if (s[u][v]=='3') return abs(u1-u) + abs(v1-v);
      if (isOK(u-1, v) && a[u-1][v]!=k) {
         a[u-1][v] = k;
         Queue.push(Node(u-1, v));
      }
      if (isOK(u+1, v) && a[u+1][v]!=k) {
         a[u+1][v] = k;
         Queue.push(Node(u+1, v));
      }
      if (isOK(u, v-1) && a[u][v-1]!=k) {
         a[u][v-1] = k;
         Queue.push(Node(u, v-1));
      }
      if (isOK(u, v+1) && a[u][v+1]!=k) {
         a[u][v+1] = k;
         Queue.push(Node(u, v+1));
      }
   }
}

main() {
//   freopen("102.inp", "r", stdin); freopen("102.out", "w", stdout);
   while (scanf("%d", &n)!=EOF) {
      gets(s[0]);
      For (i, 0, n-1) {
         gets(s[i]);
         For (j, 0, n-1) a[i][j] = 0;
      }
      int ans = 0, Count = 0;
      For (i, 0, n-1)
         For (j, 0, n-1)
            if (s[i][j]=='1')
               ans = max(ans, BFS(i, j, ++Count));
      printf("%d\n", ans);
   }
}

/* lamphanviet@gmail.com - 2011 */
