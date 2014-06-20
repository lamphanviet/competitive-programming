//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1094 - Farthest Nodes in a Tree 
// Time Limit   : 2.000s
// Description  : bfs - basic
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
#define maxN 30010
#define sq(x) ((x) * (x))
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, res;
vii adj[maxN];

int dfs(int u, int d, int p) {
    int max1 = 0, max2 = 0;
    REP(i, adj[u].size()) {
        int v = adj[u][i].ff, w = adj[u][i].ss;
        if (v == p) continue;
        int dd = dfs(v, w, u);
        if (dd >= max1) {
            max2 = max1;
            max1 = dd;
        }
        else if (dd > max2)
            max2 = dd;
    }
    res = max(res, max1 + max2);
    return max(max1, max2) + d;
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    int caseNo, cases = 0, u, v, w;
    scanf("%d", &caseNo);
    while (caseNo--) {
        scanf("%d", &n);
        REP(i, n) adj[i].clear();
        REP(_, n - 1) {
            scanf("%d %d %d", &u, &v, &w);
            adj[u].pb(ii(v, w));
            adj[v].pb(ii(u, w));
        }
        res = 0;
        dfs(0, 0, -1);
        printf("Case %d: %d\n", ++cases, res);
    }
    return 0;
}

// lamphanviet@gmail.com - 2011

