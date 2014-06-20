//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1009 - Back to Underworld 
// Time Limit   : 2.000s
// Description  : bfs - graph coloring
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
#define maxN 20010
#define sq(x) ((x) * (x))
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n = 20000, clr[maxN];
vi adj[maxN];

int bfs(int s) {
    int w = 1, b = 0;
    queue<int> q;
    q.push(s);
    clr[s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        REP(i, adj[u].size()) {
            int v = adj[u][i];
            if (clr[v] == 0) {
                clr[v] = -clr[u];
                if (clr[v] == 1) w++;
                else b++;
                q.push(v);
            }
        }
    }
    return max(w, b);
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    int caseNo, cases = 0, m, u, v;
    scanf("%d", &caseNo);
    while (caseNo--) {
        FOR (i, 1, n) {
            adj[i].clear();
            clr[i] = 0;
        }
        scanf("%d", &m);
        while (m--) {
            scanf("%d %d", &u, &v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        int res = 0;
        FOR (i, 1, n)
            if (adj[i].size() && clr[i] == 0)
                res += bfs(i);
        printf("Case %d: %d\n", ++cases, res);
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
