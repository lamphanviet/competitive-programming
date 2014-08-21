//*****************
// LAM PHAN VIET **
// UVA 10687 - Monitoring the Amazon
// Time limit: 3.000
//********************************
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define INF 500000000
#define maxN 1001
using namespace std;

int n, x[maxN], y[maxN];
int d[maxN][maxN];
bool flag[maxN];
vector<int> adj[maxN];

int Distance(int i, int j) {
    int a = x[i] - x[j], b = y[i] - y[j];
    return (a * a + b * b);
}

bool cmp(int i, int j) {
    return (x[i] < x[j] || (x[i] == x[j] && y[i] < y[j]));
}

void build_graph() {
    if (n == 1) return;
    FOR (i, 1, n) {
        adj[i].clear();
        int min_distance = INF, u, v;
        FOR (j, 1, n)
            if (d[i][j] < min_distance)
                min_distance = d[i][j], u = j;
        FOR (j, u + 1, n)
            if (d[i][j] == min_distance && cmp(j, u))
                u = j;
        adj[i].pb(u);
        
        if (n < 3) continue;
        min_distance = INF;
        FOR (j, 1, n)
            if (j != u && d[i][j] < min_distance)
                min_distance = d[i][j], v = j;
        FOR (j, v + 1, n)
            if (j != u && d[i][j] == min_distance && cmp(j, v))
                v = j;
        adj[i].pb(v);
    }
}

void dfs(int u) {
    flag[u] = false;
    REP(i, adj[u].size())
        if (flag[adj[u][i]]) dfs(adj[u][i]);
}

bool solve() {
    dfs(1);
    FOR (i, 1, n)
        if (flag[i]) return false;
    return true;
}

main() {
//    FileIn("test"); FileOut("test");
    while (scanf("%d", &n) && n) {
        FOR (i, 1, n) {
            scanf("%d %d", &x[i], &y[i]);
            FOR (j, 1, i-1)
                d[i][j] = d[j][i] = Distance(i, j);
            d[i][i] = INF;
            flag[i] = true;
        }
        build_graph();
        if (solve()) puts("All stations are reachable.");
        else puts("There are stations that are unreachable.");
    }
}

/* lamphanviet@gmail.com - 2011 */
