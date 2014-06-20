//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 
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
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 30011

int n, dist[maxN];
vii adj[maxN];
vector<iii> child[maxN];
bool vis[maxN];

int build(int u) {
	vis[u] = true;
	int maxLength = 0;
	rep(i, adj[u].size()) {
		int v = adj[u][i].ff, d = adj[u][i].ss;
		if (vis[v]) continue;
		child[u].pb(iii(ii(build(v) + d, d), v));
		maxLength = max(maxLength, child[u].back().ff.ff);
	}
	sort(all(child[u])); reverse(all(child[u]));
	return maxLength;
}

void dfs(int u, int dd) {
	dist[u] = dd;
	rep(i, child[u].size()) {
		int v = child[u][i].ss, d = child[u][i].ff.ss;
		dist[u] = max(dist[u], child[u][i].ff.ff);
		d = child[u][0].ff.ff;
		if (i == 0) {
			if (child[u].size() > 1) d = child[u][1].ff.ff;
			else d = 0;
		}
		dfs(v, max(d, dd) + child[u][i].ff.ss);
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, u, v, w;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d", &n);
		rep(i, n) {
			adj[i].clear();
			child[i].clear();
			dist[i] = 0;
			vis[i] = false;
		}
		rep(_, n - 1) {
			scanf("%d %d %d", &u, &v, &w);
			adj[u].pb(ii(v, w));
			adj[v].pb(ii(u, w));
		}
		build(0);
		dfs(0, 0);
		printf("Case %d:\n", ++caseNo);
		rep(i, n) printf("%d\n", dist[i]);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet