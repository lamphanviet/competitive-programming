//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1401 - No More Tic-tac-toe
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
#define maxN 101

int g[3][3][maxN];

int compute(int st, int nd, int n) {
	if (g[st][nd][n] != -1)
		return g[st][nd][n];
	if (n == 1) {
		if (st == 2 || nd == 2 || (st == nd))
			g[st][nd][n] = 1;
		else g[st][nd][n] = 0;
		return g[st][nd][n];
	}
	vi f;
	fr(i, 1, n) {
		int len1 = i - 1, len2 = n - i;
		if ((i == 1 && st == 0) || (i == n && nd == 0)) continue;
		int a = len1 ? compute(st, 0, len1) : 0;
		int b = len2 ? compute(0, nd, len2) : 0;
		f.pb(a ^ b);
	}
	fr(i, 1, n) {
		int len1 = i - 1, len2 = n - i;
		if ((i == 1 && st == 1) || (i == n && nd == 1)) continue;
		int a = len1 ? compute(st, 1, len1) : 0;
		int b = len2 ? compute(1, nd, len2) : 0;
		f.pb(a ^ b);
	}
	f.pb(-1); f.pb(INF);
	sort(all(f));
	fr(i, 1, f.size() - 1)
		if (f[i - 1] + 1 < f[i])
			return g[st][nd][n] = f[i - 1] + 1;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	fill(g, -1);
	rep(i, 3) rep(j, 3) fr(len, 1, maxN - 1)
		compute(i, j, len);
	char s[maxN];
	int cases, caseNo = 0;
	for (scanf(" %d ", &cases); cases--; ) {
		scanf(" %s ", s);
		int nim = 0, len = strlen(s), st = 2, pos = -1, nd, counter = 0;
		rep(i, len) {
			if (s[i] != '.') {
				nd = s[i] == 'O' ? 0 : 1;
				int n = i - pos - 1;
				if (n) nim ^= g[st][nd][n];
				st = nd;
				pos = i;
				counter++;
			}
		}
		if (pos < len - 1) nim ^= g[st][2][len - pos - 1];
		printf("Case %d: ", ++caseNo);
		counter &= 1;
		if (nim && !counter || (!nim && counter)) puts("Yes");
		else puts("No");
		
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */