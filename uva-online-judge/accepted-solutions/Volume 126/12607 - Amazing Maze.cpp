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
#define maxN 111

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };
int n, m, d[10][4][maxN][maxN], npoints, idx[10];
ii points[11];
char s[maxN][maxN];
int waitCost[4][4];

inline bool inside(int x, int y) { return (0 <= x && x < n && 0 <= y && y < m); }

void dijkstra(int p, int k) {
	rep(i, n) rep(j, m) d[p][k][i][j] = INF;
	int x = points[p].ff, y = points[p].ss;
	set<iii> q;
	d[p][k][x][y] = 0;
	q.insert(mp(d[p][k][x][y], mp(x, y)));
	while (!q.empty()) {
		iii top = *q.begin(); q.erase(top);
		x = top.ss.ff; y = top.ss.ss;
		int curCost = d[p][k][x][y];
		int curDir = (curCost + s[x][y] + k) % 4;
		rep(i, 4) {
			int xx = x + dx[i], yy = y + dy[i];
			if (!inside(xx, yy)) continue;
			int ncost = curCost + waitCost[curDir][i] + 1;
			
			if (d[p][k][xx][yy] > ncost) {
				q.erase(mp(d[p][k][xx][yy], mp(xx, yy)));
				d[p][k][xx][yy] = ncost;
				q.insert(mp(d[p][k][xx][yy], mp(xx, yy)));
			}
		}
	}
}

int solve() {
	int res = INF;
	points[npoints] = mp(0, 0);
	rep(i, npoints + 1) rep(j, 4) dijkstra(i, j);
	rep(i, npoints) idx[i] = i;
	/*rep(i, n) {
		rep(j, m) printf("%5d", d[0][1][i][j]);
		puts("");
	}*/
	do {
		int cost = 0, v, u = npoints, x, y;
		rep(i, npoints) {
			v = idx[i];
			x = points[v].ff, y = points[v].ss;
			cost += d[u][cost % 4][x][y];
			//printf("%d %d %d\n", x, y, cost);
			u = v;
		}
		cost += d[u][cost % 4][n - 1][m - 1];
		res = min(res, cost);
	} while (next_permutation(idx, idx + npoints));
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	rep(i, 4) rep(j, 4)
		waitCost[i][(i + j) % 4] = j;
	while (scanf(" %d %d ", &n, &m) && (n + m)) {
		rep(i, n) {
			scanf(" %s ", s[i]);
			rep(j, m) {
				if (s[i][j] == 'N') s[i][j] = 0;
				else if (s[i][j] == 'E') s[i][j] = 1;
				else if (s[i][j] == 'S') s[i][j] = 2;
				else if (s[i][j] == 'W') s[i][j] = 3;
			}
		}
		scanf(" %d ", &npoints);
		rep(i, npoints) {
			scanf("%d %d", &points[i].ff, &points[i].ss);
			points[i].ff--;
			points[i].ss--;
		}
		printf("%d\n", solve());
	}
	return 0;
}
