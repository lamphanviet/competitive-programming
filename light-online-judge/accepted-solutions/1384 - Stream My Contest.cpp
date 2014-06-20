//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1384 - Stream My Contest 
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
#define maxN 66
#define maxM 10011

struct Edge {
    int u, v, b, c;
    Edge() {}
};
Edge e[maxM], edges[maxM];
int N, m, mark[maxN], idx[maxN];
ii pre[maxN];

int solve(int low) {
    int k = 0, res = 0, root = 0, n = N;
    rep(i, m) if (edges[i].b >= low) e[k++] = edges[i];
    if (k == 0) return (n == 1) ? 0 : INF;
    while (true) {
        rep(i, n) {
            pre[i] = mp(INF, INF);
            idx[i] = mark[i] = -1;
        }
        rep(i, k) {
            int u = e[i].u, v = e[i].v, c = e[i].c;
            if (c < pre[v].ss && u != v) pre[v] = mp(u, c);
        }

        pre[root].ss = 0;
        rep(i, n) if (pre[i].ss == INF) return INF;
        
        int number = 0;
        rep(i, n) {
            res += pre[i].ss;
            int u = i;
            while (u != root && idx[u] < 0 && mark[u] != i) {
                mark[u] = i;
                u = pre[u].ff;
            }
            if (u != root && idx[u] < 0) {
                for (int v = pre[u].ff; v != u; v = pre[v].ff)
                    idx[v] = number;
                idx[u] = number++;
            }
        }
        
        if (number == 0) return res;

        rep(i, n) if (idx[i] < 0) idx[i] = number++;
        
        rep(i, k) {
            int u = e[i].u, v = e[i].v;
            e[i].u = idx[u];
            e[i].v = idx[v];
            if (idx[u] != idx[v]) e[i].c -= pre[v].ss;
        }
        n = number; root = idx[root];
    }
    return INF;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, maxCost;
	for (scanf("%d", &cases); cases--; ) {
	    scanf("%d %d %d", &N, &m, &maxCost);
	    vi val;
	    rep(i, m) {
	        scanf("%d %d %d %d", &edges[i].u, &edges[i].v, &edges[i].b, &edges[i].c);
	        val.pb(edges[i].b);
	    }
	    sort(all(val));
	    int lo = 0, hi = val.size() - 1, res = -1;
	    while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (solve(val[mid]) <= maxCost) {
                lo = mid + 1;
                res = val[mid];
            }
            else hi = mid - 1;
	    }
	    printf("Case %d: ", ++caseNo);
	    if (res < 0) puts("impossible");
	    else printf("%d kbps\n", res);
	}
	return 0;
}
