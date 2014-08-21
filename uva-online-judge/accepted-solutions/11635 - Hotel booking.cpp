//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 11635 - Hotel booking
// Time Limit   : 4.000s
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
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 10011
#define maxH 105

int pos = 0, len = 0;
char buffer[maxH * 20];
int nextInt() {
	int val = 0;
	while (true) {
		if (pos == len) {
			gets(buffer);
			pos = 0;
			len = strlen(buffer);
		}
		while (pos < len && !isdigit(buffer[pos])) pos++;
		if (pos == len) continue;
		while (pos < len && isdigit(buffer[pos]))
			val = val * 10 + buffer[pos++] - 48;
		return val;
	}
}

int n, h, d[maxN][maxH];
bool flag[maxN][maxH], hotel[maxN];
vii adj[maxN];

int dijkstra() {
	d[1][0] = 0;
	set<iii> heap;
	heap.insert(iii(ii(0, 0), 1));
	while (heap.size()) {
		iii top = *heap.begin(); heap.erase(top);
		int d1 = top.ff.ff, d2 = top.ff.ss, u = top.ss;
		if (u == n) return d1;
		flag[u][d1] = true;
		rep(i, adj[u].size()) {
			int v = adj[u][i].ff, w = adj[u][i].ss;
			if (d2 + w > 600) continue;
			int x = d1, y = d2 + w;
			if (x > h + 1) continue;
			if (!flag[v][x] && y < d[v][x]) {
				if (d[v][x] != INF) heap.erase(iii(ii(x, d[v][x]), v));
				d[v][x] = y;
				heap.insert(iii(ii(x, y), v));
			}
			if (hotel[v]) {
				x++, y = 0;
				if (!flag[v][x] && y < d[v][x]) {
					if (d[v][x] != INF) heap.erase(iii(ii(x, d[v][x]), v));
					d[v][x] = y;
					heap.insert(iii(ii(x, y), v));
				}
			}
		}
	}
	return -1;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int u, v, w, m;
	while ((n = nextInt()) && n) {
		h = nextInt();
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
			hotel[i] = false;
			rep(j, h + 3) {
				d[i][j] = INF;
				flag[i][j] = false;
			}
		}
		rep(i, h) hotel[nextInt()] = true;
		hotel[1] = hotel[n] = false;
		m = nextInt();
		while (m--) {
			u = nextInt(); v = nextInt(); w = nextInt();
			adj[u].pb(ii(v, w));
			adj[v].pb(ii(u, w));
		}
		printf("%d\n", dijkstra());
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet