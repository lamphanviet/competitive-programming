//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1164 - Horrible Queries 
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
#define maxN 100001

int n, q, inc[maxN * 5];
int64 sum[maxN * 5], res;

void update(int p, int lo, int hi, int lf, int rg, int val) {
	if (hi < lf || rg < lo) return;
	if (lf <= lo && hi <= rg) {
		inc[p] += val;
		return;
	}
	if (lo == hi) return;
	int mid = (lo + hi) >> 1, c = p << 1;
	update(c, lo, mid, lf, rg, val);
	update(c + 1, mid + 1, hi, lf, rg, val);
	sum[p] = sum[c] + sum[c + 1] + inc[c] * (int64)(mid - lo + 1) + inc[c + 1] * (int64)(hi - mid);
}

void get(int p, int lo, int hi, int lf, int rg) {
	if (hi < lf || rg < lo) return;
	if (lf <= lo && hi <= rg) {
		res += sum[p];
		res += inc[p] * (int64)(hi - lo + 1);
		return;
	}
	if (lo == hi) return;
	int mid = (lo + hi) >> 1, c = p << 1;
	get(c, lo, mid, lf, rg);
	get(c + 1, mid + 1, hi, lf, rg);
	lo = max(lo, lf);
	hi = min(hi, rg);
	if (hi >= lo) res += inc[p] * (int64)(hi - lo + 1);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, lf, rg, val, ques;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d", &n, &q);
		rep(i, n * 5) sum[i] = inc[i] = 0;
		printf("Case %d:\n", ++caseNo);
		while (q--) {
			scanf("%d", &ques);
			scanf("%d %d", &lf, &rg);
			if (ques) {
				res = 0LL;
				get(1, 0, n - 1, lf, rg);
				printf("%lld\n", res);
			}
			else {
				scanf("%d", &val);
				update(1, 0, n - 1, lf, rg, val);
			}
		}
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */