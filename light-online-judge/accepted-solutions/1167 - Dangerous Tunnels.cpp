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
#define INF 100005
#define eps 1e-7
#define maxN 211

int n, k, c[maxN][maxN], dangrs[maxN][maxN];
int p[maxN], st, nd, f, C[maxN][maxN];
vi adj[maxN];

void augment(int v, int minEdge) {
	if (v == st) f = minEdge;
	else if (p[v] != -1) {
		augment(p[v], min(minEdge, c[p[v]][v]));
		c[p[v]][v] -= f; c[v][p[v]] += f;
	}
}

bool accept(int maxEdge) {
	memcpy(c, C, sizeof(C));
	int mf = 0;
	do {
		f = 0;
		fr(i, 0, nd) p[i] = -1;
		p[st] = 0;
		queue<int> q; q.push(st);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (u == nd) break;
			rep(i, adj[u].size()) {
				int v = adj[u][i];
				if (dangrs[u][v] <= maxEdge && c[u][v] > 0 && p[v] == -1)
					p[v] = u, q.push(v);
			}
		}
		augment(nd, INF);
		mf += f;
		if (mf >= k) return true;
	} while (f);
	return false;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, m, u, v, w;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d", &n, &m);
		st = 0; nd = 2 * n + 1;
		fr(i, 0, nd) {
			fr(j, 0, nd)
				C[i][j] = 0, dangrs[i][j] = INF;
			adj[i].clear();
		}
		fr(i, 1, n) {
			C[i][i + n] = 1;
			dangrs[i][i + n] = dangrs[i + n][i] = 0;
			adj[i].pb(i + n); adj[i + n].pb(i);
		}
		while (m--) {
			scanf("%d %d %d", &u, &v, &w);
			if (u > v) swap(u, v);
			if (u > 0) u += n;
			if (v == n + 1) v = nd;
			dangrs[v][u] = dangrs[u][v] = w;
			C[u][v] = 1;
			adj[u].pb(v); adj[v].pb(u);
		}
		scanf("%d", &k);
		
		int res = INF, hi = INF, lo = 0;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (accept(mid))
				res = mid, hi = mid - 1;
			else lo = mid + 1;
		}
		printf("Case %d: ", ++caseNo);
		if (res == INF) puts("no solution");
		else printf("%d\n", res);
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */