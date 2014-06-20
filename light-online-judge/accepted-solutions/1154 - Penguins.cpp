//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 
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
#define maxN 222

int n, st, f, p[maxN];
int cost[maxN][maxN], jumps[maxN], peng[maxN];
bool cnt[maxN][maxN];
double x[maxN], y[maxN], maxDist;
vi adj[maxN];

double dist(double x1, double y1, double x2, double y2) {
	x1 -= x2; y1 -= y2;
	return sqrt(x1 * x1 + y1 * y1);
}

int augment(int v, int minEdge) {
	if (v == st) f = minEdge;
	else if (p[v] != -1) {
		int u = p[v];
		augment(u, min(minEdge, cost[u][v]));
		cost[u][v] -= f; cost[v][u] += f;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, totalPeng;
	for (scanf("%d", &cases); cases--; ) {
		totalPeng = 0;
		scanf("%d %lf", &n, &maxDist);
		fill(cnt, false);
		fr(i, 1, n) {
			scanf("%lf %lf", &x[i], &y[i]);
			fr(j, 1, i - 1)
				cnt[i][j] = cnt[j][i] = dist(x[i], y[i], x[j], y[j]) <= maxDist;
			scanf("%d %d", &peng[i], &jumps[i]);
			totalPeng += peng[i];
		}
		
		st = n + n + 1;
		vi res;
		
		fr(i, 1, st) adj[i].clear();
		fr(i, 1, n) {
			adj[st].pb(i);
			adj[i].pb(st);
			fr(j, 1, n) if (cnt[i][j])
				adj[i + n].pb(j), adj[j].pb(i + n);
			adj[i].pb(i + n);
			adj[i + n].pb(i);
		}
		
		fr(nd, 1, n) {
			int mf = 0;
			fill(cost, 0);
			fr(i, 1, n) {
				cost[st][i] = peng[i];
				fr(j, 1, n)
					cost[i + n][j] = cnt[i][j] ? INF : 0;
				cost[i][i + n] = jumps[i];
			}
			cost[st][nd] = 0;
			while (true) {
				f = 0;
				queue<int> q; q.push(st);
				fr(i, 1, st) p[i] = -1;
				p[st] = 0;
				while (!q.empty()) {
					int u = q.front(); q.pop();
					if (u == nd) break;
					rep(i, adj[u].size()) {
						int v = adj[u][i];
						if (cost[u][v] > 0 && p[v] == -1)
							p[v] = u, q.push(v);
					}
				}
				augment(nd, INF);
				if (f == 0) break;
				mf += f;
			}
			if (mf >= totalPeng - peng[nd]) res.pb(nd);
		}
		printf("Case %d:", ++caseNo);
		if (res.size()== 0) puts(" -1");
		else {
			rep(i, res.size())
				printf(" %d", res[i] - 1);
			puts("");
		}
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */