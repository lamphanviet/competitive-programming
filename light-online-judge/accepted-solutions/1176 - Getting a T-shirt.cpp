//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1176 - Getting a T-shirt 
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

int st, nd, n, m, f;
int c[maxN][maxN], p[maxN];
vi adj[maxN];

int augment(int v, int minEdge) {
	if (v == st) f = minEdge;
	else if (p[v] != -1) {
		augment(p[v], min(minEdge, c[p[v]][v]));
		c[p[v]][v] -= f; c[v][p[v]] += f;
	}
}

map<string, int> idx;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	string sz1, sz2;
	idx["XXL"] = 1; idx["XL"] = 2; idx["L"] = 3;
	idx["M"] = 4; idx["S"] = 5; idx["XS"] = 6;
	int cases, caseNo = 0, a, b;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d", &n, &m);
		st = m + 6 + 1;
		nd = st + 1;
		fr(i, 1, nd) adj[i].clear();
		fill(c, 0);
		fr(i, 1, m) {
			c[st][i] = 1;
			adj[st].pb(i); adj[i].pb(st);
			cin >> sz1 >> sz2;
			a = idx[sz1] + m; b = idx[sz2] + m;
			c[i][a] = 1; c[i][b] = 1;
			adj[i].pb(a); adj[a].pb(i);
			adj[i].pb(b); adj[b].pb(i);
		}
		fr(i, 1, 6) {
			c[i + m][nd] = n;
			adj[i + m].pb(nd); adj[nd].pb(i + m);
		}
		int mf = 0;
		do {
			f = 0;
			queue<int> q; q.push(st);
			fr(i, 1, nd) p[i] = -1;
			p[st] = 0;
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
		} while (f);
		printf("Case %d: ", ++caseNo);
		puts(mf == m ? "YES" : "NO");
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */