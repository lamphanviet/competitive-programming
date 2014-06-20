//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10158 - War
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
#define maxN 10011

int n, lab[maxN], e[maxN];

int getRoot(int u) {
	if (u < 0) return u;
	if (lab[u] < 0) return u;
	return lab[u] = getRoot(lab[u]);
}

int unionSet(int u, int v) {
	if (u < 0 || v < 0)
		return (u >= 0) ? u : v;
	if (u == v) return u;
	int x = lab[u] + lab[v];
	if (lab[u] > lab[v]) {
		lab[u] = v;
		lab[v] = x;
		return v;
	}
	else {
		lab[u] = x;
		lab[v] = u;
		return u;
	}
}

bool areFriends(int u, int v) { return u == v; }

bool areEnemies(int u, int v) { return e[u] == v; }

void setFriends(int u, int v) {
	if (u < 0 || v < 0) return;
	if (u == v) return;
	int x = unionSet(u, v);
	int y = unionSet(e[u], e[v]);
	if (x >= 0) e[x] = y;
	if (x >= 0) e[y] = x;
}

void setEnemies(int u, int v) {
	if (u < 0 || v < 0) return;
	if (e[u] == v) return;
	int x = unionSet(e[u], v);
	int y = unionSet(e[v], u);
	if (x >= 0) e[x] = y;
	if (y >= 0) e[y] = x;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int q, u, v;
	scanf("%d", &n);
	rep(i, n) e[i] = lab[i] = -1;
	while (scanf("%d %d %d", &q, &u, &v) != EOF) {
		if (!(q | u | v)) break;
		u = getRoot(u); v = getRoot(v);
		if (q == 1) {
			if (areEnemies(u, v)) puts("-1");
			else setFriends(u, v);
		}
		else if (q == 2) {
			if (areFriends(u, v)) puts("-1");
			else setEnemies(u, v);
		}
		else if (q == 3) {
			printf("%d\n", areFriends(u, v));
		}
		else if (q == 4) {
			printf("%d\n", areEnemies(u, v));
		}
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet