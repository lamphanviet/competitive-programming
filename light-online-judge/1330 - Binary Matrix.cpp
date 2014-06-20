//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1330 - Binary Matrix 
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

int n, m, sumRow, sumCol;
int c[maxN][maxN], st, nd, f, p[maxN];
vi adj[maxN];

void augment(int v, int minEdge) {
	if (v == st) f = minEdge;
	else if (p[v] != -1) {
		augment(p[v], min(minEdge, c[p[v]][v]));
		c[p[v]][v] -= f; c[v][p[v]] += f;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d", &n, &m);
		st = n + m + 1; nd = st + 1;
		sumRow = sumCol = 0;
		bool ok = true;
		fill(c, 0);
		fr(i, 1, nd) adj[i].clear();
		fr(i, 1, n) {
			scanf("%d", &c[st][i]);
			sumRow += c[st][i];
			if (c[st][i] > m) ok = false;
		}
		
		fr(j, 1, m) {
			scanf("%d", &c[j + n][nd]);
			sumCol += c[j + n][nd];
			if (c[j + n][nd] > n) ok = false;
		}
		
		fr(j, 1, m) {
			adj[j + n].pb(nd);
			adj[nd].pb(j + n);
			fr(i, 1, n) {
				adj[j + n].pb(i);
				c[i][j + n] = 1;
			}
		}
		
		frr(i, n, 1) {
			fr(j, 1, m) {
				adj[i].pb(j + n);
			}
			adj[st].pb(i); adj[i].pb(st);
		}
		
		if (!ok || sumRow != sumCol || sumRow > n * m) {
			printf("Case %d: impossible\n", ++caseNo);
			continue;
		}
		int mf = 0;
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
			mf += f;
		} while (f && mf <= sumCol);
		
		printf("Case %d:", ++caseNo);
		if (mf != sumRow) puts(" impossible");
		else {
			puts("");
			fr(i, 1, n) {
				fr(j, 1, m) printf("%d", 1 - c[i][j + n]);
				puts("");
			}
		}
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */