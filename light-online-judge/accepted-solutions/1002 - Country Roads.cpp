//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1002 - Country Roads
// Time Limit   : 2.000s
// Description  : dijkstra - basic
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
#define maxN 505
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, d[maxN];
vii adj[maxN];
bool flag[maxN];

void dijkstra(int s) {
    d[s] = 0;
    while (1) {
        int u = -1, minD = INF;
        REP(i, n)
            if (!flag[i] && d[i] < minD) {
                u = i; minD = d[i];
            }
        if (u == -1) break;
        flag[u] = true;
        REP(i, adj[u].size()) {
            int v = adj[u][i].ff, w = max(d[u], adj[u][i].ss);
            if (!flag[v] && d[v] > w)
                d[v] = w;
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    int m, u, v, w, s;
    int caseNo, cases = 0;
    scanf("%d", &caseNo);
    while (caseNo--) {
        scanf("%d %d", &n, &m);
        REP(i, n) {
            adj[i].clear();
            d[i] = INF;
            flag[i] = false;
        }
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            adj[u].pb(ii(v, w));
            adj[v].pb(ii(u, w));
        }
        scanf("%d", &s);
        dijkstra(s);
        printf("Case %d:\n", ++cases);
        REP(i, n) if (d[i] != INF)
            printf("%d\n", d[i]);
        else puts("Impossible");
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
