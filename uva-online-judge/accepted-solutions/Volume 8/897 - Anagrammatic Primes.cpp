//*****************
// LAM PHAN VIET **
// UVA 897 - Anagrammatic Primes
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
#define maxN 1001
using namespace std;

bool isP[maxN];
vector<int> prime, anaprime;

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

bool isAnaPrime(int n) {
    vector<int> a;
    while (n) {
        a.pb(n%10); n /= 10;
    }
    sort (all(a));
    int m = a.size();
    do {
        n = 0;
        REP (i, m) n = n*10 + a[i];
        if (!isP[n]) return false;
    } while (next_permutation(all(a)));
    return true;
}

bool PreCal() {
    Sieve();
    REP (i, prime.size())
        if (isAnaPrime(prime[i])) anaprime.pb(prime[i]);
}

int Num(int n) {
    int k = 0;
    while (n) {
        n /= 10; k++;
    }
    return k;
}

main() {
 //   FileIn("test"); FileOut("test");
    PreCal();
    int n;
    while (scanf("%d", &n) && n) {
        int ans = 0;
        if (n<maxN) {
            REP (i, anaprime.size())
                if (anaprime[i]>n) {
                    ans = anaprime[i];
                    break;
                }
            if (ans && Num(ans) > Num(n)) ans = 0;
        }
        printf("%d\n", ans);
    }
}

/* lamphanviet@gmail.com - 2011 */
