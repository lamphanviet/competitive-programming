//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1158 - Anagram Division
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

#define fr(i,a,b) for (int i = (a); i <= (b); i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0; i < (n); i++)
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
#define maxN 11

int n, m, d, counter[maxN], fact[maxN];
int f[BIT(maxN)][1011];
char s[maxN];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	fact[0]  = 1;
	fr(i, 1, maxN - 1) fact[i] = fact[i - 1] * i;
	int cases, caseNo = 0;
	for (scanf(" %d ", &cases); cases--; ) {
		scanf(" %s %d ", s, &d);
		n = strlen(s); m = BIT(n);
		rep(i, n) s[i] -= '0';
		rep(i, m) rep(j, d) f[i][j] = 0;
		f[0][0] = 1;
		rep(i, m) rep(j, d) {
			if (!f[i][j]) continue;
			rep(k, n) {
				if (i & (1 << k)) continue;
				f[i | BIT(k)][(j * 10 + s[k]) % d] += f[i][j];
			}
		}
		fr(i, 0, 9) counter[i] = 0;
		rep(i, n) counter[s[i]]++;
		fr(i, 0, 9) if (counter[i] > 1)
		f[m - 1][0] /= fact[counter[i]];
		printf("Case %d: %d\n", ++caseNo, f[m - 1][0]);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet
