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
#define maxN 100000

int n, st, nd, p, dst[maxN], dnd[maxN];
vii adjst[maxN], adjnd[maxN];

void dijkstra(int *d, int s, vii *adj) {
	set<ii> heap; heap.insert(mp(0, s));
	fr(i, 1, n) d[i] = INF; d[s] = 0;
	while (!heap.empty()) {
		ii top = *heap.begin(); heap.erase(top);
		int u = top.ss;
		rep(i, adj[u].size()) {
			int v = adj[u][i].ff, w = adj[u][i].ss + d[u];
			if (d[v] > w) {
				if (d[v] != INF) heap.erase(mp(d[v], v));
				d[v] = w;
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
	int cases, caseNo = 0, m, u, v, w;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d %d %d %d", &n, &m, &st, &nd, &p);
		fr(i, 1, n) adjst[i].clear(), adjnd[i].clear();
		while (m--) {
			scanf("%d %d %d", &u, &v, &w);
			adjst[u].pb(mp(v, w));
			adjnd[v].pb(mp(u, w));
		}
		int res = -1;
		dijkstra(dst, st, adjst);
		dijkstra(dnd, nd, adjnd);
		fr(u, 1, n) rep(j, adjst[u].size()) {
			v = adjst[u][j].ff; w = adjst[u][j].ss;
			if (dst[u] + dnd[v] + w <= p)
				res = max(res, w);
		}
		printf("Case %d: %d\n", ++caseNo, res);
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */