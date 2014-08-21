//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 11049 - Basic wall maze
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
#define maxN 10

const int dx[] = { 0, 0, -1, 1 };
const int dy[] = { -1, 1, 0, 0 };
const char dc[] = { 'N', 'S', 'W', 'E' };
int sx, sy, fx, fy;
pair<ii, ii> e[5];
bool direction[5];
const int n = 6;
int dist[maxN][maxN];
ii trace[maxN][maxN];
char path[maxN][maxN];

bool inside(int x, int y) {
	return (1 <= x && x <= n && 1 <= y && y <= n);
}

bool goDoc(int x, int y, int yy, int i) {
	if (y > yy) swap(y, yy);
	if (e[i].ff.ss != y) return true;
	return (!(e[i].ff.ff <= x - 1 && x <= e[i].ss.ff));
}

bool goNgang(int x, int y, int xx, int i) {
	if (x > xx) swap(x, xx);
	if (e[i].ff.ff != x) return true;
	return (!(e[i].ff.ss <= y - 1 && y <= e[i].ss.ss));
}

bool canGo(int x, int y, int i, int xx, int yy) {
	bool ok = true;
	rep(k, 3) {
		if (i >= 2 && direction[k]) ok = ok && goNgang(x, y, xx, k);
		else if (i < 2 && !direction[k]) ok = ok && goDoc(x, y, yy, k);
	}
	return ok;
}

bool bfs() {
	fr(i, 1, n) fr(j, 1, n) {
		dist[i][j] = INF;
		trace[i][j] = ii(0, 0);
		path[i][j] = 0;
	}
	queue<ii> q;
	q.push(ii(sx, sy));
	dist[sx][sy] = 0;
	while (!q.empty()) {
		int x = q.front().ff, y = q.front().ss, xx, yy; q.pop();
		if (x == fx && y == fy) return true;
		rep(i, 4) {
			xx = x + dx[i]; yy = y + dy[i];
			if (!inside(xx, yy)) continue;
			if (dist[xx][yy] == INF && canGo(x, y, i, xx, yy)) {
				trace[xx][yy] = ii(x, y);
				path[xx][yy] = dc[i];
				dist[xx][yy] = dist[x][y] + 1;
				q.push(ii(xx, yy));
			}
		}
	}
	return false;
}

void findPath() {
	string res = "";
	while (path[fx][fy] != 0) {
		res += path[fx][fy];
		int x = trace[fx][fy].ff, y = trace[fx][fy].ss;
		fx = x; fy = y;
	}
	reverse(all(res));
	cout << res << endl;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	while (scanf("%d %d", &sx, &sy) && (sx || sy)) {
		scanf("%d %d", &fx, &fy);
		rep(i, 3) {
			scanf("%d %d", &e[i].ff.ff, &e[i].ff.ss);
			scanf("%d %d", &e[i].ss.ff, &e[i].ss.ss);
			direction[i] = (e[i].ff.ff == e[i].ss.ff);
		}
		bfs();
		findPath();
	}
}

// Copyright (C) 2012, LamPhanViet