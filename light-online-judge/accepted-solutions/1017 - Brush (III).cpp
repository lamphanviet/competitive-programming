//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1017 - Brush (III) 
// Time Limit   : 2.000s
// Description  : dp - geometry
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
#define INF 2000000000
#define maxN 111
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, w, k, y[maxN], f[maxN][maxN];

int solve() {
    fill(f, 0);
    REP(i, n - 1) {
        REP(j, k) {
            if (i) f[i][j] = max(f[i][j], f[i - 1][j]);
            int t = i;
            while (y[t] <= y[i] + w) t++;
            f[t][j + 1] = max(f[t][j + 1], f[i][j] + t - i);
        }
    }
    int res = 0;
    REP(i, n) REP(j, k + 1)
        res = max(res, f[i][j]);
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    int caseNo, cases = 0, garbage;
    scanf("%d", &caseNo);
    while (caseNo--) {
        scanf("%d %d %d ", &n, &w, &k);
        REP(i, n)
            scanf("%d %d", &garbage, &y[i]);
        sort(y, y + n);
        y[n++] = INF;
        printf("Case %d: %d\n", ++cases, solve());
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
