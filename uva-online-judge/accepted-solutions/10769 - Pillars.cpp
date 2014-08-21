//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10769 - Pillars
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
#define maxN 111

char buff[maxN * 20];
void parse(int *a, int &n) {
	n = 0;
	int i = 0, len = strlen(buff);
	while (i < len)
		if (isdigit(buff[i])) {
			a[n] = 0;
			while (i < len && isdigit(buff[i]))
				a[n] = a[n] * 10 + buff[i++] - 48;
			n++;
		}
		else i++;
}

int H, n, m, a[maxN], b[maxN];
vii p;

bool bigger(vi &x, vi &y) {
	rep(i, 4)
		if (x[i] != y[i])
			return x[i] > y[i];
	return false;
}

bool cmp(ii x, ii y) {
	if (x.ff + x.ss == y.ff + y.ss)
		return x > y;
	return x.ff + x.ss < y.ff + y.ss;
}

bool solve() {
	vi res(4, -1), tmpres(4, 0);
	rep(i, n) fr(j, i + 1, n - 1) {
		int sum = H - a[i] - a[j];
		//if (sum < 0) continue;
		int lo = 0, hi = p.size() - 1, pos = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (p[mid].ff + p[mid].ss >= sum) {
				if (p[mid].ff + p[mid].ss == sum)
					pos = mid;
				hi = mid - 1;
			}
			else lo = mid + 1;
		}
		//printf("%d - %d: > (%d %d) %d - %d\n", i, j, a[i], a[j], sum, pos);
		if (pos != -1) {
			tmpres[0] = a[i];
			tmpres[1] = p[pos].ff;
			tmpres[2] = a[j];
			tmpres[3] = p[pos].ss;
			if (bigger(tmpres, res)) res = tmpres;
		}
	}
	if (res != vector<int>(4, -1)) {
		rep(i, 4) printf("%d%c", res[i], i == 3 ? '\n' : ' ');
		return true;
	}
	return false;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	while (scanf(" %d ", &H) != EOF) {
		gets(buff);
		parse(a, n);
		gets(buff);
		parse(b, m);
		sort(a, a + n); reverse(a, a + n);
		sort(b, b + m); reverse(b, b + m);
		//rep(i, n) printf("%5d", a[i]); puts("");
		//rep(i, m) printf("%5d", b[i]); puts("");
		p.clear();
		rep(i, m) fr(j, i + 1, m - 1)
			p.pb(ii(b[i], b[j]));
		//rep(i, p.size())
	//		printf("(%d %d\n", p[i].ff, p[i].ss);
		sort(all(p), cmp);
		if (!solve()) puts("no solution");
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */
