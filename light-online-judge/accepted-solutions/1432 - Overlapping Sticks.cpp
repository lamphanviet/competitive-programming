//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1432 - Overlapping Sticks
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
#define maxN 100005

struct Line {
	ii a, b;
	double A, B, C;
	Line() {}
	void read() {
		scanf("%d %d", &a.ff, &a.ss);
		scanf("%d %d", &b.ff, &b.ss);
		if (a > b) swap(a, b);
		A = a.ss - b.ss;
		B = b.ff - a.ff;
		C = a.ff * (double)b.ss - b.ff * (double)a.ss;
	}
	bool operator < (Line line) const {
		int64 x = (b.ff - a.ff) * (int64)(line.b.ss - line.a.ss);
		int64 y = (b.ss - a.ss) * (int64)(line.b.ff - line.a.ff);
		if (x == y) {
			double xx = A * line.a.ff + B * line.a.ss + C;
			double yy = line.getSide(a.ff, a.ss);
			return xx < yy;
		}
		return x < y;
	}
	bool operator == (Line line) const {
		int64 x = (b.ff - a.ff) * (int64)(line.b.ss - line.a.ss);
		int64 y = (b.ss - a.ss) * (int64)(line.b.ff - line.a.ff);
		if (x == y) {
			double xx = A * line.a.ff + B * line.a.ss + C;
			double yy = line.getSide(a.ff, a.ss);
			return fabs(xx - yy) < eps;
		}
		return false;
	}
	double getSide(int x, int y) { return A * x + B * y + C; }
} line[maxN];

struct BITree {
	int n, m;
	vi tree;
	BITree() {}
	int64 solve(vii a) {
		map<int, int> idx;
		sort(all(a));
		rep(i, a.size()) {
			idx[a[i].ff]++;
			idx[a[i].ss]++;
		}
		m = 0;
		foreach(it, idx) it->second = ++m;
		rep(i, a.size()) {
			a[i].ff = idx[a[i].ff];
			a[i].ss = idx[a[i].ss];
		}
		tree = vector<int>(m + 1, 0);
		n = 0;
		int64 res = 0LL;
		rep(i, a.size()) {
			if (a[i].ff == a[i].ss) continue;
			res += n - get(a[i].ff);
			update(a[i].ss);
			n++;
		}
		return res;
	}
	int get(int i) {
		int res = 0;
		while (i) {
			res += tree[i];
			i -= AND(i, -i);
		}
		return res;
	}
	void update(int i) {
		while (i <= m) {
			tree[i]++;
			i += AND(i, -i);
		}
	}
} myTree;

int n;

int64 solve() {
	int64 res = 0LL;
	sort(line, line + n);
	//rep(i, n) printf("%d %d %d %d\n", line[i].a.ff, line[i].a.ss, line[i].b.ff, line[i].b.ss);
	for (int i = 0, j = 0; i < n; ) {
		while (j < n && line[i] == line[j]) j++;
		//printf("%d - %d\n", i, j);
		bool same = true;
		fr(k, i, j - 1)
			if (line[k].a.ff != line[i].a.ff || line[k].b.ff != line[i].b.ff) {
				same = false;
				break;
			}
		vii a;
		if (same) {
			fr(k, i, j - 1) a.pb(ii(line[k].a.ss, line[k].b.ss));
		}
		else {
			//puts("second");
			fr(k, i, j - 1) a.pb(ii(line[k].a.ff, line[k].b.ff));
		}
		rep(k, a.size()) if (a[k].ff > a[k].ss) swap(a[k].ff, a[k].ss);
		//rep(k, a.size()) printf("(%d %d)", a[k].ff, a[k].ss); puts("");
		res += myTree.solve(a);
		i = j;
	}
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d", &n);
		rep(i, n) line[i].read();
		printf("Case %d: %lld\n", ++caseNo, solve());
	}
	return 0;
}

