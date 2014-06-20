//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1177 - Angry Programmer 
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

int n, k, f, c[maxN][maxN], trace[maxN];
vi adj[maxN];

void augment(int v, int minEdge) {
	if (v == 1) f = minEdge;
	else if (trace[v] != -1) {
		int u = trace[v];
		augment(u, min(minEdge, c[u][v]));
		c[u][v] -= f; c[v][u] += f;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, u, v, m, value;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d", &n, &m);
		k = n + n;
		fill(c, 0);
		fr(i, 1, k) adj[i].clear();
		fr(i, 2, n - 1) {
			scanf("%d", &c[i][i + n]);
			adj[i].pb(i + n); adj[i + n].pb(i);
		}
		c[1][1 + n] = c[n][n + n] = INF;
		adj[1].pb(1 + n); adj[1 + n].pb(1);
		adj[n].pb(n + n); adj[n + n].pb(n);
		while (m--) {
			scanf("%d %d %d", &u, &v, &value);
			c[u + n][v] += value;
			c[v + n][u] = c[u + n][v];
			adj[u + n].pb(v); adj[v].pb(u + n);
			adj[v + n].pb(u); adj[u].pb(v + n);
		}
		int mf = 0;
		do {
			f = 0;
			queue<int> q; q.push(1);
			fr(i, 1, k) trace[i] = -1;
			trace[1] = 0;
			while (!q.empty()) {
				u = q.front(); q.pop();
				if (u == k) break;
				rep(i, adj[u].size()) {
					v = adj[u][i];
					if (c[u][v] > 0 && trace[v] == -1)
						trace[v] = u, q.push(v);
				}
			}
			augment(k, INF);
			mf += f;
		} while (f);
		printf("Case %d: %d\n", ++caseNo, mf);
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */