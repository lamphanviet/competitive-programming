//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10927 - Bright Lights
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

struct Point{
    int x, y, h;
    Point() {}
} p[maxN];
int n;

bool cmp(Point a, Point b) {
    int64 x1 = a.x, y1 = a.y;
    int64 x2 = b.x, y2 = b.y;
    int64 a1 = x1 * y2;
    int64 a2 = x2 * y1;
    if (a1 == a2) {
        return x1 * x1 + y1 * y1 < x2 * x2 + y2 * y2;
    }
    return a1 < a2;
}

bool same(Point a , Point b) {
    int64 x1 = a.x, y1 = a.y;
    int64 x2 = b.x, y2 = b.y;
    int64 a1 = x1 * y2;
    int64 a2 = x2 * y1;
    return a1 == a2;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif
	int caseNo = 0;
	while (scanf("%d", &n) && n) {
        rep(i, n) {
            scanf("%d %d %d", &p[i].x, &p[i].y, &p[i].h);
        }
        sort(p, p + n, cmp);
        vii res;
        
        int curH = p[0].h;
        fr(i, 1, n - 1) {
            if (same(p[i], p[i - 1])) {
                if (p[i].h <= curH) {
                    res.pb(ii(p[i].x, p[i].y));
                }
                else curH = max(curH, p[i].h);
            }
            else curH = p[i].h;
        }
        
        sort(all(res));
        printf("Data set %d:\n", ++caseNo);
        if (!res.size()) puts("All the lights are visible.");
        else {
            puts("Some lights are not visible:");
            rep(i, res.size()) {
                printf("x = %d, y = %d", res[i].ff, res[i].ss);
                if (i == res.size() - 1) putchar('.');
                else putchar(';');
                puts("");
            }
        }
    }
	return 0;
}

// Copyright (C) 2012, LamPhanViet
