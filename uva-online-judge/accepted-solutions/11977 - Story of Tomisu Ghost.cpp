//*****************
// LAM PHAN VIET **
// UVA 11977 - Story of Tomisu Ghost
// Time limit: 2s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 100001
#define MOD 10000019
typedef unsigned long long ui64;
bool isP[maxN];
vector<int> prime;

void Sieve() {
   memset(isP, true, sizeof(isP));
   isP[0] = isP[1] = false;
   for (int i=2, lm=(int)sqrt(maxN); i<=lm; i++)
      if (isP[i]) {
         for (int j=i*i; j<maxN; j+=i)
            isP[j] = false;
      }
   for (int i=2; i<maxN; i++)
      if (isP[i]) prime.push_back(i);
}

int SoMu(int n, int p) {
   int kq = 0;
   for (int i=p; i<=n; i*=p)
      kq += (n/i);
   return kq;
}

ui64 Power(int n, int mu) {
   if (mu==1) return n;
   ui64 tmp = Power(n, mu/2);
   tmp = (tmp*tmp)%MOD;
   if (mu%2) return (tmp*n)%MOD;
   return tmp;
}

void Solve(int n, int t) {
   ui64 ans = 1;
   bool f = false;
   for (int i=0; i<prime.size() && prime[i]<=n; i++) {
      int somu = SoMu(n, prime[i]);
      if (somu>=t) {
         int k = somu/t;
         ans *= Power(prime[i], k);
         ans %= MOD;
         f = true;
      }
   }
   if (f) printf("%lld\n", ans);
   else puts("-1");
}

main() {
//   freopen("aa.inp", "r", stdin); freopen("aa.out", "w", stdout);
   Sieve();
   int Case, n, t;
   scanf("%d", &Case);
   For (kk, 1, Case) {
      scanf("%d %d", &n, &t);
      printf("Case %d: ", kk);
      Solve(n, t);
   }
}

/* lamphanviet@gmail.com - 2011 */
