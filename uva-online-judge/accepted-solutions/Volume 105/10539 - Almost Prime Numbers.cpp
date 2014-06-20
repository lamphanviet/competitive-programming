//*****************
// LAM PHAN VIET **
// UVA 10539 - Almost Prime Numbers
// Time limit: 3.000s
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
#define maxN 1000001
using namespace std;

bool isP[maxN];
vector<int> prime;
vector<uint64> alprime;
//vector<uint64>::iterator low, up;

void Sieve() {
    Fill(isP, true);
    isP[0] = isP[1] = false;
    for (int i=4; i<maxN; i+=2) isP[i] = false;
    for (int i=3; i*i<maxN; i+=2)
        if (isP[i]) for (int j=i*i; j<maxN; j+=i+i)
            isP[j] = false;
    prime.pb(2);
    for (int i=3; i<maxN; i+=2)
        if (isP[i]) prime.pb(i);
}

void PreCal() {
    Sieve();
    uint64 Max = (uint64)(maxN-1)*(maxN-1);
    REP (i, prime.size()) {
        uint64 tmp = prime[i], k = prime[i];
        while (tmp*k <= Max) {
            tmp *= k;
            alprime.pb(tmp);
        }
    }
    sort(all(alprime));
    printf("%d\n", alprime.size());
}

main() {
 //   FileIn("test"); FileOut("test");
    PreCal();
    int Case, low, up;
    uint64 n, m;
    for (scanf("%d", &Case); Case--; ) {
        scanf("%lld %lld", &n, &m);
        low = int(lower_bound(all(alprime), n) - alprime.begin());
        up = int(upper_bound(all(alprime), m) - alprime.begin());
        printf("%d\n", up-low);
    }
}

/* lamphanviet@gmail.com - 2011 */
