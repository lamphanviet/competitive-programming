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
#define maxN 20

int n, a[maxN], m, k;
vi set1, set2;

void buildSet(int nd, int i, int value, vi &s) {
	s.pb(value);
	if (i >= nd) return;
	buildSet(nd, i + 1, value + 0, s);
	buildSet(nd, i + 1, value + a[i], s);
	buildSet(nd, i + 1, value + 2 * a[i], s);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d", &n, &k);
		rep(i, n) scanf("%d", &a[i]);
		set1.clear(); set2.clear();
		buildSet(n / 2 + 1, 0, 0, set1); buildSet(n, n / 2 + 1, 0, set2);
		sort(all(set2));
		bool ok = false;
		for (int i = 0; i < set1.size() && !ok; i++) {
			int lo = 0, hi = set2.size() - 1, val = k - set1[i];
			while (!ok && lo <= hi) {
				int mid = (lo + hi) / 2;
				if (set2[mid] == val)
					ok = true;
				else if (val > set2[mid])
					lo = mid + 1;
				else hi = mid - 1;
			}
		}
		printf("Case %d: %s\n", ++caseNo, ok ? "Yes" : "No");
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet