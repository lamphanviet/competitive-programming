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
#define maxN 111

int n, K, G, st, nd, a[maxN], b[maxN];
int cost[maxN][maxN], cap[maxN][maxN];
int fnet[maxN][maxN], d[maxN], pi[maxN], pr[maxN];
vi adj[maxN];

#define pot(u, v) (d[u] + pi[u] - pi[v])
bool findPath() {
	fr(i, 1, nd) d[i] = INF, pr[i] = -1;
	d[st] = 0; pr[st] = 0;
	set<ii> heap; heap.insert(mp(d[st], st));
	while (!heap.empty()) {
		ii top = *heap.begin(); heap.erase(top);
		int u = top.ss;
		rep(i, adj[u].size()) {
			int v = adj[u][i];
			if (fnet[v][u] && d[v] > pot(u, v) - cost[v][u]) {
				if (d[v] != INF) heap.erase(mp(d[v], v));
				d[v] = pot(u, v) - cost[v][u], pr[v] = u;
				heap.insert(mp(d[v], v));
			}
			if (fnet[u][v] < cap[u][v] && d[v] > pot(u, v) + cost[u][v]) {
				if (d[v] != INF) heap.erase(mp(d[v], v));
				d[v] = pot(u, v) + cost[u][v], pr[v] = u;
				heap.insert(mp(d[v], v));
			}
		}
	}
	fr(i, 1, nd) if (pi[i] < INF) pi[i] += d[i];
	return pr[nd] > 0;
}

int mfmc(int k) {
	fill(fnet, 0); fill(pi, 0);
	int totalCost = 0, mf = 0, u, v;
	fr(i, 1, n) fr(j, 1, n) if (a[i] < b[j]) {
		pi[i] += cost[i][j + n];
		cost[i][j + n] *= k;
	}
	while (findPath()) {
		int f = INF, dist = 0;
		for (u = pr[v = nd]; v != st; u = pr[v = u])
			f = min(f, fnet[v][u] ? fnet[v][u] : cap[u][v] - fnet[u][v]);
		for (u = pr[v = nd]; v != st; u = pr[v = u])
			if (fnet[v][u]) fnet[v][u] -= f, dist -= cost[v][u];
			else fnet[u][v] += f, dist += cost[u][v];
			totalCost += f * dist;
		mf += f;
	}
	return (mf == n) ? totalCost : -1;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d %d", &n, &K, &G);
		st = n + n + 1; nd = st + 1;
		fill(cap, 0); fill(cost, 0);
		fr(i, 1, nd) adj[i].clear();
		fr(i, 1, n) scanf("%d", &a[i]);
		fr(i, 1, n) scanf("%d", &b[i]);
		fr(i, 1, n) {
			fr(j, 1, n) if (a[i] < b[j]) {
				adj[i].pb(j + n);
				adj[j + n].pb(i);
				cap[i][j + n] = 1;
				cost[i][j + n] = min(G, sqr(b[j] - a[i] - K));
			}
			cap[st][i] = 1;
			adj[st].pb(i); adj[i].pb(st);
			cap[i + n][nd] = 1;
			adj[i + n].pb(nd); adj[nd].pb(i + n);
		}
		printf("Case %d: ", ++caseNo);
		int minCost = mfmc(1);
		if (minCost >= 0)
			printf("%d %d\n", minCost, -mfmc(-1));
		else puts("impossible");
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */