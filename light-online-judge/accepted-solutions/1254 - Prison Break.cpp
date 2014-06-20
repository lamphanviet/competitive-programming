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
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 101

int n, price[maxN], d[maxN][maxN];
vii adj[maxN];

int dijkstra(int st, int nd, int lim) {
	set<iii> heap;
	rep(i, n) fr(j, 0, lim) d[i][j] = INF;
	d[st][0] = 0;
	heap.insert(iii(d[st][0], ii(st, 0)));
	while (!heap.empty()) {
		iii top = *heap.begin(); heap.erase(top);
		int u = top.ss.ff, k = top.ss.ss;
		//printf("%d %d: %d\n", u, k, d[u][k]);
		if (u == nd) break;
		rep(i, adj[u].size()) {
			int v = adj[u][i].ff, cost = adj[u][i].ss;
			if (k >= cost) {
				int kk = k - cost;
				if (d[u][k] < d[v][kk]) {
					if (d[v][kk] != INF) heap.erase(iii(d[v][kk], ii(v, kk)));
					d[v][kk] = d[u][k];
					heap.insert(iii(d[v][kk], ii(v, kk)));
				}
			}
		}
		if (k + 1 <= lim) {
			int cost = d[u][k] + price[u];
			if (cost < d[u][k + 1]) {
				if (d[u][k + 1] != INF) heap.erase(iii(d[u][k + 1], ii(u, k + 1)));
				d[u][k + 1] = cost;
				heap.insert(iii(d[u][k + 1], ii(u, k + 1)));
			}
		}
	}
	int res = INF;
	fr(i, 0, lim) res = min(res, d[nd][i]);
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, m, u, v, w, lim;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d", &n, &m);
		rep(i, n) {
			scanf("%d", &price[i]);
			adj[i].clear();
		}
		while (m--) {
			scanf("%d %d %d", &u, &v, &w);
			adj[u].pb(ii(v, w));
			adj[v].pb(ii(u, w));
		}
		printf("Case %d:\n", ++caseNo);
		scanf("%d", &m);
		while (m--) {
			scanf("%d %d %d", &lim, &u, &v);
			w = dijkstra(u, v, lim);
			if (w == INF) puts("impossible");
			else printf("%d\n", w);
		}
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet