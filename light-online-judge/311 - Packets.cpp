//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 311 - Packets
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
#define maxN 100000


int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int sum, a[7], n = 6;
	while (true) {
		int sum = 0;
		fr(i, 1, n) {
			scanf("%d", &a[i]);
			sum |= a[i];
		}
		if (!sum) break;
		int res = 0, c1 = 0, c2 = 0;
		res += a[6] + a[5];
		c1 += 11 * a[5];
		res += a[4];
		c2 += 5 * a[4];
		res += a[3] / 4;
		a[3] %= 4;
		if (a[3]) res++;
		if (a[3] == 1) {
			c2 += 5;
			c1 += 7;
		}
		else if (a[3] == 2) {
			c2 += 3;
			c1 += 6;
		}
		else if (a[3] == 3) {
			c2++;
			c1 += 5;
		}
		if (a[2] <= c2) {
			c2 -= a[2];
			c1 += c2 * 2;
		}
		else {
			a[2] -= c2;
			res += a[2] / 9;
			a[2] %= 9;
			if (a[2]) res++;
			c1 += (9 - a[2]) * 4;
		}
		if (a[1] > c1) {
			a[1] -= c1;
			res += a[1] / 36;
			if (a[1] % 36) res++;
		}
		printf("%d\n", res);
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */