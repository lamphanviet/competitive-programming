//*****************
// LAM PHAN VIET **
// UVA 11466 - Largest Prime Divisor 
// Time limit: 2.000s
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
#define REP(i, a, b) for (int i=a; i<=b; i++)
#define REP0(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) (i & -i)
#define Parent(i) (i - Last(i))
#define INF 500000000
#define maxN 10000000
using namespace std;

bool isP[maxN];
vector<int> prime;

void Sieve() {
    Fill(isP, true);
    isP[0] = isP[1] = false;
    for (int i=4; i<maxN; i+=2) isP[i] = false;
    for (int i=3; i*i<maxN; i+=2)
        if (isP[i])
            for (int j=i*i; j<maxN; j += i+i)
                isP[j] = false;
    prime.pb(2);
    for (int i=3; i<maxN; i+=2)
        if (isP[i]) prime.pb(i);
}

int64 Solve(int64 n) {
    if (n<0) n = -n;
    int p = 0, np = prime.size(), Count = 0;
    int64 rs = 0, m = n;
    while (p<np && m>1) {
        if (m%prime[p]==0) {
            Count++;
            rs = (int64)prime[p];
            while (m!=1 && m%prime[p]==0)
                m /= prime[p];
        }
        p++;
    }
    if (m>1 && m!=n) return m;
    if (Count<2) return -1;
    return rs;
}

main() {
//    FileIn("test"); FileOut("test");
    Sieve();
    int64 n;
    while (scanf("%lld", &n) && n) {
        printf("%lld\n", Solve(n));
    }
}

/* lamphanviet@gmail.com - 2011 */
