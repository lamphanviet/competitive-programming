//*****************
// LAM PHAN VIET **
// UVA 10113 - Exchange Rates
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
#define maxN 70
using namespace std;

struct Connection {
    int v, x, y;
};

int gcd(int n, int m) {
    return (n % m) ? gcd(m, n%m) : m;
}

int n, res_u, res_v;
vector< vector<Connection> > adj;
map<string, int> Index;
bool flag[maxN];

void dfs(int u, int t, int x, int y) {
    if (u == t) {
        res_u = x; res_v = y;
        flag[t] = false;
    }
    if (!flag[t]) return;
    
    flag[u] = false;
    REP(i, adj[u].size()) {
        int v = adj[u][i].v, xx = adj[u][i].x, yy = adj[u][i].y;
        if (!flag[v]) continue;
        xx *= x; yy *= y;
        int gcd_xy = gcd(xx, yy);
        xx /= gcd_xy; yy /= gcd_xy;
        dfs(v, t, xx, yy);
    }
}

int get_index(string s) {
    int u = Index[s];
    if (!u) {
        u = Index[s] = ++n;
        adj.pb(vector<Connection>());
    }
    return u;
}

main() {
//    FileIn("test"); FileOut("test");
    Connection c;
    char s1[maxN], s2[maxN], q;
    int u, v;
    
    n = 0;
    adj.pb(vector<Connection>());
    while (scanf(" %c ", &q)!=EOF) {
        if (q == '.') break;
        if (q == '!') {
            scanf(" %d %s %c %d %s ", &c.x, &s1, &q, &c.y, &s2);
            u = get_index(s1);
            v = c.v = get_index(s2);
            adj[u].pb(c);
            
            c.v = u;
            swap(c.x, c.y);
            adj[v].pb(c);
        }
        else {
            scanf(" %s %c %s ", &s1, &q, &s2);
            u = get_index(s1);
            v = get_index(s2);
            res_u = res_v = -1;
            memset(flag, true, n + 1);
            dfs(u, v, 1, 1);
            if (flag[v])
                printf("? %s = ? %s\n", s1, s2);
            else
                printf("%d %s = %d %s\n", res_u, s1, res_v, s2);
        }
    }
}

/* lamphanviet@gmail.com - 2011 */
