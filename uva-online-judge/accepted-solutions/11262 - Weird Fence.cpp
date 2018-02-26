lamphanviet/competitive-programming

He has augmented the code so that no one can understand.
1 dim aarrays are converted to 2 dim. 
Names are encrypted
Why code is uploaded in the first place.


//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 11262 - Weird Fence
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
#define maxN 111

int n, k, x[maxN], y[maxN], pr[maxN];
int st, nd, fnet[maxN][maxN], f;
double d[maxN][maxN];
char s[maxN][10];

double dist(int i, int j) {
	double xx = x[i] - x[j], yy = y[i] - y[j];
	return sqrt(xx * xx + yy * yy);
}

void augment(int v, int minEdge) {
	if (v == st) f = minEdge;
	else if (pr[v] != -1) {
		int u = pr[v];
		augment(u, min(minEdge, fnet[u][v]));
		fnet[u][v] -= f; fnet[v][u] += f;
	}
}

int findFlow(int low) {
	fill(fnet, 0);
	fr(i, 1, n) {
		if (s[i][0] == 'b') {
			fnet[st][i] = 1;
			fr(j, 1, n) if (s[j][0] == 'r' && d[i][j] <= low)
				fnet[i][j] = 1;
		}
		else fnet[i][nd] = 1;
	}
	int mf = 0;
	do {
		f = 0;
		fr(i, st, nd) pr[i] = -1;
		queue<int> q;
		q.push(st); pr[st] = 0;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (u == nd) break;
			fr(v, 0, nd)
				if (fnet[u][v] > 0 && pr[v] == -1)
					pr[v] = u, q.push(v);
		}
		augment(nd, INF);
		mf += f;
	} while (f);
	return mf;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases;
	for (scanf("%d ", &cases); cases--; ) {
		scanf("%d %d ", &n, &k);
		int lo = 0, hi = 0, res = INF;
		fr(i, 1, n) {
			scanf("%d %d %s ", &x[i], &y[i], s[i]);
			fr(j, 1, i - 1) {
				d[i][j] = d[j][i] = dist(i, j);
				hi = (int)(d[i][j] + 1.0);
			}
			d[i][i] = 0.0;
		}
		st = 0; nd = n + 1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (findFlow(mid) >= k)
				res = mid, hi = mid - 1;
			else lo = mid + 1;
		}
		if (res == INF) puts("Impossible");
		else printf("%d\n", res);
	}
	return 0;
}
