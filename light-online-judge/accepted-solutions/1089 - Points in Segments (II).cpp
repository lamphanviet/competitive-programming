//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1089 - Points in Segments (II) 
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
#define maxN 50005

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

int n, m, q, tree[maxN * 20], p[maxN];
map<int, int> idx;
ii s[maxN];

void update(int p, int lo, int hi, int lf, int rg) {
	if (hi < lf || rg < lo) return;
	if (lf <= lo && hi <= rg) {
		tree[p]++;
		return;
	}
	if (lo == hi) return;
	int mid = (lo + hi) >> 1, c = p << 1;
	update(c, lo, mid, lf, rg);
	update(c + 1, mid + 1, hi, lf, rg);
}

int get(int p, int lo, int hi, int x) {
	if (x < lo || hi < x) return 0;
	if (lo == hi) return tree[p];
	int mid = (lo + hi) >> 1, c = p << 1;
	return get(c, lo, mid, x) + get(c + 1, mid + 1, hi, x) + tree[p];
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (cases = nextInt(); cases--; ) {
		n = nextInt(); q = nextInt();
		idx.clear();
		rep(i, n) {
			s[i].ff = nextInt();
			s[i].ss = nextInt();
			idx[s[i].ff] = 1;
			idx[s[i].ss] = 1;
		}
		rep(i, q) {
			p[i] = nextInt();
			idx[p[i]] = 1;
		}
		m = 0;
		foreach(it, idx) it->ss = ++m;
		rep(i, m * 5) tree[i] = 0;
		rep(i, n) update(1, 1, m, idx[s[i].ff], idx[s[i].ss]);
		
		printf("Case %d:\n", ++caseNo);
		rep(i, q) printf("%d\n", get(1, 1, m, idx[p[i]]));
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */