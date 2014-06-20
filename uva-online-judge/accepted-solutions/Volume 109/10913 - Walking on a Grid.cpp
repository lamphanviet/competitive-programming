//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10913 - Walking on a Grid
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
#define maxN 80

int n, k, f[maxN][maxN][6], a[maxN][maxN];
bool reach[maxN][maxN][6];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int caseNo = 0;
	while (scanf("%d %d", &n, &k) && (n | k)) {
		fr(i, 1 , n) fr(j, 1 , n)
			scanf("%d", &a[i][j]);
		
		fill(reach, false);
		
		int st = a[1][1] < 0 ? 1 : 0, cur = a[1][1];
		
		f[1][1][st] = a[1][1];
		reach[1][1][st] = true;
		
		fr(i, 2, n) {
			if (a[1][i] < 0) st++;
			if (st > k) break;
			f[1][i][st] = cur + a[1][i];
			cur = f[1][i][st];
			reach[1][i][st] = true;
		}
		
		fr(i, 2, n) fr(j, 1, n) {
			fr(x, 0, k) if (reach[i - 1][j][x]) {
				st = x + (a[i][j] < 0 ? 1 : 0);
				if (st > k) continue;
				cur = f[i - 1][j][x] + a[i][j];
				if (!reach[i][j][st]) f[i][j][st] = cur;
				else f[i][j][st] = max(f[i][j][st], cur);
				reach[i][j][st] = true;
				
				frr(col, j - 1, 1) { // go left
					if (a[i][col] < 0) st++;
					if (st > k) break;
					cur += a[i][col];
					if (!reach[i][col][st]) f[i][col][st] = cur;
					else f[i][col][st] = max(f[i][col][st], cur);
					reach[i][col][st] = true;
				}
				
				st = x + (a[i][j] < 0 ? 1 : 0);
				cur = f[i - 1][j][x] + a[i][j];
				
				fr(col, j + 1, n) { // go right
					if (a[i][col] < 0) st++;
					if (st > k) break;
					cur += a[i][col];
					if (!reach[i][col][st]) f[i][col][st] = cur;
					else f[i][col][st] = max(f[i][col][st], cur);
					reach[i][col][st] = true;
				}
			}
		}
		int res;
		bool solved = false;
		fr(i, 0, k) if (reach[n][n][i]) {
			if (!solved) res = f[n][n][i];
			else res = max(res, f[n][n][i]);
			solved = true;
		}
		printf("Case %d: ", ++caseNo);
		if (!solved) puts("impossible");
		else printf("%d\n", res);
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */
