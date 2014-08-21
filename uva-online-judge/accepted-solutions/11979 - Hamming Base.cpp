//*****************
// LAM PHAN VIET **
// UVA 11979 - Hamming Base
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 2002
int a[12][maxN], n, m;
bool Free[maxN];

main() {
//   freopen("cc.inp", "r", stdin); freopen("cc.out", "w", stdout);
   int Case;
   scanf("%d", &Case);
   For (kk, 1, Case) {
      scanf("%d %d", &n, &m);
      For (i, 1, n)
         For (j, 1, m)
            scanf("%d", &a[j][i]);
            
      int ans = 0;
      For (k, 1, m) {
         sort(a[k]+1, a[k]+n+1);
         For (i, 1, n)
            ans += abs(a[k][i]-i+1);
      }
      
      printf("Case %d: %d\n", kk, ans);
   }
}

/* lamphanviet@gmail.com - 2011 */
