//*****************
// LAM PHAN VIET **
// UVA 10311 - Goldbach and Euler
// Time limit: 10.000s
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
#define maxN 100000001
using namespace std;

bool isP[maxN];
vector<int> prime;
int n, x;

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

bool Check() {
    if (n%2) {
        x = 2;
        return isP[n-x];
    }
    int p = int(upper_bound(all(prime), n/2) - prime.begin());
    for (; p>=0; p--)
        if (isP[n-prime[p]]) {
            if (prime[p] == n - prime[p]) continue;
            x = min(prime[p], n-prime[p]);
            return true;
        }
    return false;
}

main() {
//    FileIn("test"); FileOut("test");
    Sieve();
    while (scanf("%d", &n)!=EOF) {
        if (Check()) printf("%d is the sum of %d and %d.\n", n, x, n-x);
        else printf("%d is not the sum of two primes!\n", n);
    }
}

/* lamphanviet@gmail.com - 2011 */
