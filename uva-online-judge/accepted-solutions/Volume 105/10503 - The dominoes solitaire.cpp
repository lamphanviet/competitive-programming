//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name :  10503 - The dominoes solitaire
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

#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for (int i = (n) - 1; i >= 0; i--)
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
#define maxN 15

int n, m, x[maxN], y[maxN], f;
bool ok;
map<int, int> pos;

void backTrack(int i, int state, int s) {
	if (ok) return;
	if (i == n) {
		if (s == f) ok = true;
		return;
	}
	int avail = state;
	while (avail) {
		int jj = AND(avail, -avail);
		int j = pos[jj];
		if (x[j] == s) {
			backTrack(i + 1, state^jj, y[j]);
		}
		else if (y[j] == s) {
			backTrack(i + 1, state^jj, x[j]);
		}
		avail ^= jj;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int s, gar;
	for (int i = 0; i < maxN; i++)
		pos[BIT(i)] = i;
	while (scanf("%d", &n) && n) {
		scanf("%d", &m);
		scanf("%d %d", &gar, &s);
		scanf("%d %d", &f, &gar);
		for (int i = 0; i < m; i++)
			scanf("%d %d", &x[i], &y[i]);
		ok = false;
		backTrack(0, BIT(m) - 1, s);
		if (ok) puts("YES");
		else puts("NO");
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet