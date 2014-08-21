//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 12176 - Bring Your Own Horse
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
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for (int i = (n) - 1; i >= 0; i--)
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
#define maxN 111
#define M 100010
#define N 3010
#define MAX_LOG 15
struct node {
    int x, y, w;
    node(){}
    node(int xx, int yy, int ww){
        x = xx; y = yy; w = ww;
    }
};
vector <ii> adj[N];
node edge[M];
int P[N][MAX_LOG];
int L[N][MAX_LOG], depth[N];
int lab[N];
int n, m, k;
bool cmp(node a, node b) {
    return (a.w < b.w);
}
int get(int v) {
    if (lab[v] < 0) return v;
    else return lab[v] = get( lab[v] );
}
void Union(int r1, int r2){
    int x = lab[r1] + lab[r2];
    if (lab[r1] > lab[r2]) {
        lab[r2] = x;
        lab[r1] = r2;
    }
    else {
        lab[r1] = x;
        lab[r2] = r1;
    }
}
void dfs(int u, int par, int level, int cost) {
    P[u][0] = par;
    depth[u] = level;
    L[u][0] = cost;
    for (int i=0;i<adj[u].size();i++) {
        int v = adj[u][i].ff;
        int w = adj[u][i].ss;
        if ( v != par ) dfs(v, u, level + 1, w);
    }
}
void buildLCA() {
    dfs(0, -1, 0, 0);
    for (k=0;(1<<(k + 1))<=n;k++);
    for (int j=1;j<=k;j++)
        for (int i=0;i<n;i++)
            if ( P[i][j - 1] == -1) {
                P[i][j] = P[i][j - 1];
                L[i][j] = L[i][j - 1];
            }
            else {
                P[i][j] = P[P[i][j - 1]][j - 1];
                L[i][j] = max(L[P[i][j - 1]][j - 1], L[i][j - 1]);
            }
}
int getLCA(int u, int v) {
    int ans = 0;
    if (depth[u] < depth[v]) swap(u, v);
        for (int i=k; i >= 0; i--)
            if ( P[u][i] != -1 && depth[u] - (1<<i) >= depth[v]) {
                ans = max(ans, L[u][i]);
                u = P[u][i];
            }
    if (u == v) return ans;
    for (int j=k; j >= 0; j--) {
        if (P[u][j]!=-1 && P[v][j] != -1 && P[u][j] != P[v][j]) {
            ans = max(ans, max(L[u][j], L[v][j]));
            u = P[u][j];
            v = P[v][j];
        }
    }
    ans = max(ans, L[u][0]);
    ans = max(ans, L[v][0]);
    return ans;
}
void kruskal() {
    int cnt = 0, u, v;
    for (int i=1;i<=n;i++) lab[i] = -1;
    for (int i=0;i<m;i++) {
        u = get( edge[i].x ); v = get( edge[i].y );
        if (u != v) {
            cnt++;
            Union(u, v);
            adj[edge[i].x - 1].pb(ii(edge[i].y - 1, edge[i].w));
            adj[edge[i].y - 1].pb(ii(edge[i].x - 1, edge[i].w));
            if (cnt == n - 1) break;
        }
    }
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif
	int cases, caseno = 0;
	int u, v, w, q;
	scanf("%d",&cases);
	while (cases--) {
        scanf("%d %d",&n,&m);
        for (int i=0;i<=n;i++) adj[i].clear();
        for (int i=0;i<m;i++) {
            scanf("%d %d %d",&u,&v,&w);
            edge[i] = node(u, v, w);
        }
        sort(edge, edge + m, cmp);
        kruskal();
        printf("Case %d\n",++caseno);
        scanf("%d",&q);
        buildLCA();
        while (q--) {
            scanf("%d %d",&u, &v);
            u--; v--;
            printf("%d\n", getLCA(u, v));
        }
        puts("");
    }
	return 0;
}

// Copyright (C) 2012, LamPhanViet
