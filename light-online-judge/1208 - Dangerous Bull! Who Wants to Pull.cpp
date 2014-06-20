//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1208 - Dangerous Bull! Who Wants to Pull
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
#define INF 1000111222.0
#define eps 1e-7
#define maxN 211

struct Point {
	int x, y;
	Point() {}
	Point(int xx, int yy) { x = xx; y = yy; }
	void read() { scanf("%d %d", &x, &y); }
	bool operator == (const Point &p) const {
		return x == p.x && y == p.y;
	}
} bull;
map<ii, int> idx;
vector<Point> vp;
int n, id[maxN];
bool c[maxN][maxN];
double d[maxN][maxN];

int getIndex(Point p) {
	if (idx.count(mp(p.x, p.y)) == 0) {
		vp.pb(p);
		int k = vp.size() - 1;
		idx[mp(p.x, p.y)] = k;
		return k;
	}
	return idx[mp(p.x, p.y)];
}

int ccw(Point p1, Point p2, Point p3) {
	int a1, b1, a2, b2, t;
	a1 = p2.x - p1.x;
	b1 = p2.y - p1.y;
	a2 = p3.x - p2.x;
	b2 = p3.y - p2.y;
	t = a1 * b2 - a2 * b1;
	if (t == 0) return 0;
	return (t > 0) ? -1 : 1;
}

Point p0;
bool lower(Point p1, Point p2) {
	if (p1 == p0) return true;
	if (p2 == p0) return false;
	int a1, b1, a2, b2;
	a1 = p1.x - p0.x;
	b1 = p1.y - p0.y;
	a2 = p2.x - p0.x;
	b2 = p2.y - p0.y;
	return a1 * b2 > a2 * b1;
}

double dist(Point p1, Point p2) {
	p1.x -= p2.x; p1.y -= p2.y;
	return sqrt(p1.x * (double)p1.x + p1.y * (double)p1.y);
}

double solve(vector<Point> p, int pos) {
	p0 = p[pos];
	if (bull.y <= p0.y) return -1.0;
	sort(all(p), lower);
	//if (!(p0 == p[0])) while(1);
	rep(i, n) {
	    rep(j, n) d[i][j] = INF;
		id[i] = getIndex(p[i]);
	}
	d[0][0] = 0.0;
	set<pair<double, ii> > heap;
	heap.insert(mp(d[0][0], mp(0, 0)));
	while (!heap.empty()) {
	    pair<double, ii> top = *heap.begin(); heap.erase(top);
	    int u = top.ss.ff, pu = top.ss.ss;
	    if (pu && c[id[u]][id[0]] && ccw(p[u], p0, bull) == -1)
            return d[u][pu] + dist(p[u], p0);
	    fr(v, u + 1, n - 1) {
	        if (p[v].y < p0.y) continue;
	        if (!c[id[u]][id[v]]) continue;
	        if (ccw(p[u], p[v], bull) != -1) continue;
	        if (ccw(p[pu], p[u], p[v]) > 0) continue;
	        double dd = d[u][pu] + dist(p[u], p[v]);
	        if (d[v][u] > dd) {
	            heap.erase(mp(d[v][u], mp(v, u)));
                d[v][u] = dd;
                heap.insert(mp(d[v][u], mp(v, u)));
	        }
	    }
	}
	return -1.0;
}

int main() {
	#ifndef ONLINE_JUDGE
        freopen("test.inp", "r", stdin);
        //freopen("test.out", "w", stdout);
	#endif
	Point p1, p2;
	int cases, caseNo = 0, u, v;
	for (scanf("%d", &cases); cases--; ) {
		idx.clear(); vp.clear();
		fill(c, false);
		scanf("%d", &n); bull.read();
		rep(i, n) {
			p1.read(); p2.read();
			u = getIndex(p1); v = getIndex(p2);
			c[u][v] = c[v][u] = true;
		}
		
		n = vp.size();
		double res = -1.0;
		rep(i, n) {
			if (n < 3) break;
			double tmpRes = solve(vp, i);
			if (tmpRes >= 0.0) {
				if (res < 0.0) res = tmpRes * 2.0;
				else res = min(res, tmpRes * 2.0);
			}
		}
		printf("Case %d: %.12lf\n", ++caseNo, res);
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */
