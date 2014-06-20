//*****************
// LAM PHAN VIET **
// UVA 12039 - Goldbach's Cardinality
// Time limit: 5.000s
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
#define Last(i) (i & -i)
#define INF 500000000
#define maxN 10000001
using namespace std;

int np, dp[maxN];
bool isP[maxN];
vector<int> prime;

void Sieve() {
    Fill(isP, true);
    isP[0] = isP[1] = false;
    for (int i=4; i<maxN; i+=2) isP[i] = false;
    for (int i=3; i*i<maxN; i+=2)
        if (isP[i]) for (int j=i*i; j<maxN; j+=i+i)
            isP[j] = false;
    for (int i=3; i<maxN; i+=2)
        if (isP[i]) prime.pb(i);
    np = prime.size();
    
    dp[0] = dp[1] = dp[2] = 0;
    FOR (i, 3, maxN-1)
        if (isP[i]) dp[i] = dp[i-1] + 1;
        else dp[i] = dp[i-1];
}

int Search(int x, int R) {
    int L = 0, rs = 0;
    while (L<=R) {
        int mid = (L+R)/2;
        if (prime[mid]<=x) {
            rs = mid;
            L = mid + 1;
        }
        else R = mid - 1;
    }
    if (prime[rs]<=x) return rs + 1;
    return 0;
}

uint64 Cal(int n) {
    uint64 rs = 0;
    for (int i=0; i<np && prime[i]<=n; i++) {
//        rs += Search(min(n-prime[i], prime[i]), i);
        rs += dp[ min(n-prime[i], prime[i]) ];
        if (prime[i] + prime[i] <= n) rs--;
    }
    return rs;
}

main() {
//    FileIn("test"); FileOut("test");
    Sieve();
    int n, m;
    while (scanf("%d %d", &n, &m) && (n || m)) {
        uint64 rs = Cal(m) - Cal(n-1);
//        printf("%lld %lld\n", Cal(m), Cal(n-1));
        printf("%lld\n", rs);
    }
}

/* lamphanviet@gmail.com - 2011 */
