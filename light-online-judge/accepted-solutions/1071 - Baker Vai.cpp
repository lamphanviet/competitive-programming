//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 
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

const int dx[] = { 0, 0, 1, 1 };
const int dy[] = { 0, 1, 0, 1 };
int n, m, a[maxN][maxN], f[maxN][maxN][2 * maxN];

bool inside(int x, int y) { return (0 <= x && x < n && 0 <= y && y < m); }

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d", &n, &m);
		rep(i, n) rep(j, m)
			scanf("%d", &a[i][j]);
		fill(f, -1);
		f[0][0][0] = a[0][0];
		f[0][1][1] = f[1][0][1] = a[0][0] + a[0][1] + a[1][0];
		fr(len, 1, n + m - 3) {
			rep(r1, n) rep(r2, n) if (f[r1][r2][len] != -1) {
				rep(i, 4) {
					int nr1 = r1 + dx[i], nr2 = r2 + dy[i];
					int c1 = len + 1 - nr1, c2 = len + 1 - nr2;
					if (!inside(nr1, c1) || !inside(nr2, c2)) continue;
					if (nr1 == nr2 && c1 == c2) {
						if (nr1 == n - 1 && c1 == m - 1) {
							f[nr1][nr2][len + 1] = max(f[nr1][nr2][len + 1], f[r1][r2][len] + a[n - 1][m - 1]);
						}
					}
					else {
						f[nr1][nr2][len + 1] = max(f[nr1][nr2][len + 1], f[r1][r2][len] + a[nr1][c1] + a[nr2][c2]);
					}
				}
			}
		}
		printf("Case %d: %d\n", ++caseNo, f[n - 1][n - 1][n + m - 2]);
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */