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
#define maxN 50005
#define maxK 17

const int k = 16;
struct Entry {
	int id;
	ii val;
	bool operator < (const Entry &b) const { return val < b.val; }
} L[maxN];
int n, m, f[maxN], next[maxN], p[maxN][maxK];
char a[maxN], b[maxN];
bool mark[maxN];

int64 solve() {
	f[0] = f[1] = 0;
	fr(i, 2, m) {
		for (int j = f[i - 1]; ; ) {
			if (b[i - 1] == b[j]) { f[i] = j + 1; break; }
			if (j == 0) { f[i] = 0; break; }
			j = f[j];
		}
	}
	fill(mark, false);
	for (int j = 0, i = 0; j < n; ) {
		if (a[j] == b[i]) {
			j++; i++;
			if (i == m) {
				mark[j - m] = true;
				i = f[i];
			}
		}
		else if (i > 0) i = f[i];
		else j++;
	}
	next[n] = n - 1;
	repr(i, n) next[i] = mark[i] ? i + m - 2 : next[i + 1];
	
	// cal suffix array
	rep(i, n) p[i][0] = a[i] - 'a';
	fr(j, 1, k) {
		rep(i, n) {
			L[i].val.ff = p[i][j - 1];
			L[i].val.ss = i + BIT(j - 1) < n ? p[i + BIT(j - 1)][j - 1] : -1;
			L[i].id = i;
		}
		sort(L, L + n);
		p[L[0].id][j] = 0;
		fr(i, 1, n - 1) p[L[i].id][j] = p[L[i - 1].id][j] + (L[i].val != L[i - 1].val);
	}
	int64 res = next[L[0].id] - L[0].id + 1;
	fr(i, 1, n - 1) {
		int v = L[i - 1].id, u = L[i].id;
		frr(j, k, 0) {
			if (!(u < n && v < n)) break;
			if (p[v][j] == p[u][j])
				u += BIT(j), v += BIT(j);
		}
		if (u <= next[L[i].id]) res += next[L[i].id] - u + 1;
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
		scanf(" %s %s ", a, b);
		n = strlen(a); m = strlen(b);
		printf("Case %d: %lld\n", ++caseNo, solve());
	}
	return 0;
}
