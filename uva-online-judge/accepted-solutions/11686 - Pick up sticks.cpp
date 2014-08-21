//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 11686 - Pick up sticks
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

#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for (int i = (n) - 1; i >= 0; i--)
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
#define maxN 100111

int n, color[maxN];
vi adj[maxN], sortedNode;
bool possible;

void visit(int u) {
	if (!possible) return;
	color[u] = 1;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (color[v] == 0) visit(v);
		else if (color[v] == 1) {
			possible = false;
			return;
		}
	}
	sortedNode.pb(u);
	color[u] = 2;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int m, u, v;
	while (scanf("%d %d", &n, &m) && (n || m)) {
		for (int i = 1; i <= n; i++)
			color[i] = 0, adj[i].clear();
		while (m--) {
			scanf("%d %d", &u, &v);
			adj[u].pb(v);
		}
		possible = true;
		sortedNode.clear();
		for (int i = 1; i <= n && possible; i++)
			if (color[i] == 0) visit(i);
		if (!possible)
			puts("IMPOSSIBLE");
		else {
			for (int i = sortedNode.size() - 1; i >= 0; i--)
				printf("%d\n", sortedNode[i]);
		}
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet