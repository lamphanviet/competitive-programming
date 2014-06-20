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
#define eps 1e-7
#define maxN 100111

struct Point {
    int64 x, y;
    Point() {}
    Point(int64 xx, int64 yy) { x = xx; y = yy; }
    bool operator < (const Point &p) const {
        if (y == p.y) return (x > p.x);
        return y < p.y;
    }
    int64 dist(Point p) {
        p.x -= x; p.y -= y;
        return p.x * p.x + p.y * p.y;
    }
    void read() { scanf(" %lld %lld ", &x, &y); }
} p[maxN];
int n;

int ccw(Point p1, Point p2, Point p3) {
    int64 a1, b1, a2, b2, t;
    a1 = p2.x - p1.x;
    b1 = p2.y - p1.y;
    a2 = p3.x - p2.x;
    b2 = p3.y - p2.y;
    t = a1 * b2 - a2 * b1;
    if (t == 0) return 0;
    return (t > 0) ? -1 : 1;
}

bool lower(Point p1, Point p2) {
    int64 a1, b1, a2, b2;
    a1 = p1.x - p[0].x;
    b1 = p1.y - p[0].y;
    a2 = p2.x - p[0].x;
    b2 = p2.y - p[0].y;
    return (a1 * b2 > a2 * b1);
}

int graham() {
    if (n <= 2) return n;
    int m = 0;
    rep(i, n) if (p[i] < p[m]) m = i;
    swap(p[0], p[m]);
    sort(p + 1, p + n, lower);
    m = 2;
    fr(i, 2, n - 1) {
        bool chosen = true;
        while (m >= 2) {
            int turn = ccw(p[m - 2], p[m - 1], p[i]);
            if (turn < 0) break;
            if (turn == 0) {
                if (p[m - 2].dist(p[i]) >= p[m - 2].dist(p[m - 1]))
                    p[m - 1] = p[i];
                chosen = false;
                break;
            }
            m--;
        }
        if (chosen) p[m++] = p[i];
    }
    return m;
}

double solve() {
    n = graham();
    // printf("size %d\n", n); rep(i, n) printf("%lld %lld\n", p[i].x, p[i].y);
    if (n <= 2) return 0.0;
    double res = PI;
    rep(i, n) {
        int j = (i + 1) % n;
        int k = (i + n - 1) % n;
        double a = sqrt(p[j].dist(p[k]));
        double b = sqrt(p[i].dist(p[j]));
        double c = sqrt(p[i].dist(p[k]));
        double alpha = acos((a * a - b * b - c * c) / (-2.0 * b * c));
        res = min(res, alpha);
    }
    return res / PI * 180.0;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    int cases, caseNo = 0;
    for (scanf("%d", &cases); cases--; ) {
        scanf("%d", &n);
        rep(i, n) p[i].read();
        printf("Case %d: %.12lf\n", ++caseNo, solve());
    }
    return 0;
}

/* Copyright (C) 2012, LamPhanViet */
