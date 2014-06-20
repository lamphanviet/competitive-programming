//*****************
// LAM PHAN VIET **
// UVA 530 - Binomial Showdown
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
#define maxN 10000
using namespace std;

uint64 GCD(uint64 m, uint64 n) {
    uint64 r = m%n;
    while (r) {
        m = n; n = r;
        r = m%n;
    }
    return n;
}

void Solve(int n, int k) {
    uint64 i = k + 1, j = 1, gcd;
    uint64 tu = 1, mau = 1;
    while (i<=n && j<=n-k) {
        tu *= i; mau *= j;
        gcd = GCD(tu, mau);
        tu /= gcd; mau /= gcd;
        i++; j++;
    }
    while (i<=n) {
        tu *= i;
        gcd = GCD(tu, mau);
        tu /= gcd; mau /= gcd;
        i++;;
    }
    while (j<=n-k) {
        mau *= j;
        gcd = GCD(tu, mau);
        tu /= gcd; mau /= gcd;
        j++;
    }
    printf("%lld\n", tu/mau);
}

main() {
//    FileIn("test"); FileOut("test");
    int n, k;
    while (scanf("%d %d", &n, &k) && (n || k)) {
        if (k > n-k) Solve(n, k);
        else Solve(n, n-k);
    }
}

/* lamphanviet@gmail.com - 2011 */
