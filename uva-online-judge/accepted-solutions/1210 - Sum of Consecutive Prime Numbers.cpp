//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1210 - Sum of Consecutive Prime Numbers
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
#define maxN 10001

int sum[1250];
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
	sum[0] = 0;
	rep(i, prime.size())
		sum[i + 1] = sum[i] + prime[i];
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	sieve();
	int n;
	while (scanf("%d", &n) && n) {
		int res = 0;
		for (int i = 1; i <= prime.size() && prime[i - 1] <= n; i++) {
			int lo = 0, hi = i - 1, found = 0;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				int value = sum[i] - sum[mid];
				if (value == n) {
					found = 1;
					break;
				}
				else if (value < n)
					hi = mid - 1;
				else lo = mid + 1;
			}
			if (found) res++;
		}
		printf("%d\n", res);
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */