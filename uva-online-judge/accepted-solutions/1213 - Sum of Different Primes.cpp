//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1213 - Sum of Different Primes
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
#define maxN 1155

bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false;
	return true;
}

vi prime;
void sieve() {
	prime.pb(2);
	for (int i = 3; i < maxN; i++)
		if (isPrime(i)) prime.pb(i);
}

int n, m, dp1[maxN][16], dp2[maxN][16];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	sieve();
	while (scanf("%d %d", &n, &m) && (n || m)) {
		fill(dp1, 0);
		dp1[0][0] = 1;
		for (int i = 0; i < prime.size() && prime[i] <= n; i++) {
			fill(dp2, 0);
			for (int j = 0; j + prime[i] <= n; j++)
				for (int k = 0; k < m; k++)
					dp2[j + prime[i]][k + 1] += dp1[j][k];
						
			for (int j = 0; j <= n; j++)
				for (int k = 0; k <= m; k++)
					dp1[j][k] += dp2[j][k];
		}
		printf("%d\n", dp1[n][m]);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet