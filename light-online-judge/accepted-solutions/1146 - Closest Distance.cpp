//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1146 - Closest Distance 
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

struct Point {
	double x, y;
	Point() {}
	Point(double xx, double yy) { x = xx; y = yy; }
	double dist(Point p) {
		p.x -= x; p.y -= y;
		return sqrt(p.x * p.x + p.y * p.y);
	}
	void read() { scanf("%lf %lf", &x, &y); }
} a, b, c, d, aa, bb, cc, dd;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		a.read(); b.read(); c.read(); d.read();
		double res = INF;
		rep(_, 50) {
			aa.x = a.x + (b.x - a.x) / 3.0;
			aa.y = a.y + (b.y - a.y) / 3.0;
			bb.x = b.x - (b.x - a.x) / 3.0;
			bb.y = b.y - (b.y - a.y) / 3.0;
			cc.x = c.x + (d.x - c.x) / 3.0;
			cc.y = c.y + (d.y - c.y) / 3.0;
			dd.x = d.x - (d.x - c.x) / 3.0;
			dd.y = d.y - (d.y - c.y) / 3.0;
			double fA = aa.dist(cc), fB = bb.dist(dd);
			res = min(res, min(fA, fB));
			if (fA > fB)
				a = aa, c = cc;
			else b = bb, d = dd;
		}
		printf("Case %d: %.12lf\n", ++caseNo, res);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet