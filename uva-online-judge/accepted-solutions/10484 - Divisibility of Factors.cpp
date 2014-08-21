/*****************/
/* LAM PHAN VIET */
/* UVA 10484 - Divisibility of Factors
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
#define maxN 105
using namespace std;

bitset<maxN> isP;
vector<int> prime;
int number[30], n, m;

void sieve() {
    isP.set();
    for (int i = 3; i * i < maxN; i += 2)
        if (isP[i])
            for (int j = i * i; j < maxN; j += i + i)
                isP.reset(j);
    prime.pb(2);
    for (int i = 3; i < maxN; i += 2)
        if (isP[i]) prime.pb(i);
}

int cal(int n, int k) {
    int res = 0, kk = k;
    while (kk <= n) {
        res += n / kk;
        kk *= k;
    }
    return res;
}

int64 solve() {
    if (n == 0)
        return (m == 1)? 1: 0;
    int p = 0;
    while (prime[p] <= n) {
        number[p] = cal(n, prime[p]);
        p++;
    }

    int p2 = 0;
    while (p2 < prime.size() && m != 1) {
        if (m % prime[p2] == 0) {
            while (m % prime[p2] == 0) {
                m /= prime[p2];
                number[p2]--;
                if (number[p2] < 0) return 0;
            }
        }
        p2++;
    }
    
    if (m != 1) return 0;
    int64 res = 1;
    REP(i, 25)
        if (number[i])
            res *= (number[i] + 1);
    return res;
}

main() {
//    FileIn("test"); FileOut("test");
    sieve();
    while (scanf("%d %d", &n, &m) && (n || m)) {
        REP(i, 25) number[i] = 0;
        m = abs(m);
        printf("%lld\n", solve());
    }
}

/* lamphanviet@gmail.com - 2011 */
