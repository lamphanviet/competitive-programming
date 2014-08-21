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
#define maxN 200002

bool nextInt(int &n) {
	n = 0;
	char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	do {
		n = n * 10 + ch - 48;
		ch = getchar();
	} while ('0' <= ch && ch <= '9');
	return true;
}

struct Edge {
	int u, v, cost;
	bool operator < (const Edge &e) const { return cost < e.cost; }
} edge[maxN];
int n, m, lab[maxN];

int getRoot(int u) {
	if (lab[u] < 0) return u;
	return lab[u] = getRoot(lab[u]);
}

void unionSet(int r1, int r2) {
	int x = lab[r1] + lab[r2];
	if (lab[r1] > lab[r2]) {
		lab[r1] = r2;
		lab[r2] = x;
	}
	else {
		lab[r1] = x;
		lab[r2] = r1;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	while ((nextInt(n) && nextInt(m)) && (n || m)) {
		int res = 0;
		rep(i, m) {
			//scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].cost);
			nextInt(edge[i].u);
			nextInt(edge[i].v);
			nextInt(edge[i].cost);
			res += edge[i].cost;
		}
		sort(edge, edge + m);
		rep(i, n) lab[i] = -1;
		for (int i = 0, counter = 0; i < m && counter < n - 1; i++) {
			edge[i].u = getRoot(edge[i].u);
			edge[i].v = getRoot(edge[i].v);
			if (edge[i].u != edge[i].v) {
				res -= edge[i].cost;
				counter++;
				unionSet(edge[i].u, edge[i].v);
			}
		}
		printf("%d\n", res);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet