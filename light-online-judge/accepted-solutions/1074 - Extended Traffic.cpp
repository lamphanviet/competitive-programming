//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1074 - Extended Traffic 
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
#define maxN 202

int n, busy[maxN], dist[maxN][maxN], d[maxN];

void solve() {
	int d2[maxN];
	fr(i, 1, n) d2[i] = d[i];
	fr(i, 1, n) fr(j, 1, n)
		d2[j] = min(d2[j], d2[i] + dist[i][j]);
	fr(i, 1, n)
		if (d[i] == INF) d[i] = -1;
		else if (d2[i] < d[i]) d[i] = -1;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, m, u, v;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d", &n);
		fr(i, 1, n) {
			scanf("%d", &busy[i]);
			fr(j, 1, n) dist[i][j] = INF;
			d[i] = INF;
			dist[i][i] = 0;
		}
		scanf("%d", &m);
		while (m--) {
			scanf("%d %d", &u, &v);
			dist[u][v] = -(busy[u] - busy[v]) *(busy[u] - busy[v]) * (busy[u] - busy[v]);
		}
		d[1] = 0;
		rep(_, n) {
			fr(i, 1, n) fr(j, 1, n)
				d[j] = min(d[j], d[i] + dist[i][j]);
		}
		solve();
		scanf("%d", &m);
		printf("Case %d:\n", ++caseNo);
		while (m--) {
			scanf("%d", &u);
			if (d[u] < 3) puts("?");
			else printf("%d\n", d[u]);
		}
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet