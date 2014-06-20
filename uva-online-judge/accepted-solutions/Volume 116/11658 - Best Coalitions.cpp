//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 11658 - Best Coalitions
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
#define eps 1e-5
#define maxN 10011

const int m = 10000;
int n, a[maxN];
bool dp[maxN];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int x, p, q;
	while (scanf("%d %d", &n, &x) && (n || x)) {
		for (int i = 0; i < n; i++) {
			scanf("%d.%d", &p, &q);
			a[i] = p * 100 + q;
		}
		swap(a[x - 1], a[0]);
		fill(dp, 0);
		dp[a[0]] = true;
		for (int i = 1; i < n; i++)
			for (int j = m; j >= 0; j--)
				if (dp[j] && j + a[i] <= m)
					dp[j + a[i]] = true;
		double res = INF;
		for (int i = 5001; i <= m; i++)
			if (dp[i]) { res = i; break; }
		printf("%.2lf\n", (a[0] * 100.0 / res) + eps);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet