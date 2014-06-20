//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Online Judge : UVa
// Problem Name : 12442 - Forwarding Emails
// Time Limit   : 1.000s
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
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define bit(n) (1<<(n))
#define Last(i) ( (i) & (-i) )
#define sq(x) ((x) * (x))
#define INF 1000111222
#define eps 1e-7
#define maxN 50005
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, next[maxN], counter;
int low[maxN], number[maxN];
int maxLen, minNode, len[maxN];
stack<int> s;

void dfs(int u) {
	low[u] = number[u] = ++counter;
	s.push(u);
	int v = next[u];
	if (number[v] == 0) {
		dfs(v);
		low[u] = min(low[u], low[v]);
	}
	else if (number[v] > 0) {
		low[u] = min(low[u], number[v]);
	}
	if (low[u] == number[u]) {
		int tmpMinNode = n + 1;
		vi node;
		do {
			v = s.top();
			node.pb(v);
			tmpMinNode = min(tmpMinNode, v);
			number[v] = -1;
			s.pop();
		} while (v != u);
		if (node.size() == 1) {
			len[u] = len[next[u]] + 1;
			if (len[u] > maxLen || (len[u] == maxLen && u < minNode)) {
				maxLen = len[u];
				minNode = u;
			}
		}
		else {
			for (int i = 0; i < node.size(); i++) {
				len[node[i]] = node.size();
			}
			if (node.size() > maxLen || (node.size() == maxLen && tmpMinNode < minNode)) {
				maxLen = node.size();
				minNode = tmpMinNode;
			}
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int caseNo, cases = 0, u, v;
	scanf("%d", &caseNo);
	while (caseNo--) {
		scanf("%d ", &n);
		for (int i = 1; i <= n; i++) {
			number[i] = 0;
			len[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &u, &v);
			next[u] = v;
		}
		s = stack<int>();
		maxLen = minNode = counter = 0;
		for (int i = 1; i <= n; i++)
			if (!number[i])
				dfs(i);
		printf("Case %d: %d\n", ++cases, minNode);
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet
