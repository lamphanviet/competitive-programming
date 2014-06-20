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
#define maxN 5005

int n, ds[maxN], dt[maxN];
vii adj[maxN];

void dijkstra(int st, int *d) {
	set<ii> heap;
	heap.insert(ii(0, st));
	d[st] = 0;
	while (!heap.empty()) {
		ii top = *heap.begin(); heap.erase(top);
		int u = top.ss;
		rep(i, adj[u].size()) {
			int v = adj[u][i].ff, w = adj[u][i].ss;
			if (d[v] > d[u] + w) {
				if (d[v] != INF) heap.erase(ii(d[v], v));
				d[v] = d[u] + w;
				heap.insert(ii(d[v], v));
			}
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, u, v, w, m;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d", &n, &m);
		fr(i, 1, n) {
			adj[i].clear();
			ds[i] = dt[i] = INF;
		}
		while (m--) {
			scanf("%d %d %d", &u, &v, &w);
			adj[u].pb(ii(v, w));
			adj[v].pb(ii(u, w));
		}
		dijkstra(1, ds); dijkstra(n, dt);
		int res = INF;
		fr(i, 1, n) {
			int cost = ds[i] + dt[i];
			if (cost > ds[n]) res = min(res, cost);
			rep(j, adj[i].size()) {
				w = adj[i][j].ss;
				if (cost + w + w > ds[n])
					res = min(res, cost + w + w);
				if (ds[i] + w + dt[adj[i][j].ff] > ds[n])
					res = min(res, ds[i] + w + dt[adj[i][j].ff]);
			}
		}
		printf("Case %d: %d\n", ++caseNo, res);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet