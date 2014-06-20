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
#define maxN 10

int n, m, a[maxN], b[maxN];
char s[maxN];

inline bool inside(int i, int j) { return (0 <= i && i < n && 0 <= j && j < m); }

int solve(int fr, int fc) {
	memcpy(b, a, sizeof(a));
	int res = 0;
	rep(j, m) if (fr & BIT(j)) {
		res++;
		fr(u, -1, 1) fr(v, -1, 1)
			if (inside(0 + u, j + v))
				b[0 + u] ^= BIT(j + v);
	}
	rep(i, n) if (fc & BIT(i)) {
		res++;
		fr(u, -1, 1) fr(v, -1, 1)
			if (inside(i + u, 0 + v))
				b[i + u] ^= BIT(0 + v);
	}
	fr(i, 1, n - 1) {
		fr(j, 1, m - 1) if (b[i - 1] & BIT(j - 1)) {
			res++;
			fr(u, -1, 1) fr(v, -1, 1)
				if (inside(i + u, j + v))
					b[i + u] ^= BIT(j + v);
		}
		if (b[i - 1]) return INF;
	}
	if (b[n - 1]) return INF;
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d ", &n, &m);
		rep(i, n) {
			scanf(" %s ", s);
			a[i] = 0;
			rep(j, m) if (s[j] == '.') a[i] ^= BIT(j);
		}
		int res = INF;
		repr(i, BIT(m)) repr(j, BIT(n)) res = min(res, solve(i, j));
		printf("Case %d: ", ++caseNo);
		if (res == INF) puts("impossible");
		else printf("%d\n", res);
	}
	return 0;
}
