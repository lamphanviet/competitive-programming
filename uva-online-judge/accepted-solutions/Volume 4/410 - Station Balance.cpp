//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 410 - Station Balance
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
#define maxN 11


int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	vi champer[maxN];
	double sumChamper[maxN];
	int n, m, a[maxN], cases = 0;
	while (scanf("%d %d", &n, &m) != EOF) {
		double avg = 0.0;
		for (int i = 0; i < m; i++) {
			scanf("%d", &a[i]);
			avg += a[i];
		}
		for (int i = 0; i < n; i++)
			sumChamper[i] = 0.0, champer[i].clear();
		avg /= n;
		sort(a, a + m);
		for (int i = m - 1, j = 0, k = 1; i >= 0; i--, j += k) {
			sumChamper[j] += a[i];
			champer[j].pb(a[i]);
			if (j == n - 1 && k == 1) k = 0;
			else if (j == n - 1 && k == 0) k = -1;
		}
		
		double res = 0.0;
		for (int i = 0; i < n; i++)
			res += fabs(sumChamper[i] - avg);
		
		printf("Set #%d\n", ++cases);
		for (int i = 0; i < n; i++) {
			printf("%2d:", i);
			for (int j = 0; j < champer[i].size(); j++)
				printf(" %d", champer[i][j]);
			putchar('\n');
		}
		printf("IMBALANCE = %.5lf\n\n", res);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet