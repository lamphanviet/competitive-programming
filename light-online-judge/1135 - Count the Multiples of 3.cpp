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
#define maxN 100011

int n, m, a[maxN];
int x[maxN * 6], y[maxN * 6], z[maxN * 6];

void build(int p, int lo, int hi) {
	if (lo == hi) {
		x[p] = 1;
		a[lo] = y[p] = z[p] = 0;
		return;
	}
	int mid = (lo + hi) >> 1, c = p << 1;
	build(c, lo, mid);
	build(c + 1, mid + 1, hi);
	x[p] = x[c] + x[c + 1];
}

void update(int p, int lo, int hi, int u, int v) {
	if (hi < u || v < lo) return;
	int mid = (lo + hi) >> 1, c = p << 1;
	if (u <= lo && hi <= v) {
	}
	update(c, lo, mid, u, v);
	update(c + 1, mid + 1, hi, u, v);
	x[p] = x[c] + x[c + 1];
	y[p] = y[c] + y[c + 1];
	z[p] = z[c] + z[c + 1];
}

int get(int p, int lo, int hi, int u, int v) {
	if (hi < u || v < lo) return 0;
	if (u <= lo && hi <= v) return x[p];
	int mid = (lo + hi) >> 1, c = p << 1;
	return get(c, lo, mid, u, v) + get(c + 1, mid + 1, hi, u, v);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, q, u, v;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d", &n, &m);
		build(1, 0, n - 1);
		printf("Case %d:\n", ++caseNo);
		while (m--) {
			scanf("%d %d %d", &q, &u, &v);
			if (!q) update(1, 0, n - 1, u, v);
			else printf("%d\n", get(1, 0, n - 1, u, v));
		}
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet