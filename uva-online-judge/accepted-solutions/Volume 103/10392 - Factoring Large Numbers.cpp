//*****************
// LAM PHAN VIET **
// UVA 10392 - Factoring Large Numbers
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

vector<int> prime;
bool isP[maxN];

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

main() {
//    FileIn("test"); FileOut("test");
    Sieve();
    int64 n;
    while (scanf("%lld", &n) && n!=-1) {
        int p = 0, np = prime.size();
        while (p < np) {
            if (n % prime[p] == 0) {
                while (n%prime[p] == 0) {
                    printf("    %d\n", prime[p]);
                    n /= prime[p];
                }
            }
            p++;
        }
        if (n!=1) printf("    %lld\n", n);
        printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
