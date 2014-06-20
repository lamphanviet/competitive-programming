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
#define maxN 10

const int n = 9;
char s[maxN][maxN];
int row[maxN], col[maxN], reg[3][3];
vii cell;
map<int, int> pos;
int res[maxN][maxN];
bool found;

void backTrack(int i) {
	if (i == cell.size()) found = true;
	if (found) return;
	int x = cell[i].ff, y = cell[i].ss;
	int avail = row[x] & col[y] & reg[x/3][y/3];
	while (avail) {
		if (found) return;
		int j = -avail & avail;
		res[x][y] = j;
		row[x] ^= j; col[y] ^= j; reg[x/3][y/3] ^= j;
		backTrack(i + 1);
		row[x] ^= j; col[y] ^= j; reg[x/3][y/3] ^= j;
		avail ^= j;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	rep(i, 10) pos[BIT(i)] = i;
	int cases, caseNo = 0;
	for (scanf(" %d ", &cases); cases--; ) {
		rep(i, n) row[i] = col[i] = 511;
		rep(i, 3) rep(j, 3) reg[i][j] = 511;
		fill(res, 0);
		cell.clear();
		rep(i, n) {
			scanf(" %s ", s[i]);
			rep(j, n) if (isdigit(s[i][j])) {
				int x = BIT(s[i][j] - '1');
				row[i] &= ~x;
				col[j] &= ~x;
				reg[i / 3][j / 3] &= ~x;
			}
			else cell.pb(ii(i, j));
		}
		found = false;
		reverse(all(cell));
		if (cell.size()) backTrack(0);
		printf("Case %d:\n", ++caseNo);
		rep(i, n) {
			rep(j, n) if (isdigit(s[i][j])) putchar(s[i][j]);
			else putchar(pos[res[i][j]] + 49);
			//else putchar('*');
			puts("");
		}
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet