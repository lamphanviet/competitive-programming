//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1321 - Sending Packets 
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

int n, s, k;
double d[maxN];
vector<pair<int, double> > adj[maxN];

double dijkstra() {
	set<pair<double, int> > heap; heap.insert(mp(0.0, 0));
	while (!heap.empty()) {
		pair<double, int> top = *heap.begin(); heap.erase(top);
		int u = top.ss;
		//printf("%d: %lf\n", u, d[u]);
		if (u == n - 1) return fabs(d[n - 1]);
		rep(i, adj[u].size()) {
			int v = adj[u][i].ff;
			double p = -fabs(adj[u][i].ss * d[u]);
			if (d[v] > p) {
				heap.erase(mp(d[v], v));
				d[v] = p;
				heap.insert(mp(d[v], v));
			}
		}
	}
	return fabs(d[n - 1]);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, m, u, v, w;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d %d %d", &n, &m, &s, &k);
		rep(i, n) d[i] = 0.0, adj[i].clear(); d[0] = -1.0;
		while (m--) {
			scanf("%d %d %d", &u, &v, &w);
			adj[u].pb(mp(v, w / -100.0));
			adj[v].pb(mp(u, w / -100.0));
		}
		double res = dijkstra();
		printf("Case %d: %.12lf\n", ++caseNo, 1.0 / res * k * 2.0 * s);
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */