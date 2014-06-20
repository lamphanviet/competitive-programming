//*****************
// LAM PHAN VIET **
// UVA 12043 - Divisors
// Time limit: 1.000s
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
#define maxN 100001
using namespace std;

int d[maxN], sum[maxN];

void PreCal() {
    REP (i, maxN)
        d[i] = 1, sum[i] = 1;
    FOR (i, 2, maxN-1)
        for (int j=i; j<maxN; j+=i) {
            d[j]++; sum[j] += i;
        }
}

main() {
//    FileIn("test"); FileOut("test");
    int Case, a, b, k;
    PreCal();
    for (scanf("%d", &Case); Case--; ) {
        scanf("%d %d %d", &a, &b, &k);
        if (a%k) {
            a = (1 + a/k) * k;
        }
        uint64 resd = 0, ress = 0;
        while (a <= b) {
            resd += d[a];
            ress += sum[a];
            a += k;
        }
        printf("%lld %lld\n", resd, ress);
    }
}

/* lamphanviet@gmail.com - 2011 */
