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
#define maxN 100000
#define mod 1000000000

struct Matrix {
	int a[2][2];
	Matrix() {
		rep(i, 2) rep(j, 2)
			a[i][j] = 0;
	}
	Matrix multi(Matrix &m) {
		Matrix res;
		rep(i, 2) rep(j, 2) rep(k, 2) {
			res.a[i][j] += (a[i][k] * (int64)m.a[k][j]) % mod;
			res.a[i][j] %= mod;
		}
		return res;
	}
} base;

Matrix powMod(Matrix n, int k) {
	if (k == 1) return n;
	Matrix res = powMod(n, k / 2);
	res = res.multi(res);
	if (k & 1) return res.multi(n);
	return res;
}

int solve(int a, int b, int n) {
	if (n == 0) return a;
	if (n == 1) return b;
	Matrix res = powMod(base, n - 1);
	return (res.a[0][0] * (int64)b + res.a[0][1] * (int64)a) % mod;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int a, b, n, m;
	base.a[0][0] = base.a[0][1] = base.a[1][0] = 1;
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d %d %d", &a, &b, &n, &m);
		int res = solve(a, b, n);
		vector<char> s;
		rep(i, m) {
			s.pb(res % 10 + 48);
			res /= 10;
		}
		printf("Case %d: ", ++caseNo);
		while (s.size() > 1 && s.back() == '0') s.pop_back();
		reverse(all(s));
		rep(i, s.size()) putchar(s[i]); puts("");
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */
