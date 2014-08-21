//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10578 - The Game of 31
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

char s[maxN], c[7];
int dp[5][5][5][5][5][5];

int find(int sum) {
	if (dp[c[1]][c[2]][c[3]][c[4]][c[5]][c[6]] != -1)
		return dp[c[1]][c[2]][c[3]][c[4]][c[5]][c[6]];
	if (sum > 31) {
		dp[c[1]][c[2]][c[3]][c[4]][c[5]][c[6]] = 1; // P-position
		return 1;
	}
	int p = 0;
	fr(i, 1, 6) if (c[i] < 4) {
		c[i]++;
		p = max(p, 1 - find(sum + i)); // if can reach P-position => p = 1 - N-position
		c[i]--;
	}
	dp[c[1]][c[2]][c[3]][c[4]][c[5]][c[6]] = p;
	return p;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	fill(dp, -1);
	fill(c, 0);
	find(0);
	while (gets(s)) {
		rep(i, 7) c[i] = 0;
		int sum = 0, len = strlen(s);
		rep(i, len) {
			c[s[i] - '0']++;
			sum += (s[i] - '0');
			//printf("%d - %d: %d\n", i, s[i], sum);
		}
		printf("%s ", s);
		int p = dp[c[1]][c[2]][c[3]][c[4]][c[5]][c[6]];
		if (p % 2 == len % 2)
			puts("B");
		else puts("A");
		//printf("sum %d %d %d\n", sum, p, len % 2);
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */