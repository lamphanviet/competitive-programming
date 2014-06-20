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
#define INF 2000111222
#define eps 1e-7
#define maxN 100000

struct Point {
	double x, y, z;
	Point() {}
	Point(double xx, double yy, double zz) {
		x = xx; y = yy; z = zz;
	}
	void read() {
		scanf("%lf %lf %lf", &x, &y, &z);
	}
	double dist(Point p) {
		p.x -= x; p.y -= y; p.z -= z;
		return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
	}
} a, b, p;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		a.read(); b.read(); p.read();
		double res = INF;
		rep(_, 50) {
			Point midLeft, midRight;
			midLeft.x = a.x + (b.x - a.x) / 3.0;
			midLeft.y = a.y + (b.y - a.y) / 3.0;
			midLeft.z = a.z + (b.z - a.z) / 3.0;
			midRight.x = b.x - (b.x - a.x) / 3.0;
			midRight.y = b.y - (b.y - a.y) / 3.0;
			midRight.z = b.z - (b.z - a.z) / 3.0;
			double dLeft = p.dist(midLeft), dRight = p.dist(midRight);
			res = min(res, min(dLeft, dRight));
			if (dLeft > dRight)
				a = midLeft;
			else b = midRight;
		}
		printf("Case %d: %.12lf\n", ++caseNo, res);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet