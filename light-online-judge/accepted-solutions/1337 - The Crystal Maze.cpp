//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1337 - The Crystal Maze 
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
#define maxN 505

const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };
int n, m, res[maxN][maxN], counter;
bool vis[maxN][maxN];
char s[maxN][maxN];
vii node;

bool inside(int x, int y) { return (0 <= x && x < n && 0 <= y && y < m); }

void bfs(int x, int y) {
	queue<ii> q;
	q.push(ii(x, y));
	vis[x][y] = true;
	while (!q.empty()) {
		node.pb(q.front());
		x = q.front().ff, y = q.front().ss; q.pop();
		if (s[x][y] == 'C') counter++;
		rep(i, 4) {
			int xx = x + dx[i], yy = y + dy[i];
			if (!inside(xx, yy)) continue;
			if (vis[xx][yy] || s[xx][yy] == '#') continue;
			vis[xx][yy] = true;
			q.push(ii(xx, yy));
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, q, x, y;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d %d ", &n, &m, &q);
		rep(i, n) {
			scanf(" %s ", s[i]);
			rep(j, m) {
				res[i][j] = 0;
				vis[i][j] = false;
			}
		}
		rep(i, n) rep(j, m)
			if (s[i][j] != '#' && !vis[i][j]) {
				node.clear();
				counter = 0;
				bfs(i, j);
				if (counter) {
					rep(k, node.size())
						res[node[k].ff][node[k].ss] = counter;
				}
			}
		printf("Case %d:\n", ++caseNo);
		while (q--) {
			scanf(" %d %d ", &x, &y);
			printf("%d\n", res[x - 1][y - 1]);
		}
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */