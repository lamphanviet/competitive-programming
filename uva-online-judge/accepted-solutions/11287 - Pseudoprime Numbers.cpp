//*****************
// LAM PHAN VIET **
// UVA 11287 - Pseudoprime Numbers
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
#define maxN 31623
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

bool isPrime(int n) {
    if (n<maxN) return isP[n];
    int nn = (int)sqrt(n);
    for (int i=0; i<prime.size() && prime[i]<=nn; i++)
        if (n%prime[i]==0) return false;
    return true;
}

int64 Mod(int64 a, int k, int p) {
    if (k==1) return a%p;
    int64 tmp = Mod(a, k/2, p);
    tmp = (tmp*tmp) % p;
    if (k%2) return (tmp*a)%p;
    return tmp;
}

main() {
 //   FileIn("test"); FileOut("test");
    Sieve();
    int a, p;
    bool f;
    while (scanf("%d %d", &p, &a) && (p || a)) {
        if (isPrime(p)) f = false;
        else f = (Mod(a, p, p)==a);
        if (f) puts("yes");
        else puts("no");
    }
}

/* lamphanviet@gmail.com - 2011 */
