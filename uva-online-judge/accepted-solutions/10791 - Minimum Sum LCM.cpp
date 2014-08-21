/*****************/
/* LAM PHAN VIET */
/* UVA 10791 - Minimum Sum LCM
/* Time limit: 3.000s
/********************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 46350
using namespace std;

bitset<maxN> isP;
vector<int> prime;

void sieve() {
    isP.set();
    isP.reset(0); isP.reset(1);
    for (int i = 4; i < maxN; i += 2)
        isP.reset(i);
    for (int i = 3; i * i < maxN; i += 2)
        if (isP[i])
            for (int j = i * i; j < maxN; j += i + i)
                isP.reset(j);
    prime.pb(2);
    for (int i = 3; i < maxN; i += 2)
        if (isP[i]) prime.pb(i);
}

int64 solve(int n) {
    if (n == 1) return 2;
    if (n < maxN && isP[n])
        return n + 1;
    
    int nn = n, p = 0, fact = 0;
    int64 sum = 0;
    while (p < prime.size() && nn != 1) {
        if (nn % prime[p] == 0) {
            int64 tmp = 1;
            while (nn % prime[p] == 0) {
                tmp *= prime[p];
                nn /= prime[p];
            }
            sum += tmp;
            fact++;
        }
        p++;
    }
    if (nn != 1) {
        sum += nn;
        fact++;
    }
    if (fact == 1) sum++;
    return sum;
}

main() {
//    FileIn("test"); FileOut("test");
    sieve();
    int Case = 0, n;
    while (scanf("%d", &n) && n) {
        printf("Case %d: %lld\n", ++Case, solve(n));
    }
}

/* lamphanviet@gmail.com - 2011 */
