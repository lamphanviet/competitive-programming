//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10382 - Watering Grass
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
#define maxN 10111

int n, m, w;
vector< pair<double, double> > seg;

int solve() {
	int res = 0;
	double y = 0.0;
	for (int i = 0; i < seg.size(); i++)
		seg[i].ss = -seg[i].ss;
	for (int i = 0; i < seg.size(); ) {
		if (y + eps >= m) return res;
		if (seg[i].ss + eps <= y) {
			i++; continue;
		}
		if (seg[i].ff - eps > y) return -1;
		int j = i, u = i;
		while (j < seg.size() && seg[j].ff - eps <= y) {
			if (seg[j].ss > seg[u].ss) u = j;
			j++;
		}
		y = seg[u].ss;
		i = u + 1;
		res++;
	}
	if (y + eps >= m) return res;
	return -1;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int p, r;
	while (scanf("%d %d %d", &n, &m, &w) != EOF) {
		seg.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &p, &r);
			if (2.0 * r < w) continue;
			double d = sqrt(sqr((int64)r) - sqr((int64)w / 2.0));
			seg.pb(make_pair(p - d, -p - d));
		}
		sort(all(seg));
		printf("%d\n", solve());
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet