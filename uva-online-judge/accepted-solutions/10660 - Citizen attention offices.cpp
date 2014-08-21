//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10660 - Citizen attention offices
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
#define maxN 6
#define maxNN 30

const int n = 5;
const int nn = 25;
int m, x[maxNN], y[maxNN], w[maxNN], minSum;
vi res(5), tmp(5);

void check() {
	int x0, y0, tmpSum = 0;
	for (int i = 0; i < m; i++) {
		int tmpMin = INF;
		for (int k = 0; k < n; k++) {
			x0 = tmp[k] / n;
			y0 = tmp[k] % n;;
			tmpMin = min(tmpMin, (abs(x[i] - x0) + abs(y[i] - y0)) * w[i]);
		}
		tmpSum += tmpMin;
	}
	if (tmpSum >= minSum) return;
	minSum = tmpSum;
	res = tmp;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &x[i], &y[i], &w[i]);
		}
		minSum = INF;
		for (tmp[0] = 0; tmp[0] < nn; tmp[0]++)
			for (tmp[1] = tmp[0] + 1; tmp[1] < nn; tmp[1]++)
				for (tmp[2] = tmp[1] + 1; tmp[2] < nn; tmp[2]++)
					for (tmp[3] = tmp[2] + 1; tmp[3] < nn; tmp[3]++)
						for (tmp[4] = tmp[3] + 1; tmp[4] < nn; tmp[4]++)
							check();
		for (int i = 0; i < res.size(); i++) {
			if (i) printf(" ");
			printf("%d", res[i]);
		}
		putchar('\n');
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet