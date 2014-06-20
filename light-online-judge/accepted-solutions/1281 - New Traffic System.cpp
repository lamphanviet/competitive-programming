//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1281 - New Traffic System
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
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 10011

int n, r;
int d[maxN][11];
vii adj[maxN], adj2[maxN];

int dijkstra() {
	rep(i, n) fr(j, 0, r) d[i][j] = INF;
	set<iii> heap;
	d[0][0] = 0;
	heap.insert(mp(0, mp(0, 0)));
	while (!heap.empty()) {
		iii top = *heap.begin(); heap.erase(top);
		int u = top.ss.ff, k = top.ss.ss;
		if (u == n - 1) return d[u][k];
		rep(i, adj[u].size()) {
			int v = adj[u][i].ff, w = adj[u][i].ss;
			if (d[u][k] + w < d[v][k]) {
				if (d[v][k] != INF) heap.erase(mp(d[v][k], mp(v, k)));
				d[v][k] = d[u][k] + w;
				heap.insert(mp(d[v][k], mp(v, k)));
			}
		}
		if (k == r) continue;
		rep(i, adj2[u].size()) {
			int v = adj2[u][i].ff, w = adj2[u][i].ss;
			if (d[u][k] + w < d[v][k + 1]) {
				if (d[v][k + 1] != INF) heap.erase(mp(d[v][k + 1], mp(v, k + 1)));
				d[v][k + 1] = d[u][k] + w;
				heap.insert(mp(d[v][k + 1], mp(v, k + 1)));
			}
		}
	}
	return -1;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, m, k, u, v, w;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d %d %d", &n, &m, &k, &r);
		rep(i, n) adj[i].clear(), adj2[i].clear();
		while (m--) {
			scanf("%d %d %d", &u, &v, &w);
			adj[u].pb(ii(v, w));
		}
		while (k--) {
			scanf("%d %d %d", &u, &v, &w);
			adj2[u].pb(ii(v, w));
		}
		int res = dijkstra();
		printf("Case %d: ", ++caseNo);
		if (res == -1) puts("Impossible");
		else printf("%d\n", res);
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */