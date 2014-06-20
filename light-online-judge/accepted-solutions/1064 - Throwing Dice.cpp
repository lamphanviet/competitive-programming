//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1064 - Throwing Dice 
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
#define maxN 160

int n, m, x;
int64 f1[maxN], f2[maxN];

int64 gcd(int64 a, int64 b) {
	if (b == 0LL) return a;
	return gcd(b, a % b);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d", &n, &x);
		m = n * 6 + 1;
		rep(i, m) f1[i] = f2[i] = 0LL;
		fr(i, 1, 6) f2[i] = 1LL;
		rep(_, n - 1) {
			rep(i, m) f1[i] = f2[i], f2[i] = 0LL;
			rep(i, m) if (f1[i])
				fr(j, 1, 6) if (i + j < m)
					f2[i + j] += f1[i];
		}
		int64 p = 0LL, q = 0LL;
		rep(i, m) q += f2[i];
		fr(i, x, m - 1) p += f2[i];
		int64 k = gcd(p, q);
		p /= k; q /= k;
		printf("Case %d: ", ++caseNo);
		if (p == q) puts("1");
		else if (!p) puts("0");
		else printf("%lld/%lld\n", p, q);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet