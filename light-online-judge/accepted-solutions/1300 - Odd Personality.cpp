//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1300 - Odd Personality
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

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 10011

int n, num[maxN], low[maxN], number, mark[maxN], size;
vi adj[maxN];
set<ii> bridge;
bool add;

void dfs1(int u, int parent) {
    num[u] = low[u] = ++number;
    rep(i, adj[u].size()) {
        int v = adj[u][i];
        if (v == parent) continue;
        if (num[v]) low[u] = min(low[u], num[v]);
        else {
            dfs1(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > num[u]) bridge.insert(mp(min(u, v), max(u, v)));
        }
    }
}

void dfs2(int u) {
    size++;
    rep(i, adj[u].size()) {
        int v = adj[u][i];
        if (bridge.find(mp(min(u, v), max(u, v))) != bridge.end()) continue;
        if (mark[v] && mark[v] == mark[u]) add = false;
        else if (mark[v] == 0) {
            mark[v] = 0 - mark[u];
            dfs2(v);
        }
    }
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, m, u, v;
	for (scanf("%d", &cases); cases--; ) {
	    scanf(" %d %d ", &n, &m);
	    rep(i, n) {
	        adj[i].clear();
	        num[i] = mark[i] = 0;
	    }
	    while (m--) {
	        scanf(" %d %d ", &u, &v);
	        adj[u].pb(v); adj[v].pb(u);
	    }
	    bridge.clear(); number = 0;
	    rep(i, n) if (!num[i])
            dfs1(i, i);
	    int res = 0;
	    rep(i, n) if (!mark[i]) {
	        add = true; size = 0;
	        mark[i] = -1;
	        dfs2(i);
	        if (!add) res += size;
	    }
	    printf("Case %d: %d\n", ++caseNo, res);
	}
	return 0;
}
