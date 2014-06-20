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
#define maxN 10111
#define maxL 16

const int k = 15;
struct Entry {
	int id; ii val;
	bool operator < (const Entry &en) const { return val < en.val; }
} L[maxN];
int n, lo, hi, p[maxN][maxL];
char s[maxN];

inline int get(int lf, int rg) {
	int a = rg - lf + 1, b = n - lf;
	a = max(a, lo); b = min(b, hi);
	return a <= b ? b - a + 1 : 0;
}

int solve() {
	rep(i, n) p[i][0] = s[i] - 'a';
	fr(j, 1, k) {
		rep(i, n) {
			L[i].val.ff = p[i][j - 1];
			L[i].val.ss = (i + BIT(j - 1) < n) ? p[i + BIT(j - 1)][j - 1] : -1;
			L[i].id = i;
		}
		sort(L, L + n);
		p[L[0].id][j] = 0;
		fr(i, 1, n - 1) p[L[i].id][j] = p[L[i - 1].id][j] + (L[i].val != L[i - 1].val);
	}
	int res = get(L[0].id, L[0].id);
	fr(i, 1, n - 1) {
		int v = L[i - 1].id, u = L[i].id;
		for (int j = k; j >= 0 && v < n && u < n; j--) {
			if (p[u][j] == p[v][j]) {
				u += BIT(j); v += BIT(j);
			}
		}
		res += get(L[i].id, u);
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
		scanf(" %s %d %d ", s, &lo, &hi);
		n = strlen(s);
		printf("Case %d: %d\n", ++caseNo, solve());
	}
	return 0;
}
