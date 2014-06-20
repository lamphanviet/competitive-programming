//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1101 - A Secret Mission
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
#define maxN 100001
#define maxLN 20

int ar[5];
char buff[100];
void readLine() {
	gets(buff);
	//puts(buff);
	int i = 0, len = strlen(buff), m = 0;
	while (i < len)
		if (buff[i] != ' ') {
			ar[m] = 0;
			while (i < len && buff[i] != ' ')
				ar[m] = ar[m] * 10 + buff[i++] - 48;
			m++;
		}
		else i++;
}
void print(int n) {
	int m = 0;
	do {
		buff[m++] = n % 10 + 48;
		n /= 10;
	} while (n);
	while (m--) putchar(buff[m]);
}

int n, depth[maxN];
vii adj[maxN];
int P[maxN][maxLN], maxCost[maxN][maxLN], minCost[maxN][maxLN], k;

void dfs(int u, int p, int cost, int lvl) {
	P[u][0] = p;
	maxCost[u][0] = minCost[u][0] = cost;
	depth[u] = lvl;
	rep(i, adj[u].size()) {
		int v = adj[u][i].ff;
		if (v != p) dfs(v, u, adj[u][i].ss, lvl + 1);
	}
}

void buildLCA() {
	dfs(1, -1, 0, 0);
	for (k = 0; BIT(k + 1) <= n; k++);
	fr(j, 1, k) {
		fr(i, 1, n)
			if (P[i][j - 1] == -1) {
				P[i][j] = P[i][j - 1];
				maxCost[i][j] = maxCost[i][j - 1];
				minCost[i][j] = minCost[i][j - 1];
			}
			else {
				P[i][j] = P[P[i][j - 1]][j - 1];
				maxCost[i][j] = max(maxCost[i][j - 1], maxCost[P[i][j - 1]][j - 1]);
				minCost[i][j] = min(minCost[i][j - 1], minCost[P[i][j - 1]][j - 1]);
			}
	}
}

ii solve(int u, int v) {
	int mn = INF, mx = 0;
	if (depth[v] > depth[u]) swap(u, v);
	frr(j, k, 0)
		if (P[u][j] != -1 && depth[u] - BIT(j) >= depth[v]) {
			mx = max(mx, maxCost[u][j]);
			mn = min(mn, minCost[u][j]);
			u = P[u][j];
		}
	if (u == v) return ii(mn, mx);
	frr(j, k, 0)
		if (P[u][j] != -1 && P[u][j] != P[v][j]) {
			mx = max(mx, max(maxCost[u][j], maxCost[v][j]));
			mn = min(mn, min(minCost[u][j], minCost[v][j]));
			u = P[u][j]; v = P[v][j];
		}
	mx = max(mx, max(maxCost[u][0], maxCost[v][0]));
	mn = min(mn, min(minCost[u][0], minCost[v][0]));
	return ii(mn, mx);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	readLine();
	int cases, caseNo = 0, m, u, v, w;
	for (cases = ar[0]; cases--; ) {
		gets(buff); // blank line
		readLine(); n = ar[0];
		fr(i, 1, n) {
			adj[i].clear();
		}
		rep(i, n - 1) {
			readLine();
			u = ar[0]; v = ar[1]; w = ar[2];
			adj[u].pb(ii(v, w));
			adj[v].pb(ii(u, w));
		}
		buildLCA();
		printf("Case %d:\n", ++caseNo);
		readLine(); m = ar[0];
		while (m--) {
			readLine();
			ii res = solve(ar[0], ar[1]);
			print(res.ff); putchar(' '); print(res.ss);
			putchar('\n');
		}
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */