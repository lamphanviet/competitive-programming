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
#define INF 1000111222
#define eps 1e-7
#define maxN 1001

const int dx[] = {-3, -2, -2, -1, -1, 1};
const int dy[] = {-1, -1, 1, -3, -2, -2};
int g[maxN][maxN];

inline bool inside(int x, int y) { return (0 <= x && x < maxN && 0 <= y && y < maxN); }

int compute(int x, int y) {
	if (g[x][y] != -1) return g[x][y];
	vi f;
	rep(i, 6) {
		int xx = x + dx[i], yy = y + dy[i];
		if (!inside(xx, yy)) continue;
		if (g[xx][yy] == -1) compute(xx, yy);
		f.pb(g[xx][yy]);
	}
	sort(all(f));
	if (!f.size() || f[0] > 0) {
		return g[x][y] = 0;
	}
	fr(i, 1, f.size() - 1)
		if (f[i - 1] + 1 < f[i]) {
			return g[x][y] = f[i - 1] + 1;
		}
	return g[x][y] = f.back() + 1;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	fill(g, -1);
	g[0][0] = 0;
	rep(i, maxN) fr(j, 0, i)
		if (g[j][i - j] == -1)
			compute(j, i - j);
	int cases, caseNo = 0, n, x, y;
	for (scanf("%d", &cases); cases--; ) {
		int nim = 0;
		scanf("%d", &n);
		rep(i, n) {
			scanf("%d %d", &x, &y);
			nim ^= g[x][y];
		}
		printf("Case %d: ", ++caseNo);
		if (nim) puts("Alice");
		else puts("Bob");
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */