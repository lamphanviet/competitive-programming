//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10129 - Play on Words
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

int n, cnt[maxN][maxN], in[maxN], out[maxN], c[maxN][maxN];
bool flag[maxN];
char s[1011];

bool canGoBack(int x, int y) {
	rep(i, n) flag[i] = true;
	flag[y] = false;
	cnt[x][y]--;
	queue<int> q;
	q.push(y);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (!flag[x]) break;
		rep(v, n)
			if (flag[v] && cnt[u][v]) {
				flag[v] = false;
				q.push(v);
			}
	}
	cnt[x][y]++;
	return !flag[x];
}

bool check(int u) {
	while (true) {
		int next = -1;
		rep(v, n) {
			if (!cnt[u][v]) continue;
			if (canGoBack(u, v)) {
				next = v;
				break;
			}
			else next = v;
		}
		if (next == -1) break;
		cnt[u][next]--;
		u = next;
	}
	
	rep(i, maxN) rep(j, maxN)
		if (cnt[i][j]) return false;
	return true;
}

bool solve() {
	rep(i, n)
		if (in[i]) {
			rep(x, n) rep(y, n)
				cnt[x][y] = c[x][y];
			if (check(i)) return true;
		}
	return false;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases = 0, m;
	for (scanf("%d ", &cases); cases--; ) {
		scanf(" %d ", &n);
		rep(i, maxN) {
			rep(j, maxN)
				c[i][j] = 0;
			in[i] = out[i] = 0;
		}
		rep(i, n) {
			scanf(" %s ", s);
			m = strlen(s);
			c[s[0] - 'a'][s[m - 1] - 'a']++;
			in[s[0] - 'a']++;
			out[s[m - 1] - 'a']++;
		}
		n = 26;
		if (!solve()) puts("The door cannot be opened.");
		else puts("Ordering is possible.");
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet