//*****************
// LAM PHAN VIET **
// UVA 332 - Rational Numbers from Repeating Fractions
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
#define maxN 11
using namespace std;

int X10[maxN];

int GCD(int m, int n) {
    int r = m%n;
    while (r) {
        m = n; n = r;
        r = m%n;
    }
    return n;
}

main() {
//    FileIn("test"); FileOut("test");
    X10[0] = 1;
    FOR (i, 1, 9) X10[i] = X10[i-1]*10;
    int Case = 0, n;
    char s[100];
    while (scanf("%d", &n) && n>=0) {
        int p = 0, q = 0;
        scanf(" %s", &s);
        int len = strlen(s)-1;
        FOR (i, 2, len) p = p*10 + (s[i]-48);
        if (n!=0) {
            p = p - p/X10[n];
            q = X10[len-1] - X10[len-n-1];
        } else q = X10[len-1];
        int gcd = GCD(p, q);
        printf("Case %d: %d/%d\n", ++Case, p/gcd, q/gcd);
    }
}

/* lamphanviet@gmail.com - 2011 */
