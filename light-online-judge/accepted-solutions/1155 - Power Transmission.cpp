//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1155 - Power Transmission 
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

int cost[maxN][maxN], st, nd, f, p[maxN], n;
vi adj[maxN];

void augment(int v, int minEdge) {
	if (v == st) f = minEdge;
	else if (p[v] != -1) {
		augment(p[v], min(minEdge, cost[p[v]][v]));
		cost[p[v]][v] -= f;
		cost[v][p[v]] += f;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, u, m, b, d, v;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d", &n);
		st = n + n + 1;
		nd = st + 1;
		fill(cost, 0);
		fr(i, 1, nd) adj[i].clear();
		fr(i, 1, n) {
			scanf("%d", &cost[i][i + n]);
			adj[i].pb(i + n); adj[i + n].pb(i);
		}
		scanf("%d", &m);
		while (m--) {
			scanf("%d %d", &u, &v);
			scanf("%d", &cost[u + n][v]);
			adj[u + n].pb(v); adj[v].pb(u + n);
		}
		scanf("%d %d", &b, &d);
		while (b--) {
			scanf("%d", &u);
			cost[st][u] = INF;
			adj[st].pb(u); adj[u].pb(st);
		}
		while (d--) {
			scanf("%d", &u);
			cost[u + n][nd] = INF;
			adj[u + n].pb(nd); adj[nd].pb(u + n);
		}
		int res = 0;
		while (true) {
			f = 0;
			fr(i, 1, nd) p[i] = -1;
			queue<int> q; q.push(st);
			p[st] = 0;
			while (!q.empty()) {
				u = q.front(); q.pop();
				if (u == nd) break;
				rep(i, adj[u].size()) {
					v = adj[u][i];
					if (cost[u][v] > 0 && p[v] == -1) {
						p[v] = u;
						q.push(v);
					}
				}
			}
			augment(nd, INF);
			if (f == 0) break;
			res += f;
		}
		printf("Case %d: %d\n", ++caseNo, res);
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */