//*****************
// LAM PHAN VIET **
// UVA 11991 - Easy Problem from Rujia Liu
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 100001
vector<int> VectorInt;
vector< vector<int> > ans;
map<int, int> Index;

main() {
 //  freopen("ee.inp", "r", stdin); freopen("ee.out", "w", stdout);
   int n, m, val, k, idx;
   while (scanf("%d %d", &n, &m)!=EOF) {
      ans.clear(); Index.clear(); idx = 0; ans.push_back(VectorInt);
      For (i, 1, n) {
         scanf("%d", &val);
         int u = Index[val];
         if (u==0) {
            u = Index[val] = ++idx;
            ans.push_back(VectorInt);
         }
         ans[u].push_back(i);
      }
      while (m--) {
         scanf("%d %d", &k, &val);
         int u = Index[val];
         if (u==0 || ans[u].size()<k) puts("0");
         else printf("%d\n", ans[u][k-1]);
      }
   }
}

/* lamphanviet@gmail.com - 2011 */
