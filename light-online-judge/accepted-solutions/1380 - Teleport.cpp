//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1380 - Teleport 
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
#define maxN 1011

int n, st, idx[maxN], mark[maxN];
ii pre[maxN];
vector<iii> edges;

int solve() {
    int res = 0;
    while (true) {
        rep(i, n) pre[i].ss = INF;
        rep(i, edges.size()) {
            int u = edges[i].ss.ff, v = edges[i].ss.ss, w = edges[i].ff;
            if (w < pre[v].ss && u != v) pre[v] = mp(u, w);
        }
        
        pre[st].ss = 0;
        rep(i, n) {
            idx[i] = mark[i] = -1;
            if (pre[i].ss == INF) return -1;
        }
        
        int number = 0;
        rep(i, n) {
            res += pre[i].ss;
            int u = i;
            while (u != st && idx[u] < 0 && mark[u] != i) {
                mark[u] = i;
                u = pre[u].ff;
            }
            if (u != st && idx[u] < 0) { // circle
                for (int v = pre[u].ff; v != u; v = pre[v].ff)
                    idx[v] = number;
                idx[u] = number++;
            }
        }
        
        if (number == 0) return res;
        rep(i, n) if (idx[i] < 0) idx[i] = number++;
        
        rep(i, edges.size()) {
            int u = edges[i].ss.ff, v = edges[i].ss.ss, w = edges[i].ff;
            edges[i].ss.ff = idx[u];
            edges[i].ss.ss = idx[v];
            if (idx[u] != idx[v]) {
                edges[i].ff -= pre[v].ss;
            }
        }
        n = number; st = idx[st];
    }
    return -1;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, m, u, v, w;
	for (scanf("%d", &cases); cases--; ) {
	    scanf("%d %d %d", &n, &m, &st);
	    edges.clear();
	    while (m--) {
	        scanf("%d %d %d", &u, &v, &w);
	        if (v == st) continue;
	        edges.pb(mp(w, mp(u, v)));
	    }
	    int res = solve();
	    printf("Case %d: ", ++caseNo);
	    if (res < 0) puts("impossible");
        else printf("%d\n", res);
	}
	return 0;
}
