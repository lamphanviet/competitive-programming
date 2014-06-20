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
#define maxN 50001
#define maxLN 20

int ar[5];
char buff[100];
void readLine() {
	gets(buff);
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
void printLine(int n) {
	int m = 0;
	do {
		buff[m++] = n % 10 + 48;
		n /= 10;
	} while (n);
	while (m--) putchar(buff[m]);
	putchar('\n');
}

int n, lab[maxN], depth[maxN];
iii e[maxN << 1];
vii adj[maxN];
int P[maxN][maxLN], L[maxN][maxLN], k;

int getRoot(int u) {
	if (lab[u] < 0) return u;
	return lab[u] = getRoot(lab[u]);
}

void unionSet(int r1, int r2) {
	int x = lab[r1] + lab[r2];
	if (lab[r1] > lab[r2]) {
		lab[r1] = r2;
		lab[r2] = x;
	}
	else {
		lab[r1] = x;
		lab[r2] = r1;
	}
}

void dfs(int u, int p, int cost, int lvl) {
	P[u][0] = p;
	L[u][0] = cost;
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
				L[i][j] = L[i][j - 1];
			}
			else {
				P[i][j] = P[P[i][j - 1]][j - 1];
				L[i][j] = max(L[i][j - 1], L[P[i][j - 1]][j - 1]);
			}
	}
}

int solve(int u, int v) {
	int res = 0;
	if (depth[v] > depth[u]) swap(u, v);
	frr(j, k, 0)
		if (P[u][j] != -1 && depth[u] - BIT(j) >= depth[v]) {
			res = max(res, L[u][j]);
			u = P[u][j];
		}
	if (u == v) return res;
	frr(j, k, 0)
		if (P[u][j] != -1 && P[u][j] != P[v][j]) {
			res = max(res, max(L[u][j], L[v][j]));
			u = P[u][j]; v = P[v][j];
		}
	res = max(res, L[u][0]);
	res = max(res, L[v][0]);
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	readLine();
	int cases, caseNo = 0, m, u, v;
	for (cases = ar[0]; cases--; ) {
		readLine(); n = ar[0], m = ar[1];
		fr(i, 1, n) {
			lab[i] = -1;
			adj[i].clear();
		}
		rep(i, m) {
			readLine();
			e[i].ss.ff = ar[0];
			e[i].ss.ss = ar[1];
			e[i].ff = ar[2];
		}
		sort(e, e + m);
		for (int i = 0, j = 0; i < m && j < n - 1; i++) {
			u = getRoot(e[i].ss.ff);
			v = getRoot(e[i].ss.ss);
			if (u != v) {
				unionSet(u, v);
				j++;
				adj[e[i].ss.ff].pb(ii(e[i].ss.ss, e[i].ff));
				adj[e[i].ss.ss].pb(ii(e[i].ss.ff, e[i].ff));
			}
		}
		buildLCA();
		printf("Case %d:\n", ++caseNo);
		readLine(); m = ar[0];
		while (m--) {
			readLine();
			printLine(solve(ar[0], ar[1]));
		}
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */