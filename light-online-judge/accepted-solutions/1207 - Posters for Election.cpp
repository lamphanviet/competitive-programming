//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1207 - Posters for Election 
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

int n, tree[maxN * 10];
bool flag[maxN];

void update(int p, int lo, int hi, int lf, int rg, int clr, int pr) {
	if (pr != -1) tree[p] = pr;
	if (rg < lo || hi < lf) return;
	if (lf <= lo && hi <= rg) {
		tree[p] = clr;
		return;
	}
	if (lo == hi) return;
	int mid = (lo + hi) >> 1, c = p << 1;
	update(c, lo, mid, lf, rg, clr, tree[p]);
	update(c + 1, mid + 1, hi, lf, rg, clr, tree[p]);
	tree[p] = -1;
}

void get(int p, int lo, int hi) {
	if (tree[p] >= 0) {
		flag[tree[p]] = true;
		return;
	}
	if (lo == hi) return;
	int mid = (lo + hi) >> 1, c = p << 1;
	get(c, lo, mid);
	get(c + 1, mid + 1, hi);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, lf, rg;
	for (cases = nextInt(); cases--; ) {
		n = nextInt();
		rep(i, n * 10) tree[i] = -1;
		rep(i, n) {
			flag[i] = false;
			lf = nextInt();
			rg = nextInt();
			update(1, 1, n << 1, lf, rg, i, -1);
		}
		get(1, 1, n << 1);
		int res = 0;
		rep(i, n) if (flag[i])
			res++;
		printf("Case %d: %d\n", ++caseNo, res);
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */
