//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1372 - Hexagonal Bamboo Fort 
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
#define maxN 101
#define maxM 100001

int n, a[maxN], tree[maxM];

int nextInt() {
	char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	int res = 0;
	do {
		res = res * 10 + ch - 48;
		ch = getchar();
	} while ('0' <= ch && ch <= '9');
	return res;
}

void update(int i, int val = 1) {
	while (i < maxM) {
		tree[i] += val;
		i += -i & i;
	}
}

int get(int i) {
	int res = 0;
	while (i > 0) {
		res += tree[i];
		i -= -i & i;
	}
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (cases = nextInt(); cases--; ) {
		n = nextInt();
		rep(i, n) a[i] = nextInt();
		sort(a, a + n);
		rep(i, maxM) tree[i] = 0;
		int res = 0, neg = 0, all = 0;
		repr(i, n) {
			rep(j, i) fr(k, j + 1, i - 1) {
				int sum = a[i] + a[j] + a[k] - 1;
				if (sum < maxM) res += get(sum);
				else res += all;
				res += neg;
			}
			fr(j, i + 1, n - 1) fr(k, j + 1, n - 1) {
				int val = a[k] - a[j] - a[i];
				if (val <= 0) neg++;
				else {
					update(a[k] - a[j] - a[i]);
					all++;
				}
			}
		}
		printf("Case %d: %d\n", ++caseNo, res);
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */