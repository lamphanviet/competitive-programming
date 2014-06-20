//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10309 - Turn the Lights Off
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
#define maxN 12

const int n = 10;
int row[maxN], res;

int solve(int first) {
	int counter = 0;
	int curRow = row[0], prevRow = 0, nextRow = row[1];
	for (int j = 0, jj = 1; j < n; j++, jj <<= 1)
		if (first & jj) {
			curRow ^= jj >> 1;
			if (j + 1 < n) curRow ^= jj << 1;
			curRow ^= jj;
			nextRow ^= jj;
			if (++counter > 100) return INF;
		}
	for (int i = 1; i < n; i++) {
		prevRow = curRow;
		curRow = nextRow;
		if (i + 1 < n) nextRow = row[i + 1];
		for (int j = 0, jj = 1; j < n; j++, jj <<= 1) {
			if (prevRow & jj) {
				prevRow ^= jj;
				curRow ^= jj;
				curRow ^= jj >> 1;
				if (j + 1 < n) curRow ^= jj << 1;
				if (i + 1 < n) nextRow ^= jj;
				if (++counter > 100) return INF;
			}
		}
	}
	if (curRow == 0) return counter;
	return INF;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	char cases[1000], s[maxN];
	while (gets(cases) && strcmp(cases, "end")) {
		int sumRow = 0;
		for (int i = 0; i < n; i++) {
			gets(s);
			row[i] = BIT(n) - 1;
			for (int j = 0; j < n; j++)
				if (s[j] == '#') row[i] ^= BIT(j);
			sumRow += row[i];
		}
		if (sumRow == 0) res = 0;
		else {
			res = INF;
			for (int i = 0; i < 1024; i++)
				res = min(res, solve(i));
			if (res > 100) res = -1;
		}
		printf("%s %d\n", cases, res);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet