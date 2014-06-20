//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1239 - Convex Fence
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
#define eps 1e-10
#define maxN 50005

struct Point {
	int64 x, y;
	Point() {}
	Point(int64 xx, int64 yy) { x = xx; y = yy; }
	void read() { scanf("%lld %lld", &x, &y); }
	int64 dist(Point a) {
		a.x -= x; a.y -= y;
		return a.x * a.x + a.y * a.y;
	}
	bool operator < (const Point &p) const {
		if (y == p.y) return (x > p.x);
		return (y < p.y);
	}
} p[maxN];

int n, d;

int ccw(Point p1, Point p2, Point p3) {
	int64 a1, a2, b1, b2, t;
	a1 = p2.x - p1.x;
	b1 = p2.y - p1.y;
	a2 = p3.x - p2.x;
	b2 = p3.y - p2.y;
	t = a1 * b2 - a2 * b1;
	if (t == 0) return 0;
	return (t > 0) ? -1 : 1;
}

bool lower(Point a, Point b) {
	int64 a1, b1, a2, b2;
	a1 = a.x - p[1].x;
	b1 = a.y - p[1].y;
	a2 = b.x - p[1].x;
	b2 = b.y - p[1].y;
	return (a1 * b2 > a2 * b1);
}

int graham() {
	if (n <= 2) return n;
	sort(p + 2, p + n + 1, lower);
	int m = 2;
	fr(i, 3, n) {
		bool chosen = true;
		while (m >= 2) {
			int turn = ccw(p[m - 1], p[m], p[i]);
			if (turn < 0) break; // turn left
			if (turn == 0) {
				chosen = false;
				if (p[m - 1].dist(p[m]) < p[m - 1].dist(p[i]))
					p[m] = p[i];
				break;
			}
			m--;
		}
		if (chosen) p[++m] = p[i];
	}
	return m;
}

double angle(Point A, Point B, Point C) {
	double a = sqrt(B.dist(C)), b = sqrt(A.dist(C)), c = sqrt(A.dist(B));
	double x = (a * a - b * b - c * c);
	double y = -2.0 * b * c;
	return acos(x / y);
}

double perimeter() {
	if (n == 1) return 2.0 * PI * d;
	if (n == 2) return 2.0 * (PI * d + sqrt(p[1].dist(p[2])));
	double res = 0.0;
	fr(i, 1, n) {
		int j = i % n + 1, k = i - 1;
		res += sqrt(p[i].dist(p[j]));
	}
	res += 2.0 * PI * d;
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d", &n, &d);
		int u = 1;
		fr(i, 1, n) {
			p[i].read();
			if (p[i] < p[u]) u = i;
		}
		swap(p[1], p[u]);
		n = graham();
		printf("Case %d: %.8lf\n", ++caseNo, perimeter());
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */