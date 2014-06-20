//*****************
// LAM PHAN VIET **
// UVA 10650 - Determinate Prime
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
#define maxN 32001
using namespace std;

struct Ans {
    int from, to;
};
bool isP[maxN], Free[maxN];
vector<int> prime;
Ans ans[maxN];
int nans = 0;

void Sieve() {
    Fill(isP, true);
    Fill(Free, true);
    isP[0] = isP[1] = false;
    for (int i=4; i<maxN; i+=2) isP[i] = false;
    for (int i=3; i*i<maxN; i+=2)
        if (isP[i]) for (int j=i*i; j<maxN; j+=i+i)
            isP[j] = false;
    prime.pb(2);
    for (int i=3; i<maxN; i+=2)
        if (isP[i]) prime.pb(i);
}

main() {
 //   FileIn("test"); FileOut("test");
    Sieve();
    int n, m, low, up;
    while (scanf("%d %d", &n, &m) && (n || m)) {
        if (m<n) swap(n, m);
        low = int(lower_bound(all(prime), n) - prime.begin());
        up = int(upper_bound(all(prime), m) - prime.begin());
        int last = low, k = low+1, dis;
        if (k<up) dis = prime[k]-prime[k-1];
        while (k<up) {
            while (k<up && prime[k]-prime[k-1]==dis) k++;
            if (k - last >= 3) {
                ans[nans].from = last;
                ans[nans++].to = k-1;
            }
            if (k<up) {
                last = k-1;
                dis = prime[k]-prime[k-1];
            }
        }
    }
    for (int i=nans-1; i>0; i--) {
        int ax = ans[i].from, ay = ans[i].to;
        REP (j, i)
            if ((ax<=ans[j].from && ans[j].to<ay) || (ax<ans[j].from && ans[j].to<=ay))
                Free[j] = false;
    }
    REP (i, nans) if (Free[i]) {
        printf("%d", prime[ans[i].from]);
        FOR (j, ans[i].from+1, ans[i].to)
            printf(" %d", prime[j]);
        printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
