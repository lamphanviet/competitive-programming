//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 11881 - Internal Rate of Return
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

#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for (int i = (n) - 1; i >= 0; i--)
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
#define eps 1e-10
#define maxN 15

int n, c[maxN];

double npv(double irr) {
	irr = 1.0 + irr;
	double res = c[0], ir = irr;
	for (int i = 1; i <= n; i++) {
		res += c[i] / ir;
		ir *= irr;
	}
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	while (scanf("%d", &n) && n) {
		bool allZero = true;
		for (int i = 0; i <= n; i++) {
			scanf("%d", &c[i]);
			if (c[i]) allZero = false;
		}
		if (allZero) puts("Too many");
		else {
			double lo = -1.0 + eps, hi = INF, res = -2.0;
			for (int i = 0; i < 1000; i++) {
				double mid = (lo + hi) / 2.0;
				double fMid = npv(mid);
		//		printf("mid %lf %lf\n", mid, fMid);
				if (fabs(fMid) < eps) {
					res = mid;
				}
				else if (fMid > 0.0)
					lo = mid;
				else hi = mid;
			}
			if (res <= -1.0) puts("No");
			else printf("%.2lf\n", res + eps);
		}
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet