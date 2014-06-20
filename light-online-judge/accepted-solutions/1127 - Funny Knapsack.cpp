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
#define maxN 32

int n, w, a[maxN];
vector<int64> v1, v2;

void backTrack(int i, int nd, int64 sum, vector<int64> &v) {
	if (i == nd) v.pb(sum);
	else {
		backTrack(i + 1, nd, sum + a[i], v);
		backTrack(i + 1, nd, sum, v);
	}
}

int solve() {
	if (n == 1) return a[0] <= w ? 2 : 1;
	v1.clear(); v2.clear();
	int m = n / 2;
	backTrack(0, m, 0, v1);
	backTrack(m, n, 0, v2);
	//rep(i, v1.size()) printf("%d ", v1[i]); puts("");
	//rep(i, v2.size()) printf("%d ", v2[i]); puts("");
	sort(all(v2));
	int res = 0;
	rep(i, v1.size()) {
		int64 value = (int64)w - v1[i];
		if (value < 0) continue;
		int lo = 0, hi = v2.size() - 1, pos = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (v2[mid] <= value)
				pos = mid, lo = mid + 1;
			else hi = mid - 1;
		}
		res += pos + 1;
	}
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d", &n, &w);
		rep(i, n) scanf("%d", &a[i]);
		printf("Case %d: %d\n", ++caseNo, solve());
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */