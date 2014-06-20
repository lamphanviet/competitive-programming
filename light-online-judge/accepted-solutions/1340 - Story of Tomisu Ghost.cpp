//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1340 - Story of Tomisu Ghost 
// Time Limit   : 2.000s
// Description  : 
//============================================================================
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define inpFile(f) freopen(f, "r", stdin)
#define outFile(f) freopen(f, "w", stdout)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define ff first
#define ss second
#define bit(n) (1<<(n))
#define Last(i) ( (i) & (-i) )
#define sq(x) ((x) * (x))
#define INF 500000000
#define MOD 10000019
#define maxN 100010
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vi prime;
bool isP[maxN];

void sieve() {
    fill(isP, true);
    for (int i = 3; i * i < maxN; i += 2)
        if (isP[i]) for (int j = i*i; j < maxN; j += i << 1)
            isP[j] = false;
    prime.pb(2);
    for (int i = 3; i <maxN; i += 2)
        if (isP[i]) prime.pb(i);
}

int powMod(int n, int k) {
    if (k == 0) return 1;
    if (k == 1) return n;
    int tmp = powMod(n, k / 2);
    tmp = (tmp * (int64)tmp) % MOD;
    if (k & 1) return (tmp * (int64)n) % MOD;
    return tmp;
}

int cal(int n, int k) {
    int res = 0;
    int64 kk = k;
    while (kk <= n) {
        res += n / kk;
        kk *= k;
    }
    return res;
}

int solve(int n, int t) {
    int64 res = 1;
    for (int i = 0; i < prime.size() && prime[i] <= n; i++) {
        int k = cal(n, prime[i]);
        if (k >= t)
            res = (res * powMod(prime[i], k / t)) % MOD;
    }
    if (res == 1) return -1;
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    sieve();
    int caseNo, cases = 0, n, t;
    scanf("%d", &caseNo);
    while (caseNo--) {
        scanf("%d %d", &n, &t);
        printf("Case %d: %d\n", ++cases, solve(n, t));
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
