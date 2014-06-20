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
#define INF 100
#define eps 1e-7
#define maxN 222

int n, D, d[maxN], st, nd, f;
int c[maxN][maxN], p[maxN], tmpC[maxN][maxN];
char tp[maxN];

void augment(int v, int minDist) {
	if (v == st) f = minDist;
	else if (p[v] != -1) {
		augment(p[v], min(minDist, tmpC[p[v]][v]));
		tmpC[p[v]][v] -= f; tmpC[v][p[v]] += f;
	}
}

inline int dist(int i, int j) {
	return abs(d[i] - d[j]);
}

bool accept(int maxDist) {
	memcpy(tmpC, c, sizeof(c));
	int mf = 0;
	do {
		f = 0;
		queue<int> q; q.push(st);
		fr(i, 1, nd) p[i] = -1; p[st] = 0;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (u == nd) break;
			fr(v, 1, nd)
				if (tmpC[u][v] > 0 && dist(u, v) <= maxDist && p[v] == -1)
					p[v] = u, q.push(v);
		}
		augment(nd, INF);
		mf += f;
		if (mf >= 2) return true;
	} while (f);
	return false;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d", &n, &D);
		fr(i, 1, n) {
			scanf(" %c-%d ", &tp[i], &d[i]);
			d[i + n] = d[i]; tp[i + n] = tp[i];
		}
		st = 2 * n + 1; nd = st + 1;
		tp[st] = tp[nd] = 'B';
		d[st] = 0; d[nd] = D;
		
		fill(c, 0);
		fr(i, 1, n) {
			if (tp[i] == 'B') {
				fr(j, i + 1, n) c[i][j] = INF;
				c[i][nd] = INF;
				c[st][i] = INF;
			}
			else {
				c[i][i + n] = 1;
				fr(j, i + 1, n)
				c[i + n][j] = 1;
				c[st][i] = 1;
				c[i + n][nd] = 1;
			}
		}
		
		int res = D, lo = 0, hi = D;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (accept(mid))
				res = mid, hi = mid - 1;
			else lo = mid + 1;
		}
		printf("Case %d: %d\n", ++caseNo, res);
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */