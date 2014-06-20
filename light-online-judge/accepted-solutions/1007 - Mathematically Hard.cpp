//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1007 - Mathematically Hard 
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
#define maxN 5000011

uint64 phi[maxN];
bool isPrime[maxN];

void sieve() {
	rep(i, maxN) isPrime[i] = true, phi[i] = i;
	for (int i = 2; i < maxN; i++)
		if (isPrime[i])
			for (int j = i; j < maxN; j += i) {
				isPrime[j] = false;
				phi[j] *= i - 1;
				phi[j] /= i;
			}
	phi[1] = 0;
	fr(i, 2, maxN - 1)
		phi[i] = phi[i - 1] + phi[i] * phi[i];
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	sieve();
	int cases, caseNo = 0, x, y;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d", &x, &y);
		if (x > y) swap(x, y);
		printf("Case %d: %llu\n", ++caseNo, phi[y] - phi[x - 1]);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet