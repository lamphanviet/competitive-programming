//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Online Judge : UVa - 12439 - February 29
// Problem Name : 12439 - February 29
// Time Limit   : 1.000s
// Description  : graph
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
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define bit(n) (1<<(n))
#define Last(i) ( (i) & (-i) )
#define sq(x) ((x) * (x))
#define INF 1000111222
#define eps 1e-7
#define maxN 100000
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int month[2], day[2], year[2];
map<string, int> getMonth;
void preCal() {
	getMonth["January"] = 1;
	getMonth["February"] = 2;
}

int cal(int a, int b, int k) {
	if (a > b) return 0;
	int res = 0;
	if (a % k == 0) {
		res = 1;
	}
	else {
		int tmp = (a / k) + 1;
		a = tmp * k;
		if (a <= b) res++;
	}
	if (a > b) return res;
	a = b - a;
	res += a / k;
	return res;
}

int solve() {
	return cal(year[0], year[1], 4) - cal(year[0], year[1], 100) + cal(year[0], year[1], 400);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif
	preCal();
	int caseNo, cases = 0;
	scanf("%d ", &caseNo);
	while (caseNo--) {
		for (int i = 0; i < 2; i++) {
			string m;
			cin >> m;
			month[i] = getMonth[m];
			scanf(" %d, ", &day[i]);
			scanf(" %d ", &year[i]);
			if (i == 0 && month[i] == 0)
				year[i]++;
			else if (i == 1 && month[i]) {
				if (month[i] == 1 || (month[i] == 2 && day[i] < 29))
					year[i]--;
			}
		}
		printf("Case %d: %d\n", ++cases, solve());
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet
