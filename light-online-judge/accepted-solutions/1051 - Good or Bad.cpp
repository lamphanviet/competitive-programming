//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1051 - Good or Bad 
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
#define INF 10
#define eps 1e-7
#define maxN 55

int n, f[maxN], g[maxN];
char s[maxN];
bool type[300];

bool isBad() {
	rep(i, n) {
		int cnt = 0;
		for (int j = 0; j < 3 && i + j < n; j++)
			if (s[i + j] == '?' || type[s[i + j]]) cnt++;
			else break;
		if (cnt == 3) return true;
		cnt = 0;
		for (int j = 0; j < 5 && i + j < n; j++)
			if (s[i + j] == '?' || !type[s[i + j]]) cnt++;
			else break;
		if (cnt == 5) return true;
	}
	return false;
}

bool isGood() {
	fill(f, 0); fill(g, 0);
	if (s[0] == '?') f[0] = g[0] = 1;
	else if (type[s[0]]) f[0] = 1;
	else g[0] = 1;
	fr(i, 1, n - 1) {
		if (s[i] == '?') {
			if (g[i - 1]) f[i] = 1;
			else f[i] = f[i - 1] + 1;
			if (f[i - 1]) g[i] = 1;
			else g[i] = g[i - 1] + 1;
			if (f[i] >= 3 && g[i] >= 5) return false;
			if (f[i] >= 3) f[i] = 0;
			if (g[i] >= 5) g[i] = 0;
		}
		else if (type[s[i]]) {
			if (g[i - 1]) f[i] = 1;
			else f[i] = f[i - 1] + 1;
			g[i] = 0;
			if (f[i] >= 3) return false;
		}
		else {
			f[i] = 0;
			if (f[i - 1]) g[i] = 1;
			else g[i] = g[i - 1] + 1;
			if (g[i] >= 5) return false;
		}
		//printf("%d: %d %d\n", i, f[i], g[i]);
	}
	return true;
}

int check() {
	if (isGood()) {
		if (isBad()) return 2;
		return 1;
	}
	return 0;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	fill(type, false);
	type['A'] = type['E'] = type['O'] = type['U'] = type['I'] = true;
	int cases, caseNo = 0;
	for (scanf(" %d ", &cases); cases--; ) {
		scanf(" %s ", s); n = strlen(s);
		printf("Case %d: ", ++caseNo);
		int res = check();
		if (res == 2) puts("MIXED");
		else if (res == 1) puts("GOOD");
		else puts("BAD");
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet
