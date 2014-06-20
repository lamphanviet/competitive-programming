//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1269 - Consecutive Sum 
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
#define maxN 50005

struct Node {
	int next[2];
	Node() {
		next[0] = next[1] = -1;
	}
};
int n, a[maxN], mx, mn;
vector<Node> node;

char buff[maxN * 20];
void readLine() {
	gets(buff);
	int len = strlen(buff), i = 0, m = 0;
	while (i < len)
		if (buff[i] != ' ') {
			a[++m] = 0;
			while (i < len && buff[i] != ' ')
				a[m] = a[m] * 10 + buff[i++] - 48;
		}
		else i++;
}

void solve() {
	node.clear();
	node.pb(Node());
	mx = mn = a[1];
	fr(i, 1, n) {
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
		// find min
		int id = 0, value = 0;
		repr(j, 32) {
			int k = a[i] & BIT(j) ? 1 : 0;
			if (node[id].next[k] == -1)
				k = 1 - k;
			if (node[id].next[k] == -1) break;
			value = value * 2 + k;
			id = node[id].next[k];
		}
		mn = min(mn, a[i] ^ value);
		// find max
		id = value = 0;
		repr(j, 32) {
			int k = a[i] & BIT(j) ? 0 : 1;
			if (node[id].next[k] == -1)
				k = 1 - k;
			if (node[id].next[k] == -1) break;
			value = value * 2 + k;
			id = node[id].next[k];
		}
		mx = max(mx, a[i] ^ value);
		// add
		id = 0;
		repr(j, 32) {
			int k = a[i] & BIT(j) ? 1 : 0;
			if (node[id].next[k] == -1) {
				node.pb(Node());
				node[id].next[k] = node.size() - 1;
			}
			id = node[id].next[k];
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	readLine();
	int cases, caseNo = 0;
	for (cases = a[1]; cases--; ) {
		readLine(); n = a[1];
		a[0] = 0;
		readLine();
		fr(i, 1, n) a[i] ^= a[i - 1];
		solve();
		printf("Case %d: %d %d\n", ++caseNo, mx, mn);
	}
	return 0;
}

/* Copyright (C) 2012, LamPhanViet */