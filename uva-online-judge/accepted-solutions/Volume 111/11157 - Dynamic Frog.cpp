//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 11157 - Dynamic Frog
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
#define maxN 111

int n, d;
ii stone[maxN];
bool flag[maxN];

int solve() {
	int res = 0;
	fill(flag, true);
	int lastPos = 0;
	for (int i = 0; i < n; ) {
		res = max(res, stone[i].ff - lastPos);
		if (stone[i].ss == 1)
			flag[i] = false;
		lastPos = stone[i].ff;
		if (i + 1 == n) break;
		if (stone[i + 1].ss == 0)
			i++;
		else i += 2;
	}
	lastPos = d;
	for (int i = n - 1; i >= 0; ) {
		res = max(res, lastPos - stone[i].ff);
		lastPos = stone[i].ff;
		if (i == 0) break;
		if (flag[i - 1])
			i--;
		else i -= 2;
	}
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	char x;
	int cases, caseNo = 0, d, y;
	scanf("%d", &cases);
	while (cases--) {
		scanf("%d %d ", &n, &d);
		for (int i = 0; i < n;i++) {
			scanf(" %c-%d ", &x, &y);
			if (x == 'B') stone[i] = ii(y, 0);
			else stone[i] = ii(y, 1);
		}
		stone[n] = ii(0, 0);
		stone[n + 1] = ii(d, 0);
		n += 2; sort(stone, stone + n);
		printf("Case %d: %d\n", ++caseNo, solve());
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet