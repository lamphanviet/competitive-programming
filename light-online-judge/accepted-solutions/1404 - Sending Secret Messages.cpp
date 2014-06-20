//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1404 - Sending Secret Messages 
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
#define maxN 111

int n, st, nd, f, data;
int cost[maxN][maxN], p[maxN], d[maxN];
vii adj[maxN];

void augment(int v, int minEdge) {
	if (v == st) f = minEdge;
	else if (p[v] != -1) {
		int u = p[v];
		augment(u, min(minEdge, cost[u][v]));
		cost[u][v] -= f; cost[v][u] += f;
	}
}

void findPath() {
	fr(i, 1, nd) p[i] = -1, d[i] = INF;
	d[st] = 0; p[st] = 0;
	set<ii> heap; heap.insert(mp(d[st], st));
	while (!heap.empty()) {
		ii top = *heap.begin(); heap.erase(top);
		int u = top.ss;
		if (u == nd) break;
		rep(i, adj[u].size()) {
			int v = adj[u][i].ff, w = adj[u][i].ss;
			if (cost[u][v] > 0 && d[v] > d[u] + w) {
				if (d[v] != INF) heap.erase(mp(d[v], v));
				d[v] = d[u] + w;
				p[v] = u;
				heap.insert(mp(d[v], v));
			}
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, m, u, v, w, c;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d %d", &n, &m, &data);
		st = 1; nd = 2 * n;
		fill(cost, 0);
		fr(i, 1, nd) adj[i].clear();
		fr(i, 1, n) {
			cost[i][i + n] = INF;
			adj[i].pb(mp(i + n, 0));
			adj[i + n].pb(mp(i, 0));
		}
		while (m--) {
			scanf("%d %d %d %d", &u, &v, &c, &w);
			adj[u + n].pb(mp(v, w));
			adj[v].pb(mp(u + n, -w));
			
			adj[v + n].pb(mp(u, w));
			adj[u].pb(mp(v + n, -w));
			
			cost[u + n][v] = c;
			cost[v + n][u] = c;
		}
		int mf = 0, res = 0;
		do {
			f = 0;
			findPath();
			augment(nd, INF);
			f = min(f, data);
			res += d[nd] * f;
			data -= f;
		} while (f && data);
		printf("Case %d: ", ++caseNo);
		if (data) puts("impossible");
		else printf("%d\n", res);
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */