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
#define maxN 10111

int n, number[maxN], low[maxN], counter, res, rootChild;
vi adj[maxN];
bool ok[maxN];

void visit(int u, int parent) {
    number[u] = low[u] = ++counter;
    rep(i, adj[u].size()) {
        int v = adj[u][i];
        if (!number[v]) {
            if (u == 1) rootChild++;
            visit(v, u);
            
            if (low[v] >= number[u]) ok[u] = true;
            low[u] = min(low[u], low[v]);
        }
        else {
            low[u] = min(low[u], number[v]);
        }
    }
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, m, u, v;
	for (scanf("%d", &cases); cases--; ) {
	    scanf(" %d %d ", &n, &m);
	    fr(i, 1, n) {
	        adj[i].clear();
	        number[i] = 0;
	        ok[i] = false;
	    }
	    while (m--) {
	        scanf("%d %d", &u, &v);
	        adj[u].pb(v); adj[v].pb(u);
	    }
	    res = counter = rootChild = 0;
	    visit(1, 1);
	    ok[1] = (rootChild > 1);
	    fr(i, 1, n) res += ok[i];
	    printf("Case %d: %d\n", ++caseNo, res);
	}
	return 0;
}
