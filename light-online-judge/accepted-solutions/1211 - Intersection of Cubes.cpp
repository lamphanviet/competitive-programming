//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1211 - Intersection of Cubes 
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
	int n, rx1, rx2, ry1, ry2, rz1, rz2;
	int cases, caseNo = 0, x1, y1, z1, x2, y2, z2;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d", &n);
		rx1 = ry1 = rz1 = -INF;
		rx2 = ry2 = rz2 = INF;
		rep(i, n) {
			scanf("%d %d %d", &x1, &y1, &z1);
			scanf("%d %d %d", &x2, &y2, &z2);
			rx1 = max(rx1, x1); ry1 = max(ry1, y1); rz1 = max(rz1, z1);
			rx2 = min(rx2, x2); ry2 = min(ry2, y2); rz2 = min(rz2, z2);
		}
		if (rx1 > rx2) rx1 = rx2 = 0;
		printf("Case %d: %d\n", ++caseNo, (rx2 - rx1) * (ry2 - ry1) * (rz2 - rz1));
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet