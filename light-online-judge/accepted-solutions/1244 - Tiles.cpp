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
#define mod 10007

struct Matrix {
	int a[3][3];
	Matrix() {
		rep(i, 3) rep(j, 3)
			a[i][j] = 0;
	}
	Matrix multi(Matrix m) {
		Matrix res;
		rep(i, 3) rep(j, 3) rep(k, 3) {
			res.a[i][j] += a[i][k] * m.a[k][j];
			res.a[i][j] %= mod;
		}
		return res;
	}
};

Matrix powMod(Matrix n, int k) {
	if (k == 1) return n;
	Matrix res = powMod(n, k / 2);
	res = res.multi(res);
	if (k & 1) return res.multi(n);
	return res;
}

int f[] = { 0, 1, 2, 5 };

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	Matrix base;
	base.a[0][0] = 2; base.a[0][2] = 1;
	base.a[1][0] = base.a[2][1] = 1;
	int cases, caseNo = 0, n;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d", &n);
		printf("Case %d: ", ++caseNo);
		if (n <= 3) printf("%d\n", f[n]);
		else {
			Matrix res = powMod(base, n - 3);
			int ans = 0;
			rep(i, 3) {
				ans += res.a[0][i] * f[3 - i];
				ans %= mod;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */