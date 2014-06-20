//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 159 - Word Crosses
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
#define maxN 100

char s[maxN][maxN];
string word[5];

void output() {
	rep(i, maxN) {
		int j = maxN - 1;
		while (j >= 0 && s[i][j] == ' ') j--;
		if (j < 0) continue;
		s[i][j + 1] = '\0';
		puts(s[i]);
	}
}

void find() {
	fill(s, ' ');
	int row = 50, col = 0;
	rep(i, word[0].length())
		s[row][col++] = word[0][i];
	col += 3;
	rep(i, word[2].length())
		s[row][col++] = word[2][i];
	
	int sx = -1, sy = -1;
	rep(i, word[0].length()) {
		rep(j, word[1].length())
			if (word[0][i] == word[1][j]) {
				sx = i;
				sy = j;
				break;
			}
		if (sx != -1) break;
	}
	for (int i = row, j = sy; j >= 0; i--, j--)
		s[i][sx] = word[1][j];
	for (int i = row, j = sy; j < word[1].length(); i++, j++)
		s[i][sx] = word[1][j];
	
	sx = -1, sy = -1;
	rep(i, word[2].length()) {
		rep(j, word[3].length())
			if (word[2][i] == word[3][j]) {
				sx = i; sy = j;
				break;
			}
		if (sx != -1) break;
	}
	sx += word[0].length() + 3;
	for (int i = row, j = sy; j >= 0; i--, j--)
		s[i][sx] = word[3][j];
	for (int i = row, j = sy; j < word[3].length(); j++, i++)
		s[i][sx] = word[3][j];
	output();
}

bool solve() {
	bool ok = false;
	rep(i, word[0].length())
		rep(j, word[1].length())
			if (word[0][i] == word[1][j]) {
				ok = true;
				break;
			}
	if (!ok) return false;
	ok = false;
	rep(i, word[2].length())
		rep(j, word[3].length())
			if (word[2][i] == word[3][j]) {
				ok = true;
				break;
			}
	if (!ok) return false;
	find();
	return true;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif
	bool line = false;
	while (cin >> word[0]) {
		if (word[0] == "#") break;
		if (line) puts("");
		else line = true;
		fr(i, 1, 3) cin >> word[i];
		if (solve()) continue;
		puts("Unable to make two crosses");
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */
