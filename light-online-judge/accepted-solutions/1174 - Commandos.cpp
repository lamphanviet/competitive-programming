//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1174 - Commandos 
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
#define maxN 110
#define sq(x) ((x) * (x))
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, d[maxN], dd[maxN];
vi adj[maxN];

int bfs(int s, int t) {
    REP(i, n) d[i] = INF;
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        REP(i, adj[u].size()) {
            int v = adj[u][i];
            if (d[v] == INF) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    int res = 0;
    REP(i, n) {
        REP(i, n) dd[i] = INF;
        q = queue<int>();
        q.push(i);
        dd[i] = d[i];
        while (!q.empty()) {
            int u = q.front(); q.pop();
            REP(i, adj[u].size()) {
                int v = adj[u][i];
                if (dd[v] == INF) {
                    dd[v] = dd[u] + 1;
                    q.push(v);
                }
            }
        }
        res = max(res, dd[t]);
    }
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    int caseNo, cases = 0, m, u, v;
    scanf("%d", &caseNo);
    while (caseNo--) {
        scanf("%d %d", &n, &m);
        REP(i, n) adj[i].clear();
        while (m--) {
            scanf("%d %d", &u, &v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        scanf("%d %d", &u, &v);
        printf("Case %d: %d\n", ++cases, bfs(u, v));
    }
    return 0;
}

// lamphanviet@gmail.com - 2011

