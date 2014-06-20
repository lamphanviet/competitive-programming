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
#define maxN 1011

int n, dp[maxN];
char s[maxN];
bool f[maxN][maxN];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf(" %d ", &cases); cases--; ) {
		scanf(" %s ", s);
		n = strlen(s);
		rep(i, n) rep(j, n) f[i][j] = true;
		fr(len, 2, n)
			for (int i = 0, j = len - 1; j < n; i++, j++) {
				f[i][j] = false;
				if (s[i] == s[j])
					f[i][j] = f[i + 1][j - 1];
			}
		dp[0] = 1;
		fr(i, 1, n - 1) {
			if (f[0][i]) {
				dp[i] = 1;
				continue;
			}
			dp[i] = INF;
			fr(j, 1, i) if (f[j][i])
				dp[i] = min(dp[i], dp[j - 1] + 1);
		}
		printf("Case %d: %d\n", ++caseNo, dp[n - 1]);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet