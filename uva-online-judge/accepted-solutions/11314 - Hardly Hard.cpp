//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 11314 - Hardly Hard
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
#define INF 10001112221000111222.0
#define eps 1e-7
#define maxN 111

double ax, ay, bx, by, ab, bc;
double res;

double per(double cy, double dx) {
    double cd = sqrt(cy * cy + dx * dx);
    double da = sqrt(sqr(ax - dx) + sqr(ay));
    return ab + bc + cd + da;
}

double fy(double cy) {
	bc = sqrt(sqr(bx) + sqr(by - cy));
    double lo = eps, hi = 10000.0;
    rep(_, 100) {
        double lf = lo + (hi - lo) / 3.0;
        double rg = lf + (hi - lo) / 3.0;
        double flf = per(cy, lf), frg = per(cy, rg);
        if (flf <= frg)
            hi = rg;
        else lo = lf;
    }
    return per(cy, (lo + hi) / 2.0);
}

double solve() {
    ab = sqrt(sqr(ax - bx) + sqr(ay - by));
    double lo = eps, hi = 10000.0;
    res = INF;
    rep(_, 100) {
        double lf = lo + (hi - lo) / 3.0;
        double rg = lf + (hi - lo) / 3.0;
        double flf = fy(lf), frg = fy(rg);
        res = min(res, min(flf, frg));
        if (flf <= frg)
            hi = rg;
        else lo = lf;
    }
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    int cases;
    for (scanf("%d", &cases); cases--; ) {
        scanf("%lf %lf", &ax, &ay);
        scanf("%lf %lf", &bx, &by);
        printf("%.3lf\n", solve());
    }
    return 0;
}

/* Copyright (C) 2012, LamPhanViet */
