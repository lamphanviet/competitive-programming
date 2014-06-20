//*****************
// LAM PHAN VIET **
// UVA 967 - Circular
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

int dp[maxN];
vector<int> prime;
bool isP[maxN], isCP[maxN];

void Sieve() {
    Fill(isP, true);
    isP[0] = isP[1] = false;
    for (int i=4; i<maxN; i+=2) isP[i] = false;
    for (int i=3; i*i<maxN; i+=2)
        if (isP[i])
            for (int j=i*i; j<maxN; j+=i+i)
                isP[j] = false;
    prime.pb(2);
    for (int i=3; i<maxN; i+=2)
        if (isP[i]) prime.pb(i);
}

void Check(int n) {
    int d[10], m = 0;
    vector<int> store;
    store.pb(n);
    while (n) {
        d[m++] = n % 10;
        n /= 10;
    }
    for (int i=m-1; i>=0; i--) {
        n = 0;
        for (int j = i, k = 1; k<=m; j = (j + m-1)%m, k++)
            n = n * 10 + d[j];
        if (!isP[n]) return;
        store.pb(n);
    }
    REP (i, store.size())
        isCP[store[i]] = true;
}

void PreCal() {
    Sieve();
    Fill(isCP, false);
    REP (i, prime.size())
        Check(prime[i]);
        
    dp[0] = 0;
    FOR (i, 1, maxN-1)
        if (isCP[i]) dp[i] = dp[i-1] + 1;
        else dp[i] = dp[i-1];
}

main() {
//    FileIn("test"); FileOut("test");
    int a, b, n;
    PreCal();
    while (scanf("%d", &a) && a!=-1) {
        scanf("%d", &b);
        n = dp[b] - dp[a-1];
        if (n==1) puts("1 Circular Prime.");
        else if (n) printf("%d Circular Primes.\n", n);
        else puts("No Circular Primes.");
    }
}

/* lamphanviet@gmail.com - 2011 */
