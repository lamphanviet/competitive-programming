//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1404 - Sending Secret Messages
// Time Limit   : .000s
// Description  : Mincost Maxflow + dijkstra (successive shortest path)
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
#define maxN 55

int n, st, nd, cap[maxN][maxN], cost[maxN][maxN], fnet[maxN][maxN];
int d[maxN], p[maxN], pi[maxN];
vi adj[maxN];

#define pot(u, v) (d[u] + pi[u] - pi[v])
bool findPath() {
	fr(i, 1, n) d[i] = INF, p[i] = -1;
	d[st] = 0; p[st] = 0;
	set<ii> heap; heap.insert(mp(d[st], st));
	while (!heap.empty()) {
		ii top = *heap.begin(); heap.erase(top);
		int u = top.ss;
		if (u == nd) break;
		rep(i, adj[u].size()) {
			int v = adj[u][i];
			if (fnet[v][u] && d[v] > pot(u, v) - cost[v][u]) {
				heap.erase(mp(d[v], v));
				d[v] = pot(u, v) - cost[v][u], p[v] = u;
				heap.insert(mp(d[v], v));
			}
			if (fnet[u][v] < cap[u][v] && d[v] > pot(u, v) + cost[u][v]) {
				heap.erase(mp(d[v], v));
				d[v] = pot(u, v) + cost[u][v], p[v] = u;
				heap.insert(mp(d[v], v));
			}
		}
	}
	fr(i, 1, n) if (pi[i] < INF)
		pi[i] += d[i];
	return p[nd] >= 0;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, m, u, v, w, c, data;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d %d", &n, &m, &data);
		fr(i, 1, n) adj[i].clear();
		fill(cap, 0); fill(pi, 0); fill(fnet, 0);
		
		while (m--) {
			scanf("%d %d %d %d", &u, &v, &c, &w);
			cap[u][v] = cap[v][u] = c;
			cost[u][v] = cost[v][u] = w;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		
		st = 1; nd = n;
		int netCost = 0;
		do {
			if (!findPath()) break;
			int f = INF, totalCost = 0;
			for (v = nd, u = p[v]; v != st; v = u, u = p[u])
				f = min(f, fnet[v][u] ? fnet[v][u] : cap[u][v] - fnet[u][v]);
			
			for (v = nd, u = p[v]; v != st; v = u, u = p[u]) {
				if (fnet[v][u]) { fnet[v][u] -= f; totalCost -= cost[v][u]; }
				else { fnet[u][v] += f; totalCost += cost[u][v]; }
			}
			netCost += min(data, f) * totalCost;
			data -= f;
		} while (data > 0);
		//printf("dta %d %d\n", data, netCost);
		printf("Case %d: ", ++caseNo);
		if (data > 0) puts("impossible");
		else printf("%d\n", netCost);
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */