//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 983 - Localized Summing for Blurring
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
#define maxN 1011

int n, m, sum[maxN][maxN];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	bool endLine = false;
	while (scanf("%d %d", &n, &m) != EOF) {
		for (int i = 0; i <= n; i++)
			sum[i][0] = sum[0][i] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				scanf("%d", &sum[i][j]);
				sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			}
		if (endLine) putchar('\n'); endLine = true;
		int totalSum = 0;
		for (int i = 1, k = n - m + 1; i <= k; i++)
			for (int j = 1; j <= k; j++) {
				int x = i + m - 1, y = j + m - 1;
				int ans = sum[x][y] - sum[i-1][y] - sum[x][j-1] + sum[i-1][j-1];
				printf("%d\n", ans);
				totalSum += ans;
			}
		printf("%d\n", totalSum);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet