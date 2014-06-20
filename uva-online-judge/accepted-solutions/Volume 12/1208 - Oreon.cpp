//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1208 - Oreon
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
#define maxN 30

int n, lab[maxN];
vector<iii> edges;

int getRoot(int v) { return (v == lab[v]) ? v : lab[v] = getRoot(lab[v]); }

void unionSet(int u, int v) { lab[getRoot(v)] = getRoot(u); }

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, u, v, val;
	for (scanf("%d", &cases); cases--; ) {
	    scanf(" %d ", &n);
	    edges.clear();
	    rep(i, n) {
	        rep(j, n - 1) {
	            scanf("%d,", &val);
	            if (val) edges.pb(mp(val, mp(i, j)));
	        }
	        scanf("%d", &val);
	        if (val) edges.pb(mp(val, mp(i, n - 1)));
	        lab[i] = i;
	    }
	    printf("Case %d:\n", ++caseNo);
	    sort(all(edges));
	    for (int i = 0, m = 0; i < edges.size() && m < n - 1; i++) {
	        u = getRoot(edges[i].ss.ff);
            v = getRoot(edges[i].ss.ss);
            if (u != v) {
                unionSet(u, v);
                printf("%c-%c %d\n", edges[i].ss.ff + 'A', edges[i].ss.ss + 'A', edges[i].ff);
            }
	    }
	}
	return 0;
}
