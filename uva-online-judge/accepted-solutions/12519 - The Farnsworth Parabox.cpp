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
#define maxN 211

vector <ii> adj[maxN];
int mark[maxN], n, m;
bool found;
void dfs(int start, int u, int s) {
    if (found) return;
    if (mark[u]) return;
    mark[u] = 1;
    for (int i = 0;i < adj[u].size();i++) {
        int v = adj[u][i].ff;
        int w = adj[u][i].ss;
        if ((v == start && s + w != 0)) {
            found = true;
            return;
        }
        else dfs(start, v, s + w);
    }
}
bool solve() {
    found = false;
    for (int i = 1;i <= n;i++) {
        fill(mark, 0);
        dfs(i, i, 0);
        if (found) break;
    }
    return found;
}
int main() {
	/*#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	#endif*/
	int u, v, w;
	while ( scanf("%d %d", &n, &m) && (m + n)) {
	    for (int i = 1;i <= n;i++) adj[i].clear();
	    for (int i = 1;i <= m;i++) {
	        scanf("%d %d %d", &u, &v, &w);
	        adj[u].pb(ii(v, w));
	        adj[v].pb(ii(u, -w));
	    }
	    if ( solve() ) puts("Y");
	    else puts("N");
	}
	return 0;
}
