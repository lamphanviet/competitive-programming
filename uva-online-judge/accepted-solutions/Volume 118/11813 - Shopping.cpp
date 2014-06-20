//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 11813 - Shopping
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

typedef pair<int64, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 99999999999999999LL
#define eps 1e-7
#define maxN 100011
#define maxS 11

int n, ns, stores[maxS];
int64 dist[maxN], d[maxS][maxS], f[maxS][BIT(maxS)];
vector< pair<int, int> > adj[maxN];

void dijkstra(int u, int su) {
	rep(i, n) dist[i] = INF;
	dist[u] = 0;
	set<ii> heap;
	heap.insert(mp(dist[u], u));
	while (!heap.empty()) {
		ii top = *heap.begin(); heap.erase(top);
		int u = top.ss;
		rep(i, adj[u].size()) {
			int v = adj[u][i].ff, w = adj[u][i].ss;
			if (dist[v] > dist[u] + w) {
				if (dist[v] != INF) heap.erase(mp(dist[v], v));
				dist[v] = dist[u] + w;
				heap.insert(mp(dist[v], v));
			}
		}
	}
	rep(i, ns) d[su][i] = d[i][su] = dist[stores[i]];
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, u, v, w, m;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d", &n, &m);
		rep(i, n) adj[i].clear();
		while (m--) {
			scanf("%d %d %d", &u, &v, &w);
			adj[u].pb(mp(v, w));
			adj[v].pb(mp(u, w));
		}
		scanf("%d", &ns);
		rep(i, ns) scanf("%d", &stores[i]);
		rep(i, ns) dijkstra(stores[i], i);
		stores[ns] = 0; dijkstra(0, ns);
		m = BIT(ns);
		rep(i, ns) {
			rep(j, m) f[i][j] = INF;
			f[i][BIT(i)] = d[ns][i];
		}
		rep(j, m - 1) rep(i, ns) if (f[i][j] != INF) {
			rep(k, ns) if (!(j & BIT(k)))
				f[k][j | BIT(k)] = min(f[k][j | BIT(k)], f[i][j] + d[i][k]);
		}
		int64 res = INF;
		rep(i, ns) res = min(res, f[i][m - 1] + d[i][ns]);
		printf("%lld\n", res);
	}
	return 0;
}