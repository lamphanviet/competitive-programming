//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1363 - Binary Matrix (II) 
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

int n, m, row[maxN], col[maxN], total;
char s[maxN][maxN];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf(" %d %d ", &n, &m);
		total = 0;
		rep(i, n) row[i] = 0;
		rep(j, m) col[j] = 0;
		rep(i, n) {
			scanf(" %s ", s[i]);
			rep(j, m) if (s[i][j] == '1') {
				row[i]++;
				col[j]++;
				total++;
			}
		}
		printf("Case %d: ", ++caseNo);
		if (total % n && total % m)
			puts("Impossible");
		else if (total % n == 0 && total % m == 0) {
			rep(i, n) rep(j, m)
			if (s[i][j] == '1' && row[i] > k1 || col[j] > k2 && !(row[i] > k1 && col[j] > k2))
				res++;
		}
		else if (total % n == 0) {
			int res = 0, k = total / n;
			rep(i, n) if (row[i] > k)
				res += row[i] - k;
			printf("row %d\n", res);
		}
		else if (total % m == 0) {
			int res = 0, k = total / m;
			rep(i, m) if (col[i] > k)
				res += col[i] - k;
			printf("column %d\n", res);
		}
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */