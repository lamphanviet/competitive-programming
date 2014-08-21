//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10400 - Game Show Math
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
#define maxN 111
#define maxM 64111

const int M = 32000;
int n, a[maxN], result;
int dp[maxN][maxM];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		scanf("%d", &result);
		
		// dp[][] = 0 + , 1 - , 2 * , 3 /
		fill(dp, -1);
		dp[0][a[0] + M] = 0;
		for (int i = 1; i < n; i++)
			for (int j = 0; j < maxM; j++)
				if (dp[i - 1][j] != -1) {
			//		printf("%d: %d: %d\n", i - 1, j, dp[i - 1][j]);
					if (abs(j - M + a[i]) <= M)
						dp[i][j - M + a[i] + M] = 0;
					if (abs(j - M - a[i]) <= M)
						dp[i][j - M - a[i] + M] = 1;
					if (abs((j - M) * a[i]) <= M)
						dp[i][(j - M) * a[i] + M] = 2;
					if ((j - M) % a[i] == 0 && abs((j - M) / a[i]) <= M)
						dp[i][(j - M) / a[i] + M] = 3;
				}
		if (dp[n - 1][result + M] == -1)
			puts("NO EXPRESSION");
		else {
			vi ope;
			for (int i = n - 1, j = result; i >= 0; i--) {
				ope.pb(dp[i][j + M]);
				switch (dp[i][j + M]) {
					case 0: j -= a[i]; break;
					case 1: j += a[i]; break;
					case 2: j /= a[i]; break;
					case 3: j *= a[i]; break;
				}
			}
			reverse(all(ope));
			for (int i = 0; i < n; i++) {
				char ch;
				switch (ope[i]) {
					case 0: ch = '+'; break;
					case 1: ch = '-'; break;
					case 2: ch = '*'; break;
					case 3: ch = '/'; break;
				}
				if (i) putchar(ch);
				printf("%d", a[i]);
			}
			printf("=%d\n", result);
		}
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet