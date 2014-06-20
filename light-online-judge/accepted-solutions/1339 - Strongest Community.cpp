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
#define maxN 100001

int n, c, q, region[maxN], res;
int most[maxN * 5];
ii lf[maxN * 5], rg[maxN * 5];

void buildIT(int p, int lo, int hi) {
	if (lo == hi) {
		most[p] = 1;
		lf[p] = rg[p] = ii(region[lo], 1);
		return;
	}
	int mid = (lo + hi) >> 1, c = p << 1;
	buildIT(c, lo, mid);
	buildIT(c + 1, mid + 1, hi);
	most[p] = max(most[c], most[c + 1]);
	if (rg[c].ff == lf[c + 1].ff)
		most[p] = max(most[p], rg[c].ss + lf[c + 1].ss);
	lf[p] = lf[c];
	if (lf[p].ff == lf[c + 1].ff)
		lf[p].ss += lf[c + 1].ss;
	rg[p] = rg[c + 1];
	if (rg[p].ff == rg[c].ff)
		rg[p].ss += rg[c].ss;
}

pair<ii, ii> get(int p, int lo, int hi, int u, int v) {
	if (hi < u || v < lo) return mp(ii(0, 0), ii(0, 0));
	if (u <= lo && hi <= v) {
		res = max(res, most[p]);
		return mp(lf[p], rg[p]);
	}
	if (lo == hi) return mp(ii(0, 0), ii(0, 0));
	int mid = (lo + hi) >> 1, c = p << 1;
	pair<ii, ii> lfChild = get(c, lo, mid, u, v);
	pair<ii, ii> rgChild = get(c + 1, mid + 1, hi, u, v);
	ii lf1 = lfChild.ff, rg1 = lfChild.ss;
	ii lf2 = rgChild.ff, rg2 = rgChild.ss;
	if (rg1.ff == lf2.ff)
		res = max(res, rg1.ss + lf2.ss);
	if (lf1.ff == lf2.ff)
		lf1.ss += lf2.ss;
	if (rg2.ff == rg1.ff)
		rg2.ss += rg1.ss;
	return mp(lf1, rg2);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, u, v;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d %d", &n, &c, &q);
		fr(i, 1, n) scanf("%d", &region[i]);
		buildIT(1, 1, n);
		printf("Case %d:\n", ++caseNo);
		while (q--) {
			scanf("%d %d", &u, &v);
			res = 1;
			get(1, 1, n, u, v);
			printf("%d\n", res);
		}
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */