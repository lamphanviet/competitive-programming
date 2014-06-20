//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1199 - Partitioning Game
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
#define maxN 10001

int g[maxN];
bool f[maxN];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	g[1] = g[2] = 0;
	fr(i, 3, maxN - 1) {
		g[i] = 0;
		fill(f, true);
		for (int j = 1, m = (i - 1) / 2; j <= m; j++)
			f[g[j] ^ g[i - j]] = false;
		rep(j, maxN) if (f[j]) {
			g[i] = j;
			break;
		}
	}
	int cases, caseNo = 0, n, val;
	for (scanf("%d", &cases); cases--; ) {
		int nim = 0;
		scanf("%d", &n);
		rep(i, n) {
			scanf("%d", &val);
			nim ^= g[val];
		}
		printf("Case %d: ", ++caseNo);
		if (nim) puts("Alice");
		else puts("Bob");
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */