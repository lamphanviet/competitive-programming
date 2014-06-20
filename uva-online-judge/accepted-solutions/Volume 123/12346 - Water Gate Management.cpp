//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : Asia Regionals Phuket 2011 - UVa
// Problem Name : 12346 - Water Gate Management
// Time Limit   : 1.000s
// Description  : back tracking
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
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 100010
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, f[maxN], c[maxN], maxVal, t;
int64 res;

void backTracking(int i, int64 flow, int64 cost) {
    if (cost >= res) return;
    if (flow >= maxVal) {
        res = min(res, cost);
        return;
    }
    if (i == n) return;
    backTracking(i + 1, flow + f[i] * (int64)t, cost + c[i]);
    backTracking(i + 1, flow, cost);
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); outFile("test.out");
    #endif
    int m;
    scanf("%d", &n);
    REP(i, n) scanf("%d %d", &f[i], &c[i]);
    scanf("%d", &m);
    FOR (test, 1, m) {
        scanf("%d %d", &maxVal, &t);
        printf("Case %d: ", test);
        res = INF;
        backTracking(0, 0, 0);
        if (res != INF) printf("%lld\n", res);
        else puts("IMPOSSIBLE");
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
