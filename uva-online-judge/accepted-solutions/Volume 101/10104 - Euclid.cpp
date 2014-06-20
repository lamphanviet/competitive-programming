//*****************
// LAM PHAN VIET **
// UVA 10104 - Euclid
// Time limit:
//********************************
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

long gcd(long p,long q, long *x, long *y)
{
     long x1,y1;
     long g;
     
     if (q>p) return (gcd(q,p,y,x));
     
     if (q==0) {
        *x=1;
        *y=0;
        return p;
     }
     
     g=gcd(q, p%q, &x1,&y1);
     
     *x = y1;
     *y = (x1 - (long)floor(p/q)*y1);
     
     return g;
}

int main()
{
      long p,q,x,y,m;
      while (scanf("%ld %ld",&p,&q)==2)
      {
            m=gcd(p,q,&x,&y);
            printf("%d %d %d\n",x,y,m);
      }
      return 0;
}
