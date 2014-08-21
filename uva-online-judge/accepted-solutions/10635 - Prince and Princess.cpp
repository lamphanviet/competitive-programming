//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10635 - Prince and Princess
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
#define maxN 62505

int n, p, q, a[maxN], b[maxN], idx[maxN];

int solve() {
    idx[a[0]] = 1;
    fr(i, 1, p - 1) idx[a[i]] = idx[a[i - 1]] + 1;
	vi v; v.pb(idx[b[0]]);
	fr(i, 1, q - 1) {
		//printf("%d ", idx[b[i]]); 
		if (idx[b[i]] < 0) continue;
		b[i] = idx[b[i]];
		if (v.back() < b[i]) {
			v.pb(b[i]);
			continue;
		}
		int lo = 0, hi = v.size() - 1, pos = 0;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (v[mid] < b[i]) {
				pos = mid + 1;
				lo = mid + 1;
			}
			else hi = mid - 1;
		}
		if (b[i] < v[pos]) v[pos] = b[i];
	}
	return v.size();
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("test.inp", "r", stdin);
        //freopen("test.out", "w", stdout);
    #endif
    int cases, caseNo = 0;
    for (scanf("%d", &cases); cases--; ) {
        scanf("%d %d %d", &n, &p, &q); p++; q++;
        fr(i, 1, n * n) idx[i] = -1;
        rep(i, p) scanf("%d", &a[i]);
        rep(i, q) scanf("%d", &b[i]);
        printf("Case %d: %d\n", ++caseNo, solve());
    }
    return 0;
}

/* Copyright (C) 2012, LamPhanViet */
