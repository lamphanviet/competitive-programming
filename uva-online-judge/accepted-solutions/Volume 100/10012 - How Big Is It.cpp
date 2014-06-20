//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10012 - How Big Is It
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
#define INF 1000111222222299.0
#define eps 1e-6
#define maxN 10

double dist(double R, double r) {
    double diff = fabs(R - r);
    return sqrt(sqr(R + r) - sqr(diff));
}

int n;
double r[maxN], p[maxN];

double solve() {
    if (n == 0) return 0.0;
    if (n == 1) return r[0] * 2.0;
    double res = r[0] * 2.0;
    p[0] = r[0];
    fr(i, 1, n - 1) {
        p[i] = p[i - 1];
        fr(j, 0, i - 1)
            p[i] = max(p[i], max(dist(r[i], r[j]) + p[j], r[i]));
        res = max(res, p[i] + r[i]);
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
        scanf("%d", &n);
        rep(i, n) scanf("%lf", &r[i]);
        sort(r, r + n);
        double res = INF;
        do {
            res = min(res, solve());
        } while (next_permutation(r, r + n));
        printf("%.3lf\n", res);
    }
	return 0;
}

// Copyright (C) 2012, LamPhanViet
