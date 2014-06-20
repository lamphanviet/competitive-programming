//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10870 - Recurrences
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
	int n;
	vector<vi> a;
	Matrix() { }
	Matrix(int _n) {
		n = _n;
		a.resize(n);
		rep(i, n) a[i] = vector<int>(n, 0);
	}
	Matrix multi(Matrix m) {
		Matrix res(n);
		rep(i, n) rep(j, n) rep(k, n) {
			res.a[i][j] += (a[i][k] * (int64)m.a[k][j]) % mod;
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

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int n, d, f[20], a[20];
	while (scanf("%d %d %d", &d, &n, &mod) && (d | n | mod)) {
		fr(i, 1, d) {
			scanf("%d", &a[i]);
			a[i] %= mod;
		}
		fr(i, 1, d) {
			scanf("%d", &f[i]);
			f[i] %= mod;
		}
		if (n <= d) printf("%d\n", f[n]);
		else {
			Matrix base(d);
			rep(i, d) base.a[0][i] = a[i + 1];
			fr(i, 1, d - 1) base.a[i][i - 1] = 1;
			base = powMod(base, n - d);
			int res = 0;
			rep(i, d) {
				res += (base.a[0][i] * (int64)f[d - i]) % mod;
				res %= mod;
			}
			printf("%d\n", res);
		}
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */