//*****************
// LAM PHAN VIET **
// UVA 10780 - Again Prime? No Time.
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <bitset>
#include <cmath>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 5001
#define INF 2000000000
vector<int> prime;
bool isPrime[maxN];

void Sieve() {
   memset(isPrime, true, maxN);
   isPrime[0] = isPrime[1] = false;
   for (int i=2, lm=(int)sqrt(maxN); i<=lm; i++)
      if (isPrime[i]) for (int j=i*i; j<maxN; j+=i)
         isPrime[j] = false;
   For (i, 2, maxN-1)
      if (isPrime[i]) prime.push_back(i);
}

int SoMu(int k, int n) {
   int kq = 0, x = k;
   while (x<=n) {
      kq += n/x;
      x *= k;
   }
   return kq;
}

int Solve(int n, int m) {
   int p = 0, ans = INF;
   while (m>1) {
      if (m%prime[p]==0) {
         int sm = 0;
         while (m%prime[p]==0) {
            sm++;
            m /= prime[p];
         }
         int k = SoMu(prime[p], n);
         if (k<sm) return -1;
         ans = min(ans, k/sm);
      }
      p++;
   }
   if (ans==INF) return -1;
   return ans;
}

main() {
   Sieve();
   int Case, m, n;
   scanf("%d", &Case);
   For (kk, 1, Case) {
      scanf("%d %d", &m, &n);
      int ans = Solve(n, m);
      printf("Case %d:\n", kk);
      if (ans>0) printf("%d\n", ans);
      else puts("Impossible to divide");
   }
}

/* lamphanviet@gmail.com - 2011 */
