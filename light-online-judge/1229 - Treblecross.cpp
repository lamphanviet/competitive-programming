//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1229 - Treblecross
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
#define maxN 201

int g[4][4][maxN];
char s[maxN];
vi res;

int compute(int st, int nd, int n) {
	if (g[st][nd][n] != -1) return g[st][nd][n];
	if (n == 0 || st == 3 || nd == 3) return g[st][nd][n] = 0; // P-position
	vi f;
	fr(i, 1, n) {
		int a = 0, b = 0;
		f.pb(a ^ b);
	}
	f.pb(-1); fb.pb(INF);
	fr(i, 1, f.size() - 1)
		if (f[i - 1] + 1 < f[i])
			return g[st][nd][n] = f[i - 1] + 1;
}

void solve() {
	res.clear();
	int len = strlen(s);
	vii state;
	
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	fill(g, -1);
	rep(i, 4) rep(j, 4) rep(k, maxN)
		compute(i, j, k);
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf(" %s ", s);
		printf("Case %d:", ++caseNo);
		if (!res.size()) puts(" 0");
		else rep(i, res.size())
			printf(" %d", res[i]);
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */