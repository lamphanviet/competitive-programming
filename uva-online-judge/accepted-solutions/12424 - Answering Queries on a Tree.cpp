//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 12424 - Answering Queries on a Tree
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

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100111

int ar[maxN];
char buff[maxN * 20];

int nextInt() {
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    int res = 0;
    do {
        res = res * 10 + c - 48;
        c = getchar();
    } while (isdigit(c));
    return res;
}

void println(int n) {
    int len = 0;
    do {
        buff[len++] = n % 10;
        n /= 10;
    } while (n);
    while (len) putchar(buff[--len] + '0');
    puts("");
}

void readLine() {
    gets(buff);
    int len = strlen(buff), i = 0, m = 0;
    while (i < len)
        if (isdigit(buff[i])) {
            ar[m] = 0;
            while (i < len && isdigit(buff[i]))
                ar[m] = ar[m] * 10 + buff[i++] - 48;
            m++;
        }
        else i++;
}

int counter[10];
struct Tree {
    int n;
    vector<vi> t;
    vi tmp;
    
    void clear() {
        n = 0;
        t.clear();
        tmp.clear();
    }
    
    void add(int clr) { tmp.pb(clr); }
    
    void build() {
        n = tmp.size();
        t.resize(n + 1);
        fr(i, 1, n) t[i] = vi(10, 0);
        rep(i, tmp.size()) update(i + 1, tmp[i], 1);
        tmp.clear();
    }
    
    int get(int i, int clr, bool x) {
        int res = 0;
        while (i > 0) {
            res += t[i][clr];
            i -= (-i & i);
        }
        return res;
    }
    
    void get(int lo, int hi) {
        rep(i, 10) counter[i] += (get(hi, i, true) - get(lo - 1, i, true));
    }
    
    void update(int i, int clr, int val) {
        while (i <= n) {
            t[i][clr] += val;
            i += (-i & i);
        }
    }
} tree[maxN];
int n, c[maxN], parent[maxN], depth[maxN], sz[maxN];
vi adj[maxN];
bool heavy[maxN];
int root[maxN], number[maxN];

void dfs(int u, int lvl, int pr) {
    sz[u] = 1;
    parent[u] = pr;
    depth[u] = lvl;
    rep(i, adj[u].size()) {
        int v = adj[u][i];
        if (v == parent[u]) continue;
        dfs(v, lvl + 1, u);
        sz[u] += sz[v];
    }
}

void dfs2(int u) {
    if (heavy[u]) {
        root[u] = root[parent[u]];
        number[u] = number[parent[u]] + 1;
        tree[root[u]].add(c[u]);
    }
    else {
        root[u] = u;
        number[u] = 0;
    }
    rep(i, adj[u].size()) {
        int v = adj[u][i];
        if (v == parent[u]) continue;
        if (sz[v] > sz[u] / 2) heavy[v] = true;
        dfs2(v);
    }
}

int solve(int u, int v) {
    fill(counter, 0);
    while (root[u] != root[v]) {
        if (depth[root[u]] < depth[root[v]]) swap(u, v);
        if (heavy[u]) {
            tree[root[u]].get(1, number[u]);
            u = root[u];
        }
        else {
            counter[c[u]]++;
            u = parent[u];
        }
    }
    
    if (depth[u] > depth[v]) swap(u, v);
    if (depth[u] != depth[v]) {
        tree[root[u]].get(number[u], number[v]);
        if (u == root[u]) counter[c[u]]++;
    }
    else counter[c[u]]++;
    
    int mx = 0;
    rep(i, 10) mx = max(mx, counter[i]);
    return mx;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int cases, m, u, v, q;
	for (scanf("%d ", &cases); cases--; ) {
        readLine();
        n = ar[0]; m = ar[1];
        readLine();
	    fr(i, 1, n) {
            c[i] = ar[i - 1] - 1;
	        adj[i].clear();
	        heavy[i] = false;
	        parent[i] = 0;
	        tree[i].clear();
	    }
	    
	    rep(i, n - 1) {
            readLine();
            u = ar[0]; v = ar[1];
	        adj[u].pb(v); adj[v].pb(u);
	    }
	    dfs(1, 0, 1);
	    dfs2(1);
	    
	    fr(i, 1, n) tree[i].build();
	    
	    while (m--) {
            readLine();
            q = ar[0]; u = ar[1]; v = ar[2];
	        if (q == 0) {
	            v--;
	            if (heavy[u]) {
                    tree[root[u]].update(number[u], c[u], -1);
                    tree[root[u]].update(number[u], v, 1);
	            }
	            c[u] = v;
	        }
	        else println(solve(u, v));
	    }
	}
	return 0;
}
