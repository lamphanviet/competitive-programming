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
#define maxN 1000111
#define mod 1000003

bool isPrime[maxN];
vi prime;

void sieve() {
	fill(isPrime, true);
	for (int i = 3; i * i < maxN; i += 2)
		if (isPrime[i])
			for (int j = i * i; j < maxN; j += i + i)
				isPrime[j] = false;
	prime.pb(2);
	for (int i = 3; i < maxN; i += 2)
		if (isPrime[i]) prime.pb(i);
}

int powMod(int n, int k) {
	if (k == 0) return 1;
	if (k == 1) return n % mod;
	int64 tmp = powMod(n, k / 2);
	tmp = (tmp * tmp) % mod;
	if (k & 1) tmp *= n;
	return tmp % mod;
}

int cal(int n, int k) {
	int64 res = 0, kk = k;
	while (kk <= n) {
		res += n / kk;
		kk *= k;
	}
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	sieve();
	int cases, caseNo = 0, n, k;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d", &n, &k);
		int res = 1;
		for (int i = 0; i < prime.size() && prime[i] <= n; i++) {
			int p = cal(n, prime[i]) - cal(n - k, prime[i]) - cal(k, prime[i]);
			res = (res * (int64)powMod(prime[i], p)) % mod;
		}
		printf("Case %d: %d\n", ++caseNo, res);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet