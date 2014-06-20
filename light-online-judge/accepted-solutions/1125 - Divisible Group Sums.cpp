//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1125 - Divisible Group Sums 
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
#define maxN 202

int n, a[maxN], b[maxN];
int64 f[11][22];

int64 solve(int d, int m) {
	fill(f, 0);
	f[0][0] = 1;
	fr(i, 1, n) {
		b[i] = a[i] % d;
		while (b[i] < 0) b[i] = (b[i] + d) % d;
		frr(j, m - 1, 0) rep(k, d) {
			int kk = (k + b[i]) % d;
			f[j + 1][kk] += f[j][k];
		}
	}
	return f[m][0];
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, q, d, m;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d", &n, &q);
		fr(i, 1, n) scanf("%d", &a[i]);
		printf("Case %d:\n", ++caseNo);
		while (q--) {
			scanf("%d %d", &d, &m);
			printf("%lld\n", solve(d, m));
		}
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */