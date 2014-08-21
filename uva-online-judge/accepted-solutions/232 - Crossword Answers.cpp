//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 
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
#define maxN 15

int n, m, number[maxN][maxN];
char s[maxN][maxN];
bool flag[maxN][maxN];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int puz = 0;
	while (scanf("%d", &n) && n) {
		scanf(" %d ", &m);
		rep(i, n) scanf(" %s ", s[i]);
		if (puz) puts("");
		printf("puzzle #%d:\n", ++puz);
		int kk = 0;
		rep(i, n) rep(j, m) {
			if (s[i][j] == '*') continue;
			if (i == 0 || j == 0)
				number[i][j] = ++kk;
			else {
				if (i && s[i - 1][j] == '*') number[i][j] =  ++kk;
				else if (j && s[i][j - 1] == '*') number[i][j] = ++kk;
			}
		}
		fill(flag, true);
		puts("Across");
		rep(i, n) rep(j, m)
			if (flag[i][j] && s[i][j] != '*') {
				printf("%3d.", number[i][j]);
				int k = j;
				while (k < m && flag[i][k] && s[i][k] != '*') {
					putchar(s[i][k]);
					flag[i][k] = false;
					k++;
				}
				puts("");
			}
		fill(flag, true);
		puts("Down");
		rep(i, n) rep(j, m)
			if (flag[i][j] && s[i][j] != '*') {
				printf("%3d.", number[i][j]);
				int k = i;
				while (k < n && flag[k][j] && s[k][j] != '*') {
					putchar(s[k][j]);
					flag[k][j] = false;
					k++;
				}
				puts("");
			}
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet