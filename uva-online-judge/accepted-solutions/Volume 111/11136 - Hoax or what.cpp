//*****************
// LAM PHAN VIET **
// UVA 11136 - Hoax or what
// Time limit: 3s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 10000
#define ui64 unsigned long long
multiset<int> Set;
multiset<int>::iterator it;

main() {
//   freopen("366.inp", "r", stdin); freopen("366.out", "w", stdout);
   int n, m, val;
   while (scanf("%d", &n) && n) {
      Set.clear();
      ui64 sum = 0;
      while (n--) {
         scanf("%d", &m);
         while (m--) {
            scanf("%d", &val);
            Set.insert(val);
         }
         it = Set.end(); it--;
         int low = *Set.begin(), high = *it;
         sum += high - low;
         Set.erase(Set.begin());
         Set.erase(it);
      }
      printf("%lld\n", sum);
   }
}

/* lamphanviet@gmail.com - 2011 */
