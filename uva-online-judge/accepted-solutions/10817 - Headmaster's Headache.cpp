//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10817 - Headmaster's Headache
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
#define INF 2000111222
#define eps 1e-7
#define maxS 10
#define maxN 111

int ar[maxN], sz;
char buff[maxN * 20];
int n, m, s, dp[7000];
int bit[7000][10];

void readLine() {
	sz = 0;
	gets(buff);
	for (int i = 0; buff[i]; i++)
		if ('0' <= buff[i] && buff[i] <= '9')
			ar[sz++] = buff[i] - '0';
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	rep(i, 7000) {
		fill(bit[i], 0);
		int k = i;
		rep(j, 8) {
			bit[i][j] = k % 3;
			k /= 3;
		}
	}
	int c[maxS], cost, cnext[maxS];
	while (scanf("%d %d %d", &s, &m, &n) && s) {
		int total = 0, st = 0;
		fill(c, 0);
		while (m--) {
			scanf("%d", &cost);
			total += cost;
			readLine();
			set<int> sub;
			rep(k, sz) sub.insert(ar[k] - 1);
			foreach (it, sub) {
				c[*it] = min(2, c[*it] + 1);
			}
		}
		repr(k, s) st = st * 3 + c[k];
		m = 1;
		rep(i, s) m *= 3;
		rep(i, m) dp[i] = INF;
		dp[st] = total;

		rep(i, n) {
			scanf("%d", &cost);
			readLine(); fill(c, 0);
			set<int> sub;
			rep(k, sz) sub.insert(ar[k] - 1);
			foreach (it, sub) {
				c[*it] = min(2, c[*it] + 1);
			}
			
			repr(j, m) {
				if (dp[j] == INF) continue;
				fill(cnext, 0);
				rep(k, s) {
					cnext[k] = min(2, c[k] + bit[j][k]);
				}
				int next = 0;
				repr(k, s) next = next * 3 + cnext[k];
				dp[next] = min(dp[next], dp[j] + cost);
			}
		}

		printf("%d\n", dp[m - 1]);
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */
