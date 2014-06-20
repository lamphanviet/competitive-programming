//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1003 - Drunk 
// Time Limit   : 2.000s
// Description  : dfs - topo - find circle
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
#define inpFile(f) freopen(f, "r", stdin)
#define outFile(f) freopen(f, "w", stdout)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define ff first
#define ss second
#define bit(n) (1<<(n))
#define Last(i) ( (i) & (-i) )
#define sq(x) ((x) * (x))
#define INF 500000000
#define maxN 20010
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, number[maxN], low[maxN], no;
vi adj[maxN];
map<string, int> idx;
bool circle;
stack<int> s;

int getIdx(string a) {
    int id = idx[a];
    if (!id) {
        id = idx[a] = ++n;
        adj[id].clear();
        number[id] = 0;
    }
    return id;
}

void visit(int u) {
    if (circle) return;
    number[u] = low[u] = ++no;
    s.push(u);
    REP(i, adj[u].size()) {
        int v = adj[u][i];
        if (number[v] != -1) {
            if (number[v] == 0) {
                visit(v);
                low[u] = min(low[u], low[v]);
            }
            else
                low[u] = min(low[u], number[v]);
        }
    }
    if (number[u] == low[u]) {
        int counter = 0, v;
        do {
            counter++;
            v = s.top(); s.pop();
            number[v] = -1;
        } while (v != u);
        if (counter > 1)
            circle = true;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    char a[11], b[11];
    int caseNo, cases = 0, u, v, m;
    scanf("%d", &caseNo);
    while (caseNo--) {
        idx.clear();
        n = 0;
        scanf("%d ", &m);
        while (m--) {
            scanf(" %s %s ", &a, &b);
            u = getIdx(a);
            v = getIdx(b);
            adj[u].pb(v);
        }
        no = 0;
        circle = false;
        s = stack<int>();
        for (int i = 1; i <= n && !circle; i++)
            if (number[i] == 0)
                visit(i);
        printf("Case %d: ", ++cases);
        if (circle) puts("No");
        else puts("Yes");
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
