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
#define INF 1111222
#define eps 1e-7
#define maxN 15

const int dx[] = { 1, 1, -1, -1, 2, 2, -2, -2 };
const int dy[] = { 2, -2, 2, -2, 1, -1, 1, -1 };
int n, m, d[maxN][maxN];
char s[maxN][maxN];

bool inside(int x, int y) { return (0 <= x && x < n && 0 <= y && y < m) ; }

int bfs(int x, int y) {
	rep(i, n) rep(j, m) d[i][j] = INF;
	queue<ii> q;
	q.push(ii(x, y));
	d[x][y] = 0;
	while (!q.empty()) {
		x = q.front().ff, y = q.front().ss; q.pop();
		rep(i, 8) {
			int xx = x + dx[i], yy = y + dy[i];
			if (inside(xx, yy) && d[xx][yy] == INF) {
				d[xx][yy] = d[x][y] + 1;
				q.push(ii(xx, yy));
			}
		}
	}
	int res = 0;
	rep(i, n) rep(j, m)
		if (s[i][j] != '.') {
			if (d[i][j] == INF) return INF;
			res += d[i][j] / (s[i][j] - 48);
			if (d[i][j] % (s[i][j] - 48)) res++;
		}
	return min(res, INF);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases = 0, caseNo = 0, res;
	for (scanf(" %d ", &cases); cases--; ) {
		res = INF;
		scanf(" %d %d ", &n, &m);
		rep(i, n) scanf(" %s ", s[i]);
		rep(i, n) rep(j, m)
			res = min(res, bfs(i, j));
		if (res == INF) res = -1;
		printf("Case %d: %d\n", ++caseNo, res);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet