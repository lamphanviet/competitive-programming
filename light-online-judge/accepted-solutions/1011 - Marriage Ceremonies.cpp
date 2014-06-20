//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1011 - Marriage Ceremonies 
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
#define maxN 17

int n, m, val[maxN][maxN];
int dp[2][BIT(maxN)];

int p(int x) {
	rep(i, n)
		if (x & BIT(i)) putchar('1');
		else putchar('0');
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int caseNo, cases = 0;
	for (scanf("%d", &caseNo); caseNo--; ) {
		scanf("%d", &n); m = BIT(n);
		fill(dp, 0);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &val[i][j]);
		for (int i = 0; i < n; i++) {
			int cur = i & 1, next = (i + 1) & 1;
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					if (k & BIT(j)) {
						dp[next][k ^ BIT(j)] = max(dp[next][k ^ BIT(j)], dp[cur][k] + val[i][j]);
					}
				}
			}
		}
		printf("Case %d: %d\n", ++cases, dp[n & 1][0]);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet