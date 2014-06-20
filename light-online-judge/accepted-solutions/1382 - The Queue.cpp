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
#define mod 1000000007

int n, c[maxN][maxN], child[maxN];
vi adj[maxN];
bool mark[maxN];

int dfs(int u) {
	vi val;
	child[u] = 0;
	int sum = 0, res = 1;
	rep(i, adj[u].size()) {
		int v = adj[u][i];
		res = (res * (int64)dfs(v)) % mod;
		val.pb(child[v]);
		sum += child[v];
	}
	child[u] = sum + 1;
	rep(i, val.size()) {
		res = (res * (int64)c[sum][val[i]]) % mod;
		sum -= child[adj[u][i]];
	}
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	rep(i, maxN) {
		c[i][0] = c[i][i] = 1;
		fr(j, 1, i - 1) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
	}
	int cases, caseNo = 0, st, u, v;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d", &n);
		rep(i, n) adj[i].clear(), mark[i] = true;
		rep(_, n - 1) {
			scanf("%d %d", &u, &v); u--; v--;
			adj[u].pb(v);
			mark[v] = false;
		}
		rep(i, n) if (mark[i]) { st = i; break; }		
		printf("Case %d: %d\n", ++caseNo, dfs(st));
	}
	return 0;
}
