//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 11413 - Fill the Containers
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
#define maxN 1111

int n, m, a[maxN], res, sum, maxVal;

bool accept(int val) {
	int k = 0, tmp = 0;
	for (int i = 0; i < n && k <= m; i++) {
		if (tmp + a[i] > val)
			tmp = 0;
		if (tmp == 0) k++;
		tmp += a[i];
	}
	return k <= m;
}

int solve() {
	int L = maxVal, R = sum, res = INF;
	while (L <= R) {
		int mid = (L + R) >> 1;
		if (accept(mid)) {
			R = mid - 1;
			res = min(res, mid);
		}
		else L = mid + 1;
	}
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	while (scanf("%d %d", &n, &m) != EOF) {
		sum = maxVal = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
			maxVal = max(maxVal, a[i]);
		}
		if (m >= n) res = maxVal;
		else res = solve();
		printf("%d\n", res);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet