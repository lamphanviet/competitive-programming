//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1131 - Just Two Functions 
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

int mod;
struct Matrix {
	int a[6][6];
	Matrix() {
		rep(i, 6) rep(j, 6)
			a[i][j] = 0;
	}
	Matrix multi(Matrix m) {
		Matrix res;
		rep(i, 6) rep(j, 6) rep(k, 6) {
			res.a[i][j] += a[i][k] * m.a[k][j];
			res.a[i][j] %= mod;
		}
		return res;
	}
};
int a1, b1, c1, a2, b2, c2, f[3], g[3];

Matrix powMod(Matrix n, int k) {
	if (k == 1) return n;
	Matrix res = powMod(n, k / 2);
	res = res.multi(res);
	if (k & 1) return res.multi(n);
	return res;
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	Matrix base;
	int cases, caseNo = 0, n, m;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d %d", &a1, &b1, &c1);
		scanf("%d %d %d", &a2, &b2, &c2);
		rep(i, 3) scanf("%d", &f[i]);
		rep(i, 3) scanf("%d", &g[i]);
		scanf("%d %d", &mod, &m);
		rep(i, 3)
			f[i] %= mod, g[i] %= mod;
		base.a[0][0] = a1; base.a[0][1] = b1; base.a[0][5] = c1;
		base.a[1][0] = base.a[2][1] = 1;
		base.a[3][2] = c2; base.a[3][3] = a2; base.a[3][4] = b2;
		base.a[4][3] = base.a[5][4] = 1;
		
		printf("Case %d:\n", ++caseNo);
		while (m--) {
			scanf("%d", &n);
			if (n <= 2) printf("%d %d\n", f[n], g[n]);
			else {
				Matrix res = powMod(base, n - 2);
				int x = 0, y = 0;
				rep(i, 3) {
					x += res.a[0][i] * f[2 - i];
					y %= mod;
					x += res.a[0][i + 3] * g[2 - i];
					x %= mod;
					y += res.a[3][i] * f[2 - i];
					y %= mod;
					y += res.a[3][i + 3] * g[2 - i];
					y %= mod;
				}
				printf("%d %d\n", x, y);
			}
		}
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */