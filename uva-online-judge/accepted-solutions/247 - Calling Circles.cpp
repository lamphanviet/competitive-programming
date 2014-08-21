//*****************
// LAM PHAN VIET **
// UVA 247 - Calling Circles
// Time limit: 3.000s
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
#define Last(i) (i & -i)
#define INF 500000000
#define maxN 30
using namespace std;

int n;
bool Free[maxN];
string name[maxN];
vector<int> adj[maxN], radj[maxN];
map<string, int> Index;
vector<int> node;

void Visit(int u) {
    Free[u] = false;
    REP (i, adj[u].size())
        if (Free[adj[u][i]]) Visit(adj[u][i]);
    node.pb(u);
}

void rVisit(int u, bool p) {
    Free[u] = true;
    if (p) printf(", ");
    cout << name[u];
    REP (i, radj[u].size())
        if (!Free[radj[u][i]]) rVisit(radj[u][i], true);
}

int GetIndex(char s[], int &Count) {
    int idx = Index[s];
    if (idx==0) {
        idx = Index[s] = ++Count;
        name[idx] = s;
    }
    return idx;
}

main() {
//    FileIn("test"); FileOut("test");
    int Case = 0, m, u, v;
    char s1[maxN], s2[maxN];
    while (scanf(" %d %d", &n, &m) && (n || m)) {
        Index.clear();
        FOR (i, 1, n)
            adj[i].clear(), radj[i].clear();
        int Count = 0;
        while (m--) {
            scanf(" %s %s", &s1, &s2);
            u = GetIndex(s1, Count); v = GetIndex(s2, Count);
            adj[u].pb(v);
            radj[v].pb(u);
        }
        Fill(Free, true);
        node.clear();
        FOR (i, 1, n)
            if (Free[i]) Visit(i);
        if (Case) printf("\n");
        printf("Calling circles for data set %d:\n", ++Case);
        for (int i=n-1; i>=0; i--)
            if (!Free[node[i]]) {
                rVisit(node[i], false);
                printf("\n");
            }
    }
}

/* lamphanviet@gmail.com - 2011 */
