//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 11402 - Ahoy, Pirates!
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

#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for (int i = (n) - 1; i >= 0; i--)
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
#define maxN 1024111
#define maxSN 2111

int n, nn, res;
int bit[maxSN], inv[maxSN];
vector<bool> s;

void process(int a, int b, char cmd) {
	int u = a / nn, v = b / nn;
	//printf("ab %d %d - uv %d %d - %c\n", a, b, u, v, cmd);
	if (u == v) {
		if (a % nn == 0 && (b + 1) % nn == 0) {
			if (cmd =='E') bit[u] = 0;
			else if (cmd == 'F') bit[u] = nn;
			else if (cmd == 'I') bit[u] = nn - bit[u];
			else res += bit[u];
			if (cmd == 'I') inv[u]++;
			else if (cmd == 'E' || cmd== 'F') inv[u] = 0;
		}
		else {
			int x = (a / nn) * nn;
			int y = min(x + nn, n);
			for (int i = x; i < y; i++)
				if (bit[u] == nn) s[i] = true;
				else if (bit[u] == 0) s[i] = false;
				else if (inv[u] & 1) s[i] = !s[i];
			inv[u] = 0;
			for (int i = a; i <= b; i++) {
				if (cmd == 'E') s[i] = false;
				else if (cmd == 'F') s[i] = true;
				else if (cmd == 'I') s[i] = !s[i];
				else if (s[i]) res++;
			}
			bit[u] = 0;
			for (int i = x; i < y; i++)
				if (s[i]) bit[u]++;
		}
		return;
	}
	if (a == b) return;
	while (a <= b) {
		int next = min((a / nn) * nn + nn - 1, n - 1);
		if (next < b) {
			process(a, next, cmd);
			a = next + 1;
		}
		else {
			process(a, b, cmd);
			break;
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	char tmp[55], q;
	int cases, caseNo = 0, m, k, a, b;
	for (scanf("%d", &cases); cases--; ) {
		s.clear();
		scanf("%d", &m);
		while (m--) {
			scanf(" %d ", &k);
			scanf(" %s ", &tmp);
			while (k--) {
				for (int i = 0, len = strlen(tmp); i < len; i++)
					if (tmp[i] == '0') s.pb(false);
					else s.pb(true);
			}
		}
		n = s.size(); k = 0; nn = sqrt(n);
		fill(bit, 0);
		fill(inv, 0);
		for (int i = 0; i < n; i++)
			if (s[i]) bit[i / nn]++;
		printf("Case %d:\n", ++caseNo);
		scanf("%d", &m);
		while (m--) {
			scanf(" %c %d %d ", &q, &a, &b);
			res = 0;
			process(a, b, q);
			//cout << s << endl;
			if (q == 'S') printf("Q%d: %d\n", ++k, res);
		}
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet