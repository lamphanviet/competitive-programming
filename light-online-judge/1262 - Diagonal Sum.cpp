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
#define maxN 222

int n, m, k, st, nd, f, p[maxN], c[maxN][maxN], mn;
vi adj[maxN];

void augment(int v, int minEdge) {
	if (v == st) f = minEdge;
	else if (p[v] != -1) {
		int u = p[v];
		augment(u, min(minEdge, c[u][v]));
		c[u][v] -= f; c[v][u] += f;
	}
}

int getCells(int x) {
	if (x <= mn) return x;
	int y = abs(n + m - x);
	if (y <= mn) return y;
	return mn;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		fill(c, 0);
		scanf("%d %d", &n, m);
		k = n + m - 1;
		st = k + k + 1; nd = st + 1;
		mn = min(n, m);
		fr(i, 1, nd) adj[i].clear();
		fr(i, 1, k) {
			scanf("%d", &c[st][i]);
			adj[st].pb(i); adj[i].pb(st);
			c[st][i] -= getCells(i);
		}
		fr(j, 1, k) {
			scanf("%d", &c[j + k][nd]);
			adj[j + k].pb(nd); adj[nd].pb(j + k);
			c[j + k][nd] -= getCells(j);
		}
		fr(i, 1, n) fr(j, 1, m) {
			int x, y;
			c[x][y + k] = 99;
			adj[x].pb(y + k);
			adj[y + k].pb(x);
		}
		do {
			f = 0;
			queue<int> q; q.push(st);
			fr(i, 1, nd) p[i] = -1; p[st] = 0;
			while (!q.empty()) {
				int u = q.front(); q.pop();
				if (u == nd) break;
				rep(i, adj[u].size()) {
					int v = adj[u][i];
					if (c[u][v] > 0 && p[v] == -1)
						p[v] = u, q.push(v);
				}
			}
			augment(nd, INF);
		} while (f);
		printf("Case %d:\n", ++caseNo);
		fr(i, 1, n) {
			fr(j, 1, n)
		}
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */