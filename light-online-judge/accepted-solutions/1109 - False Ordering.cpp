//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1109 - False Ordering 
// Time Limit   : 1.000s
// Description  : beginner
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
#define maxN 1005
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int res[maxN];

bool cmp(const ii &a, const ii &b) {
    if (a.ss == b.ss)
        return a.ff > b.ff;
    return a.ss < b.ss;
}

void preCal() {
    ii f[maxN];
    FOR (i, 1, 1000) {
        FOR (j, 1, i)
            if (i % j == 0)
                f[i].ss++;
        f[i].ff = i;
    }
    sort(f + 1, f + 1001, cmp);
    FOR (i, 1, 1000)
        res[i] = f[i].ff;
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); outFile("test.out");
    #endif
    preCal();
    int caseNo, cases = 0, n;
    for (scanf("%d", &caseNo); caseNo--; ) {
        scanf("%d", &n);
        printf("Case %d: %d\n", ++cases, res[n]);
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
