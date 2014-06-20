//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1019 - Brush (V)
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
#define maxN 110
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, d[maxN];
vii adj[maxN];
bool flag[maxN];

void dijkstra() {
    d[1] = 0;
    while (1) {
        int u = 0, minD = INF;
        FOR (i, 1, n)
            if (!flag[i] && d[i] < minD) {
                u = i; minD = d[i];
            }
        if (u == 0 || u == n) break;
        flag[u] = true;
        REP(i, adj[u].size()) {
            int v = adj[u][i].ff, w = adj[u][i].ss;
            if (d[v] > d[u] + w)
                d[v] = d[u] + w;
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    int caseNo, cases = 0, m, u, v, w;
    scanf("%d", &caseNo);
    while (caseNo--) {
        scanf("%d %d", &n, &m);
        FOR (i, 1, n) {
            adj[i].clear();
            flag[i] = false;
            d[i] = INF;
        }
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            adj[u].pb(ii(v, w));
            adj[v].pb(ii(u, w));
        }
        dijkstra();
        printf("Case %d: ", ++cases);
        if (d[n] == INF) puts("Impossible");
        else printf("%d\n", d[n]);
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
