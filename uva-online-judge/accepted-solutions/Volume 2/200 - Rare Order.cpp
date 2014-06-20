//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 200 - Rare Order
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
#define maxN 30

int n, m;
vector<int> adj[maxN], sortedNode;
vector<char> name;
int idx[maxN];
char s[10000][maxN];
bool visited[maxN];

int getIndex(char ch) {
	int id = idx[ch - 'A'];
	if (id == 0) {
		name.pb(ch);
		id = idx[ch - 'A'] = ++n;
		adj[id].clear();
	}
	return id;
}

void buildGraph() {
	for (int i = 0; i < m - 1; i++) {
		int len1 = strlen(s[i]), len2 = strlen(s[i + 1]);
		int u = 0, v = 0;
		while (u < len1 && v < len2 && s[i][u] == s[i + 1][v])
			u++, v++;
		if (u < len1 && v < len2)
			adj[s[i][u]].pb(s[i + 1][v]);
	}
}

void visit(int u) {
	visited[u] = true;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (!visited[v]) visit(v);
	}
	sortedNode.pb(u);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	while (gets(s[0])) {
		name.resize(1);
		fill(idx, 0);
		n = m = 0;
		do {
			if (!strcmp(s[m], "#")) break;
			m++;
			for (int i = 0, len = strlen(s[m - 1]); i < len; i++)
				s[m - 1][i] = getIndex(s[m - 1][i]);
		} while (gets(s[m]));
		buildGraph();
		fill(visited, false);
		for (int i = 1; i <= n; i++)
			if (!visited[i]) visit(i);
		for (int i = sortedNode.size() - 1; i >= 0; i--)
			printf("%c", name[sortedNode[i]]);
		putchar('\n');
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet