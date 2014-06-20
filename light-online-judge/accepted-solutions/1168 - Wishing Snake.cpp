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
#define maxN 1001

const int n = 1000;
int number[maxN], low[maxN], idx, nreg, reg[maxN], deg[maxN];
bool exist[maxN], root[maxN];
stack<int> st;
vi adj[maxN];

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
		do {
			v = st.top(); st.pop();
			reg[v] = nreg;
		} while (v != u);
		nreg++;
	}
}

bool solve() {
	st = stack<int>();
	idx = nreg = 0;
	rep(u, n) if (exist[u] && number[u] == 0) visit(u);
	rep(u, n) if (exist[u]) {
		rep(i, adj[u].size()) {
			int v = adj[u][i];
			if (reg[u] != reg[v]) {
				deg[reg[u]]++;
				root[reg[v]] = false;
			}
		}
	}
	int node = -1;
	rep(i, nreg) {
		if (deg[i] > 1) return false;
		if (root[i]) {
			if (node < 0) node = i;
			else return false;
		}
	}
	return reg[0] == node;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, m, k, u, v;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d", &m);
		rep(i, n) {
			reg[i] = -1;
			adj[i].clear();
			exist[i] = false;
			root[i] = true;
			number[i] = low[i] = deg[i] = 0;
		}
		rep(i, m) {
			scanf("%d", &k);
			while (k--) {
				scanf("%d %d", &u, &v);
				adj[u].pb(v);
				exist[u] = exist[v] = true;
			}
		}
		printf("Case %d: %s\n", ++caseNo, solve() ? "YES" : "NO");
	}
	return 0;
}
