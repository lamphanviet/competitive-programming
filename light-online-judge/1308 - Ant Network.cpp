//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1308 - Ant Network 
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
#define maxN 10011

int rootChild, number, low[maxN], num[maxN], n, size, idx[maxN], counter;
bool mark[maxN], vis[maxN];
vi adj[maxN];

void dfs(int u, int parent) {
    num[u] = low[u] = ++number;
    rep(i, adj[u].size()) {
        int v = adj[u][i];
        if (v == parent) continue;
        if (num[v]) low[u] = min(low[u], num[v]);
        else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (num[u] <= low[v]) mark[u] = true;
            if (u == 0) rootChild++;
        }
    }
}

void visit(int u, int key) {
    size++;
    vis[u] = true;
    rep(i, adj[u].size()) {
        int v = adj[u][i];
        if (mark[v]) {
            if (idx[v] != key) counter++;
            idx[v] = key;
            continue;
        }
        if (!vis[v]) visit(v, key);
    }
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, m, u, v;
	for (scanf("%d", &cases); cases--; ) {
	    scanf("%d %d", &n, &m);
	    rep(i, n) {
	        adj[i].clear();
	        mark[i] = vis[i] = false;
	        num[i] = 0;
	        idx[i] = -1;
	    }
	    while (m--) {
	        scanf("%d %d", &u, &v);
	        adj[u].pb(v); adj[v].pb(u);
	    }
	    number = 0;
	    rep(i, n) if (!num[i]) {
            rootChild = 0;
	        dfs(i, i);
            mark[i] = rootChild > 1;
	    }
	    bool one = true;
	    uint64 cnt = 0, ways = 1;
	    //rep(i, n) if (mark[i]) printf("%d ", i); puts("");
	    rep(i, n) if (!vis[i] && !mark[i]) {
	        size = counter = 0;
	        visit(i, i);
	        if (counter == 1) {
                cnt++;
                ways *= (uint64)size;
	        }
	        if (size > 1) one = false;
	    }
	    if (one) {
	        cnt = 2; ways = (n * (n - 1)) / 2;
	    }
	    printf("Case %d: ", ++caseNo); cout << cnt << " " << ways << endl;
	}
	return 0;
}
