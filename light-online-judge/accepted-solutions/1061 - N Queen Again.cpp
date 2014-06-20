//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1061 - N Queen Again 
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
#define maxN 10

const int n = 8;
int sol[100][8], tmpSol[8], m, pos[BIT(n)], q;
char s[maxN];
ii queen[maxN];

void backTrack(int x, int d1, int d2, int col) {
	if (x == n) {
		rep(i, 8) sol[m][i] = tmpSol[i];
		m++;
		return;
	}
	int sts = d1 & d2 & col;
	while (sts) {
		int p = AND(sts, -sts);
		tmpSol[x] = pos[p];
		backTrack(x + 1, ((d1^p)>>1)|BIT(n - 1), (((d2^p)<<1)|1)&(~BIT(n)), col^p);
		sts ^= p;
	}
}

int f[BIT(n)];

int move(int x1, int y1, int x2, int y2) {
	if (x1 == x2 && y1 == y2) return 0;
	if (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2)) return 1;
	return 2;
}

int solve(int *p) {
	rep(i, 256) f[i] = INF;
	f[0] = 0;
	rep(i, n) {
		repr(j, 256) if (f[j] != INF) {
			rep(k, n) if (!AND(j, BIT(k))) {
				int next = j | BIT(k);
				f[next] = min(f[next], f[j] + move(queen[i].ff, queen[i].ss, k, p[k]));
			}
		}
	}
	return f[255];
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	rep(i, n) pos[BIT(i)] = i;
	m = 0;
	backTrack(0, 255, 255, 255);
	int cases, caseNo = 0;
	for (scanf(" %d ", &cases); cases--; ) {
		q = 0;
		rep(i, n) {
			scanf(" %s ", s);
			rep(j, n) if (s[j] == 'q')
				queen[q++] = ii(i, j);
		}
		int res = INF;
		rep(i, m) res = min(res, solve(sol[i]));
		printf("Case %d: %d\n", ++caseNo, res);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet