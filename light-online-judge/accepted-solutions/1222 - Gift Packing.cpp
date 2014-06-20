//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1222 - Gift Packing 
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

int n, st, nd, cap[maxN][maxN], cost[maxN][maxN];
int fnet[maxN][maxN], pi[maxN], pr[maxN], d[maxN];

#define pot(u, v) (d[u] + pi[u] - pi[v])
bool findPath() {
	fr(i, 0, nd) pr[i] = -1, d[i] = INF;
	d[st] = 0; pr[st] = 0;
	set<ii> heap; heap.insert(mp(d[st], st));
	//int counter = 0;
	while (!heap.empty()) {
		ii top = *heap.begin(); heap.erase(top);
		int u = top.ss;
		if (u == nd) break;
		//printf("uu %d: %d\n", u, d[u]);
		//if (++counter > 20) break;
		fr(v, 0, nd) {
			if (!cap[u][v] && !cap[v][u]) continue;
			if (fnet[v][u] && d[v] > pot(u, v) - cost[v][u]) {
				if (d[v] != INF) heap.erase(mp(d[v], v));
				d[v] = pot(u, v) - cost[v][u], pr[v] = u;
				heap.insert(mp(d[v], v));
				//printf("-> v1: %d %d\n", v, d[v]);
			}
			if (fnet[u][v] < cap[u][v] && d[v] > pot(u, v) + cost[u][v]) {
				if (d[v] != INF) heap.erase(mp(d[v], v));
				d[v] = pot(u, v) + cost[u][v], pr[v] = u;
				heap.insert(mp(d[v], v));
				//printf("-> v2: %d %d\n", v, d[v]);
			}
		}
	}
	fr(i, 0, nd) if (pi[i] < INF) pi[i] += d[i];
	return pr[nd] >= 0;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, u, v;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d", &n);
		st = n + n; nd = st + 1;
		fill(cost, 0); fill(cap, 0); fill(fnet, 0); fill(pi, 0);
		rep(i, n) rep(j, n) {
			scanf("%d", &cost[i][j + n]);
			//pi[j + n] += cost[i][j + n];
			pi[i] += cost[i][j + n]; // tong cac canh ra
			cost[i][j + n] = -cost[i][j + n];
			cap[i][j + n] = 1;
		}
		rep(i, n) {
			cap[st][i] = 1;
			cap[i + n][nd] = 1;
		}
		int totalProfit = 0;
		while (true) {
			if (!findPath()) break;
			int f = INF, profit = 0;
			for (u = pr[v = nd]; v != st; u = pr[v = u])
				f = min(f, fnet[v][u] ? fnet[v][u] : cap[u][v] - fnet[u][v]);
			for (u = pr[v = nd]; v != st; u = pr[v = u]) {
				if (fnet[v][u]) {
					fnet[v][u] -= f;
					profit -= cost[v][u];
				}
				else {
					fnet[u][v] += f;
					profit += cost[u][v];	
				}
			}
			totalProfit += profit;
			//printf("%d: %d\n", f, profit);
		}
		printf("Case %d: %d\n", ++caseNo, -totalProfit);
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */