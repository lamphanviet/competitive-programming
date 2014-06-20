//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 256 - Quirksome Squares
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
#define maxN 100000

const int d[] = { 10, 100, 1000, 10000 };
const int t[] = { };
vector<int> res[4];

bool check(int a, int b, int n) {
	int64 res = (a + b) * (int64)(a + b);
	return (res % d[n] == b && res / d[n] == a);
}

void preCal() {
	for (int i = 0; i < 4; i++) {
		for (int a = 0; a < d[i]; a++)
			for (int b = 0; b < d[i]; b++)
				if (check(a, b, i)) res[i].pb(a * d[i] + b);
	}
}

void printResult(int n) {
	for (int i = 0; i < res[n].size(); i++) {
		int x = d[n] * d[n] / 10;
		while (res[n][i] < x) putchar('0'), x /= 10;
		if (res[n][i]) printf("%d\n", res[n][i]);
		else putchar('\n');
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	preCal();
	int n;
	while (scanf("%d", &n) != EOF)
		printResult(n / 2 - 1);
	return 0;
}

// Copyright (C) 2012, LamPhanViet