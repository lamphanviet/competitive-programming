//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1235 - Anti Brute Force Lock - UVa
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
#define maxN 505

int n, d[maxN][maxN], dist[maxN];
string s[maxN];
bool mark[maxN];

int cal(const string &a, const string &b) {
    int res = 0;
    rep(i, 4) {
        int x = a[i] - '0', y = b[i] - '0';
        res += min(abs(x - y), 10 - abs(x - y));
    }
    return res;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int cases;
	for (scanf("%d", &cases); cases--; ) {
	    scanf(" %d ", &n);
	    s[0] = "0000"; d[0][0] = 0;
	    fr(i, 1, n) {
	        cin >> s[i];
	        rep(j, i) d[i][j] = d[j][i] = cal(s[i], s[j]);
	        d[i][i] = 0;
	        dist[i] = INF;
	    }
	    fill(mark, false);
	    int res = 0;
	    set<ii> heap;
	    int x = 1;
	    fr(i, 1, n) if (d[0][i] < d[0][x]) x = i;
	    dist[x] = d[0][x]; heap.insert(mp(dist[x], x));
	    while (!heap.empty()) {
	        ii top = *heap.begin(); heap.erase(top);
	        int u = top.ss;
	        mark[u] = true;
	        res += dist[u];
	        fr(v, 1, n) if (!mark[v] && dist[v] > d[u][v]) {
	            heap.erase(mp(dist[v], v));
	            dist[v] = d[u][v];
	            heap.insert(mp(dist[v], v));
	        }
	    }
	    printf("%d\n", res);
	}
	return 0;
}
