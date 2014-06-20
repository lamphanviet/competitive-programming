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

double check(double x, double y) {
	if (x + x + y + y > 400.0 + eps) return 401.0;
	double k = sqrt(x * x + y * y) / 2.0;
	double alpha = acos((y * y - 2.0 * k * k) / (-2.0 * k * k));
	return 2.0 * (x + alpha * k);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, a, b;
	for (scanf("%d", &cases); cases--; ) {
		scanf(" %d : %d ", &a, &b);
		double lo = eps, hi = 400.0, resX = 0.0, resY = 0.0;
		rep(_, 500) {
			double x = (lo + hi) / 2.0;
			double y = b * x / (double)a;
			double per = check(x, y);
			if (fabs(per - 400.0) < eps) {
				resX = x; resY = y;
				break;
			}
			if (per > 400.0) hi = x;
			else lo = x;
		}
		printf("Case %d: %.12lf %.12lf\n", ++caseNo, resX, resY);
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */