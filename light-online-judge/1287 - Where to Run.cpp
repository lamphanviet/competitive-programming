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
#define maxN 16

int n;
vii adj[maxN];
double f[maxN][BIT(maxN)];
short int booEJ[maxN][BIT(maxN)];

bool isEJ(int u, int mask) {
	short int &res = booEJ[u][mask];
	if (res >= 0) return res;
	
	//printf("cal %d %d\n", u, mask);
	
	if (mask == BIT(n) - 1) return res = 1;
	
	res = 0;
	
	rep(i, adj[u].size()) {
		int v = adj[u][i].ff;
		if (!(mask & BIT(v))) {
			res |= isEJ(v, mask ^ BIT(v));
		}
	}
	
	return res;
}

double step(int u, int mask) {
	double &res = f[u][mask];
	if (res >= 0.0) return res;
	res = 0.0;
	
	vii ej;
	rep(i, adj[u].size()) {
		int v = adj[u][i].ff;
		if (!(mask & BIT(v)) && isEJ(v, mask ^ BIT(v))) ej.pb(adj[u][i]);
	}
	
	//printf("%d %d:: %d\n", u, mask, ej.size());
	
	if (ej.size() == 0) return res = 0.0;
	
	rep(i, ej.size()) {
		int v = adj[u][i].ff, w = adj[u][i].ss;
		res += (step(v, mask ^ BIT(v)) + w) * (1.0 / ej.size());
	}
	
	res += 5;
	
	//printf("%d %d: %d\n", u, mask, u);
	
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, u, v, w, m;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d", &n, &m);
		rep(i, n) repr(j, BIT(n)) f[i][j] = booEJ[i][j] = -1;
		rep(i, n) adj[i].clear();
		while (m--) {
			scanf("%d %d %d", &u, &v, &w);
			adj[u].pb(mp(v, w));
			adj[v].pb(mp(u, w));
		}
		printf("Case %d: %.12lf\n", ++caseNo, step(0, 1));
	}
	return 0;
}
