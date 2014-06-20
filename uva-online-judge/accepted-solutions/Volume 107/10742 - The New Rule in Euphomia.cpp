//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10742 - The New Rule in Euphomia
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
#define maxN 1000111

vi prime;
bool isPrime[maxN];
void sieve() {
	fill(isPrime, true);
	for (int i = 3; i * i < maxN; i += 2)
		if (isPrime[i])
			for (int j = i * i; j < maxN; j += i << 1)
				isPrime[j] = false;
	prime.pb(2);
	for (int i = 3; i < maxN; i += 2)
		if (isPrime[i])
			prime.pb(i);
}

int solve(int n) {
	int res = 0;
	for (int i = 0; i < prime.size() && n - prime[i] > prime[i]; i++) {
		int upPrime = n - prime[i];
		int lo = i + 1, hi = prime.size() - 1, p = i;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (prime[mid] <= upPrime)
				lo = mid + 1, p = mid;
			else hi = mid - 1;
		}
		res += p - i;
	}
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	sieve();
	int n, cases = 0;
	while (scanf("%d", &n) && n) {
		printf("Case %d: %d\n", ++cases, solve(n));
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet