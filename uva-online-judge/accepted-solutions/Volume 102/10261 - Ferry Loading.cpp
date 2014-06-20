//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10261 - Ferry Loading
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
#define maxN 10011

int m;
vi car, sum;
int dp[222][maxN];

void solve() {
	if (!car.size() || car[0] > m) {
		puts("0");
		return;
	}
	
	int x = 0, y = 0;
	for (int i = 0; i <= m; i++)
		dp[0][i] = -1;
	dp[0][0] = 0; dp[0][car[0]] = 1;
	for (int i = 1; i < car.size(); i++) {
		for (int j = 0; j <= m; j++)
			dp[i][j] = -1;
		for (int j = 0; j <= m; j++)
			if (dp[i - 1][j] != -1) {
				if (sum[i] - j <= m) {
					x = i; y = j;
					dp[i][j] = 0;
				}
				if (j + car[i] <= m) {
					x = i; y = j + car[i];
					dp[i][y] = 1;
				}
			}
		if (x != i) break;
	}
	vector<bool> res;
	while (x >= 0 && dp[x][y] != -1) {
		if (dp[x][y]) {
			res.pb(false);
			y -= car[x];
		}
		else
			res.pb(true);
		x--;
	}
	printf("%d\n", res.size());
	for (int i = res.size() - 1; i >= 0; i--)
		if (!res[i]) puts("port");
		else puts("starboard");
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	bool blank = false;
	int cases, val;
	for (scanf("%d", &cases); cases--; ) {
		car.clear(); sum.clear();
		scanf("%d", &m); m *= 100;
		while (scanf("%d", &val) && val) {
			car.pb(val);
			sum.pb(val);
			if (sum.size() > 1) sum[sum.size()-1] += sum[sum.size() - 2];
		}
		if (blank) puts(""); blank = true;
		solve();
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet