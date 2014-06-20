//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1138 - Trailing Zeroes (III) 
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
#define maxN 100000

int cal(int n, int k) {
	int res = 0, kk = k;
	while (kk <= n) {
		res += n / kk;
		kk *= k;
	}
	return res;
}

int get(int n) { return min(cal(n, 2), cal(n, 5)); }

int main() {
	#ifndef ONLINE_JUDGE
	//freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, m;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d", &m);
		int lo = 5, hi = 2000111222, res = INF;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			int fmid = get(mid);
			if (fmid >= m) {
				hi = mid - 1;
				if (fmid == m) res = min(res, mid);
			}
			else lo = mid + 1;
		}
		printf("Case %d: ", ++caseNo);
		if (res != INF) printf("%d\n", res);
		else puts("impossible");
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet