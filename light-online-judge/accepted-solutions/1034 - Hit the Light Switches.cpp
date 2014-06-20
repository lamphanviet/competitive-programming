//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1034 - Hit the Light Switches 
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
#define maxN 10001

int n, nRegion, region[maxN], number[maxN], low[maxN], counter;
vi adj[maxN];
stack<int> s;
bool flag[maxN];

void dfs(int u) {
	s.push(u);
	number[u] = low[u] = ++counter;
	rep(i, adj[u].size()) {
		int v = adj[u][i];
		if (region[v] != -1) continue;
		if (number[v])
			low[u] = min(low[u], number[v]);
		else {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
	}
	if (number[u] == low[u]) {
		int v;
		do {
			v = s.top(); s.pop();
			region[v] = nRegion;
		} while (v != u);
		nRegion++;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int m, u, v;
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d", &n, &m);
		fr(i, 1, n) {
			number[i] = 0;
			region[i] = -1;
			adj[i].clear();
			flag[i] = true;
		}
		flag[0] = true;
		counter = nRegion = 0;
		while (m--) {
			scanf("%d %d", &u, &v);
			adj[u].pb(v);
		}
		nRegion = 0;
		fr(i, 1, n)
			if (number[i] == 0) dfs(i);
		fr(i, 1, n)
			rep(j, adj[i].size()) {
				v = adj[i][j];
				if (region[i] != region[v])
					flag[region[v]] = false;
			}
		int res = 0;
		rep(i, nRegion)
			if (flag[i]) res++;
		printf("Case %d: %d\n", ++caseNo, res);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet