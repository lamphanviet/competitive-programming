//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1128 - Greatest Parent 
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
#define maxN 100002

int nextInt() {
	int res = 0;
	char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	do {
		res = res * 10 + ch - 48;
		ch = getchar();
	} while ('0' <= ch && ch <= '9');
	return res;
}
char buff[20];
void write(int n, int len = 0) {
	do {
		buff[len++] = n % 10 + 48; n /= 10;
	} while (n);
	while (len--) putchar(buff[len]);
}

int n, m, k, res[maxN];
int parent[maxN], value[maxN];
vii ques[maxN];
ii node[maxN];
vi child[maxN];

void dfs(int u) {
	node[k++] = ii(value[u], u);
	rep(i, ques[u].size()) {
		int val = ques[u][i].ff, pos = ques[u][i].ss;
		int lo = 0, hi = k - 1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (node[mid].ff >= val)
				hi = mid - 1;
			else lo = mid + 1;
		}
		res[pos] = node[lo].ss;
	}
	rep(i, child[u].size()) dfs(child[u][i]);
	child[u].clear(); ques[u].clear();
	k--;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, u, val;
	for (cases = nextInt(); cases--; ) {
		n = nextInt(); m = nextInt();
		fr(i, 1, n - 1) {
			parent[i] = nextInt();
			value[i] = nextInt();
			child[parent[i]].pb(i);
		}
		parent[0] = 0; value[0] = 1;
		rep(i, m) {
			u = nextInt(); val = nextInt();
			ques[u].pb(ii(val, i));
		}
		k = 0;
		dfs(0);
		printf("Case %d:\n", ++caseNo);
		rep(i, m) { write(res[i]); putchar('\n'); }
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet