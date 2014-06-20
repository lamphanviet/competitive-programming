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
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 50111

int n, nreg, idx;
int number[maxN], low[maxN], reg[maxN];
int minNode[maxN], size[maxN];
vi adj[maxN], regAdj[maxN];
stack<int> st;

void visit(int u) {
	st.push(u);
	number[u] = low[u] = ++idx;
	rep(i, adj[u].size()) {
		int v = adj[u][i];
		if (reg[v] >= 0) continue;
		if (number[v]) low[u] = min(low[u], number[v]);
		else {
			visit(v);
			low[u] = min(low[u], low[v]);
		}
	}
	if (number[u] == low[u]) {
		int v;
		minNode[nreg] = n;
		size[nreg] = 0;
		do {
			v = st.top(); st.pop();
			reg[v] = nreg;
			minNode[nreg] = min(minNode[nreg], v);
			size[nreg]++;
		} while (v != u);
		nreg++;
	}
}

int dfs(int u) {
	int res = size[u];
	rep(i, regAdj[u].size())
		res += dfs(regAdj[u][i]);
	return res;
}

int solve() {
	nreg = idx = 0;
	st = stack<int>();
	fr(i, 1, n) if (!number[i]) visit(i);
	
	fr(u, 1, n) {
		rep(i, adj[u].size()) {
			int v = adj[u][i];
			if (reg[u] != reg[v]) regAdj[reg[u]].pb(reg[v]);
		}
	}
	
	int maxNodes = 0, resNode = 1;
	rep(i, nreg) {
		int tmpSize = dfs(i);
		if (tmpSize > maxNodes || (tmpSize == maxNodes && minNode[i] < resNode)) {
			maxNodes = tmpSize;
			resNode = minNode[i];
		}
	}
	return resNode;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, u, v;
	for (scanf("%d", &cases); cases--; ) {
		scanf(" %d ", &n);
		fr(i, 0, n) {
			adj[i].clear();
			regAdj[i].clear();
			number[i] = low[i] = 0;
			reg[i] = -1;
		}
		rep(_, n) {
			scanf("%d %d", &u, &v);
			adj[u].pb(v);
		}
		printf("Case %d: %d\n", ++caseNo, solve());
	}
	return 0;
}
