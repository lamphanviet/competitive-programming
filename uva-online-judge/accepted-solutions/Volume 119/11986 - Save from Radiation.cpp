//*****************
// LAM PHAN VIET **
// UVA 11986 - Save from Radiation
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 10000
typedef unsigned long long ULL;
ULL pow2[60];

main() {
   pow2[0] = 1;
   For (i, 1, 59) pow2[i] = pow2[i-1]*2;
   int Case, ans;
   ULL n;
   scanf("%d", &Case);
   For (kk, 1, Case) {
      scanf("%lld", &n); n++;
      ans = 0;
      for (ans=0; ans<60; ans++)
         if (pow2[ans]>=n) break;
      printf("Case %d: %d\n", kk, ans);
   }
}

/* lamphanviet@gmail.com - 2011 */
