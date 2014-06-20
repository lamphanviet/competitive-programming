//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 910 - TV game
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
#define maxN 30

int n, m, f[maxN][maxN], next[maxN][2];
bool end[maxN], inQueue[maxN][maxN], flag[maxN];

int solve() {
	inQueue[0][0] = true;
	f[0][0] = 1;
	queue<ii> q;
	q.push(ii(0, 0));
	while (!q.empty()) {
		ii top = q.front(); q.pop();
		int u = top.ff, len = top.ss;
		
		inQueue[u][len] = false;
		if (len == m) continue;
		
		rep(i, 2) {
			int v = next[u][i];
			f[v][len + 1] += f[u][len];
			if (!inQueue[v][len + 1]) {
				inQueue[v][len + 1] = true;
				q.push(ii(v, len + 1));
			}
		}
		
	}
	int res = 0;
	rep(i, maxN) if (end[i])
		res += f[i][m];
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	char u, v1, v2, spec;
	while (scanf("%d", &n) != EOF) {
		rep(i, maxN) {
			end[i] = false;
			flag[i] = false;
			rep(j, maxN) f[i][j] = 0, inQueue[i][j] = false;
		}
		rep(i, n) {
			scanf(" %c %c %c %c ", &u, &v1, &v2, &spec);
			u -= 'A'; v1 -= 'A'; v2 -= 'A';
			flag[u] = true;
			next[u][0] = v1;
			next[u][1] = v2;
			if (spec == 'x') end[u] = true;
		}
		scanf("%d", &m);
		printf("%d\n", solve());
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet