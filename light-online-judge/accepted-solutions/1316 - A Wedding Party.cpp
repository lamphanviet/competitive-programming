//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1316 - A Wedding Party 
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
#define maxN 505

int n, k, d[maxN], st, nd;
int shop[20], dist[20][20], f[20][BIT(15)];
vii adj[maxN];

void dijkstra(int s, int p) {
	rep(i, n) d[i] = INF; d[s] = 0;
	set<ii> heap; heap.insert(mp(d[s], s));
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
	rep(i, nd + 1) dist[p][i] = d[shop[i]];
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, m, u, v, w;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d %d", &n, &m, &k);
		rep(i, k) scanf("%d", &shop[i]);
		rep(i, n) adj[i].clear();
		while (m--) {
			scanf("%d %d %d", &u, &v, &w);
			adj[u].pb(mp(v, w));
		}
		st = k; nd = st + 1;
		shop[st] = 0; shop[nd] = n - 1;
		rep(i, nd + 1) dijkstra(shop[i], i);
		
		printf("Case %d: ", ++caseNo);
		if (dist[st][nd] == INF) {
			puts("Impossible");
			continue;
		}
		
		m = BIT(k);
		rep(i, k) {
			rep(j, m) f[i][j] = INF;
			f[i][BIT(i)] = dist[st][i];
		}
		
		int sp = 0, time = dist[st][nd];
		rep(x, m) {
			rep(i, k) if (f[i][x] != INF) {
				rep(j, k)
					if (shop[i] != shop[j] && dist[i][j] != INF) {
						int nextX = x | BIT(j);
						f[j][nextX] = min(f[j][nextX], f[i][x] + dist[i][j]);
					}
				int tmp = __builtin_popcount(x);
				if (dist[i][nd] != INF && tmp >= sp) {
					if (tmp == sp) time = min(time, f[i][x] + dist[i][nd]);
					else time = f[i][x] + dist[i][nd];
					sp = tmp;
				}
			}
		}
		printf("%d %d\n", sp, time);
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */