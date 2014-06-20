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
#define maxN 30011

// input + output optimization: reduce the runtime from 0.661 to 0.372
int cur = 0, len = 0;
char buffer[maxN * 10];
int nextInt() {
	int res = 0;
	while (true) {
		if (cur == len) {
			gets(buffer);
			len = strlen(buffer); cur = 0;
		}
		while (cur < len && !isdigit(buffer[cur])) cur++;
		if (cur == len) continue;
		while (cur < len && isdigit(buffer[cur]))
			res = res * 10 + buffer[cur++] - 48;
		break;
	}
	return res;
}
char out[10];
void println(int n, int m = 0) {
	if (!n) { putchar('0'); putchar('\n'); return; }
	while (n) out[m++] = n % 10 + 48, n /= 10;
	while (m) putchar(out[--m]); putchar('\n');
}
// END input + output optimization

struct BITree {
	vi tree, tmp;
	void clear() { tmp.clear(); tree.clear(); }
	int get(int i) {
		int res = 0;
		while (i) {
			res += tree[i];
			i -= (-i & i);
		}
		return res;
	}
	void update(int i, int val) {
		if (!i) return;
		while (i < tree.size()) {
			tree[i] += val;
			i += (-i & i);
		}
	}
	void build() {
		tree = vi(tmp.size() + 1, 0);
		rep(i, tmp.size()) update(i + 1, tmp[i]);
		tmp.clear();
	}
	void add(int val) { tmp.pb(val); }
} tree[maxN];

int n, genies[maxN], size[maxN];
int parent[maxN], depth[maxN], head[maxN], number[maxN];
bool heavy[maxN];
vi adj[maxN];

int dfs(int u, int p, int lvl) {
	size[u] = 1;
	parent[u] = p;
	depth[u] = lvl;
	rep(i, adj[u].size()) {
		int v = adj[u][i];
		if (v != parent[u]) size[u] += dfs(v, u, lvl + 1);
	}
	return size[u];
}

void build(int u, int hd, int num) {
	number[u] = num;
	head[u] = hd;
	rep(i, adj[u].size()) {
		int v = adj[u][i];
		if (v == parent[u]) continue;
		if (size[v] > size[u] / 2) { // heavy edge
			heavy[v] = true;
			tree[head[u]].add(genies[v]);
			build(v, hd, num + 1);
		}
		else build(v, v, 0);
	}
}

int getLCA(int u, int v) {
	while (head[u] != head[v]) {
		if (depth[head[u]] < depth[head[v]]) swap(u, v);
		if (heavy[u]) u = head[u];
		else u = parent[u];
	}
	if (depth[u] < depth[v]) return u;
	return v;
}

int getLength(int u) { // get total genies from root (0) to u
	int res = 0;
	while (u != -1) {
		if (heavy[u]) {
			res += tree[head[u]].get(number[u]);
			u = head[u];
		}
		else {
			res += genies[u];
			u = parent[u];
		}
	}
	return res;
}

void update(int u, int val) {
	if (heavy[u]) tree[head[u]].update(number[u], -genies[u] + val);
	genies[u] = val;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, m, u, v, q;
	for (cases = nextInt(); cases--; ) {
		n = nextInt();
		rep(i, n) {
			genies[i] = nextInt();
			adj[i].clear(); tree[i].clear();
			heavy[i] = false;
		}
		rep(i, n-1) {
			u = nextInt(); v = nextInt();
			adj[u].pb(v); adj[v].pb(u);
		}
		dfs(0, -1, 0);
		build(0, 0, 0);
		rep(i, n) tree[i].build();
		//rep(i, n) printf("%d: size %d | heavy %d | parent %d | head %d | number %d\n", i, size[i], heavy[i], parent[i], head[i], number[i]);
		printf("Case %d:\n", ++caseNo);
		m = nextInt();
		while (m--) {
			//scanf("%d %d %d", &q, &u, &v);
			q = nextInt(); u = nextInt(); v = nextInt();
			if (q) update(u, v);
			else {
				q = getLCA(u, v);
				//printf("%d %d: %d %d => %d: %d\n", u, v, getLength(u), getLength(v), q, getLength(q));
				println(getLength(u) + getLength(v) - 2 * getLength(q) + genies[q]);
			}
		}
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet
// Test Cases:
// 3
// 4
// 10 20 30 40
// 0 1
// 1 2
// 1 3
// 6
// 0 2 3
// 1 1 100
// 0 2 3
// 0 0 3
// 0 3 0
// 0 0 2
// 
// 7
// 0 1 2 3 4 5 6
// 0 6
// 0 1
// 1 5
// 1 2
// 2 3
// 3 4
// 4
// 0 0 4
// 0 4 6
// 0 5 6
// 0 3 4
// 
// 11
// 0 1 2 3 4 5 6 7 8 9 10
// 0 1
// 1 3
// 1 2
// 2 4
// 2 5
// 5 6
// 6 7
// 6 8
// 6 9
// 6 10
// 1
// 0 4 6
// Answer:
// Case 1:
// 90
// 170
// 150
// 150
// 140
// Case 2:
// 10
// 16
// 12
// 7
// Case 3:
// 17
