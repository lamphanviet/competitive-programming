//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1169 - Monkeys on Twin Tower 
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
#define maxN 1011

int n, costX[maxN], costY[maxN], fx[maxN], fy[maxN], jumpX[maxN], jumpY[maxN];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d", &n);
		rep(i, n) scanf("%d", &costX[i]);
		rep(i, n) scanf("%d", &costY[i]);
		rep(i, n - 1) scanf("%d", &jumpX[i]);
		rep(i, n - 1) scanf("%d", &jumpY[i]);
		fx[0] = costX[0];
		fy[0] = costY[0];
		fr(i, 1, n - 1) {
			fx[i] = min(fx[i - 1], fy[i - 1] + jumpY[i - 1]) + costX[i];
			fy[i] = min(fy[i - 1], fx[i - 1] + jumpX[i - 1]) + costY[i];
		}
		printf("Case %d: %d\n", ++caseNo, min(fx[n - 1], fy[n - 1]));
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet