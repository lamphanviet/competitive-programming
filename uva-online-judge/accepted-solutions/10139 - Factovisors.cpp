//*****************
// LAM PHAN VIET **
// UVA 10139 - Factovisors
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 46350
#define ui64 unsigned long long
bool isPrime[maxN];
int prime[4800], np = 0;

void Sieve() {
   memset(isPrime, true, maxN);
   for (int i=2, lm=(int)sqrt(maxN); i<=lm; i++)
      if (isPrime[i])
         for (int j=i*i; j<maxN; j+=i)
            isPrime[j] = false;
   for (int i=2; i<maxN; i++)
      if (isPrime[i]) prime[np++] = i;
}

int ThuaSo(int n, int m) {
   int kq = 0; ui64 k = m;
   while (k<=n) {
      kq += n/k; k *= m;
   }
   return kq;
}

bool Check(int n, int m) {
   if (m<=1 || n<=1) return (m==1);
   if (m<=n) return true;
   int p = 0, a = 0;
   while (m>1 && p<np) {
      if (m%prime[p]==0) {
         a++;
         m /= prime[p];
      }
      else if (a==0) p++;
      else {
         int k = ThuaSo(n, prime[p]);
         if (k<a) return false;
         a = 0; p++;
      }
   }
   if (m==1) return (ThuaSo(n, prime[p])>=a);
   if (m>1) return (ThuaSo(n, m)>=1);
   return true;
}

main() {
   int n, m;
   Sieve();
   while (scanf("%d %d", &n, &m)!=EOF) {
      bool ans = Check(n, m);
      if (ans) printf("%d divides %d!\n", m, n);
      else printf("%d does not divide %d!\n", m, n);
   }
}

/* lamphanviet@gmail.com - 2011 */
