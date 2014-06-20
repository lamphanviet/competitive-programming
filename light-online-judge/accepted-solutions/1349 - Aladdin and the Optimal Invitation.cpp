//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1349 - Aladdin and the Optimal Invitation 
// Time Limit   : .000s
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
#define maxN 50010
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, m, k, sumW[maxN];
ii x[maxN], y[maxN];
int64 cost[maxN];

int solve(ii *p) {
    cost[0] = sumW[0] = 0;
    for (int i = 1; i < k; i++) {
        sumW[i] = sumW[i - 1] + p[i - 1].ss;
        cost[i] = cost[i - 1] + sumW[i] * (int64)(p[i].ff - p[i - 1].ff);
    }
    int64 tmpCost = 0, tmpW = 0;
    int64 minCost = cost[k - 1], pos = p[k - 1].ff;
    for (int i = k - 2; i >= 0; i--) {
        tmpW += p[i + 1].ss;
        tmpCost += tmpW * (int64)(p[i + 1].ff - p[i].ff);
        if (tmpCost + cost[i] < minCost) {
            minCost = tmpCost + cost[i];
            pos = p[i].ff;
        }
    }
    return pos;
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    int caseNo, cases = 0, w;
    scanf("%d", &caseNo);
    while (caseNo--) {
        scanf("%d %d %d", &n, &m, &k);
        REP(i, k) {
            scanf("%d %d %d", &x[i].ff, &y[i].ff, &w);
            x[i].ss = w;
            y[i].ss = w;
        }
        sort(x, x + k);
        sort(y, y + k);
        printf("Case %d: %d %d\n", ++cases, solve(x), solve(y));
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
