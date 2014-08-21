//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 12483 - Toboggan of Marbles - UVa
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
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 1003

struct Point {
  double x, y;
  Point() {}
  Point(double _x, double _y) { x = _x; y = _y; }
  double dist(Point p) {
    p.x -= x; p.y -= y;
    return sqrt(p.x * p.x + p.y * p.y);
  }
};
struct Line {
    Point A, B;
    double a, b, c;
    Line() {}
    Line(Point AA, Point BB) {
        A = AA; B = BB;
        makeLine();
    }
    void makeLine() {
        a = A.y - B.y;
        b = B.x - A.x;
        c = A.x * B.y - B.x * A.y;
    }
    Point getIntersection(Line L) {
        double d = a * L.b - L.a * b;
        double dx = b * L.c - L.b * c;
        double dy = c * L.a - L.c * a;
        if (fabs(d) <= eps) return Point(INF, INF);
        return Point(dx / d, dy / d);
    }
    double dist(Point p) {
        return fabs(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
    }
} line[maxN];

int n, y[maxN], xf[maxN], yf[maxN], L, H;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	while (scanf("%d", &n) != EOF) {
	    scanf("%d %d", &L, &H);
	    double res = INF;
	    fr(i, 1, n) {
	        scanf("%d %d %d", &y[i], &xf[i], &yf[i]);
	        if (i & 1) {
	            line[i] = Line(Point(0, y[i]), Point(xf[i], yf[i]));
	            res = min(res, L - xf[i] + 0.0);
	        }
	        else {
	            line[i] = Line(Point(L, y[i]), Point(xf[i], yf[i]));
	            res = min(res, xf[i] + 0.0);
	        }
	    }
	    fr(i, 1, n - 1) {
	        res = min(res, line[i].B.dist(line[i + 1].A));
	        res = min(res, line[i].B.dist(line[i + 1].B));
	        
	        Line l;
	        l.a = line[i + 1].B.x - line[i + 1].A.x;
	        l.b = line[i + 1].B.y - line[i + 1].A.y;
	        l.c = -(l.a * line[i].B.x + l.b * line[i].B.y);
	        Point p = l.getIntersection(line[i + 1]);
	        double d1 = line[i + 1].A.dist(line[i + 1].B);
	        double d2 = line[i + 1].A.dist(p);
	        if ((0 <= p.x && p.x <= L) && d1 >= d2) {
                res = min(res, line[i + 1].dist(line[i].B));
	        }
	    }
	    printf("%.2lf\n", res);
	}
	return 0;
}
