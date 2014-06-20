//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 132 - Bumpy Objects
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
#define eps 1e-4
#define maxN 1001

int n, res;
double x[maxN], y[maxN], sx, sy;

double dist(double x1, double y1, double x2, double y2) {
	x1 -= x2; y1 -= y2;
	return sqrt(x1 * x1 + y1 * y1);
}

void solve() {
	double a, b, c, a1, b1, c1;
	rep(i, n) fr(j, i + 1, n) {
		a = y[i] - y[j];
		b = x[j] - x[i];
		c = x[i] * y[j] - x[j] * y[i];
		int tmpRes = max(i, j), side = 0;
		rep(k, n) if (k != i && k != j) {
			double val = a * x[k] + b * y[k] + c;
			if (val > 0) side |= 1;
			if (val < 0) side |= 2;
			if (side == 3) break;
			if (val == 0) tmpRes = max(tmpRes, k);
		}
		if (side == 3) continue;
		double dij = dist(x[i], y[i], x[j], y[j]);
		double dis = dist(x[i], y[i], sx, sy);
		double djs = dist(x[j], y[j], sx, sy);
		double dd = fabs(a * sx + b * sy + c) / sqrt(a * a + b * b);
		double d1 = sqrt(sqr(dis) - sqr(dd));
		double d2 = sqrt(sqr(djs) - sqr(dd));
		if (fabs(d1 + d2 - dij) < eps)
			res = min(res, tmpRes);
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	string name = "";
	while (cin >> name && name != "#") {
		cout << name;
		scanf(" %lf %lf ", &sx, &sy);
		n = 0;
		while (scanf("%lf %lf", &x[n], &y[n]))
			if (x[n] || y[n]) n++;
			else break;
		res = n - 1;
		fr(i, name.length(), 19)
			putchar(' ');
		solve();
		printf("%d\n", res + 1);
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */