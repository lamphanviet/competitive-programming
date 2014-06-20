//*****************
// LAM PHAN VIET **
// UVA 11984 - A Change in Thermal Unit
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 10000

main() {
   int Case;
   double c, d;
   scanf("%d", &Case);
   for (int kk=1; kk<=Case; kk++) {
      scanf("%lf %lf", &c, &d);
      c = 9.0*c/5.0 + 32;
      c += d;
      c = (c-32.0)*5.0/9.0;
      printf("Case %d: %.2lf\n", kk, c);
   }
}

/* lamphanviet@gmail.com - 2011 */
