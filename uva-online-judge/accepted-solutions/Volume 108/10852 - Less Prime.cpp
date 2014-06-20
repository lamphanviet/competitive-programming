//*****************
// LAM PHAN VIET **
// UVA 10852 - Less Prime
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
#define maxN 10001
using namespace std;

bool isP[maxN];
vector<int> prime;

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

int Solve(int n) {
    int dif = 0, m;
    for (int i=0; i<prime.size() && prime[i]<=n; i++) {
        int p = n/prime[i];
        if (n - prime[i]*p > dif) {
            dif = n - prime[i]*p;
            m = prime[i];
        }
    }
    return m;
}

main() {
 //   FileIn("test"); FileOut("test");
    Sieve();
    int Case, n;
    for (scanf("%d", &Case); Case--; ) {
        scanf("%d", &n);
        printf("%d\n", Solve(n));
    }
}

/* lamphanviet@gmail.com - 2011 */
