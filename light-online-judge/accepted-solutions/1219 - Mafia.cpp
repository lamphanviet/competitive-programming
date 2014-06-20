//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1219 - Mafia
// Time Limit   : 2.000s
// Description  : graph - tree
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
#define maxN 10010
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

struct NodeValue {
    int cost, child, mafia;
} node[maxN];
int n;
set<int> adj[maxN];

void dfs(int u, int p) {
    node[u].cost = 0;
    node[u].child = 0;
    foreach(it, adj[u]) {
        int v = *it;
        if (v == p) continue;
        dfs(v, u);
        node[u].mafia += node[v].mafia;
        node[u].child += node[v].child;
        node[u].cost += node[v].cost + node[v].mafia;
    }
    node[u].cost += node[u].child;
    int use = min(node[u].mafia, node[u].child);
    node[u].mafia -= use;
    node[u].child -= use;
    if (node[u].mafia) node[u].mafia--;
    else node[u].child++;
  //  printf("%d: %d %d %d\n", u, node[u].child, node[u].mafia, node[u].cost);
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    int caseNo, cases = 0, id, m;
    scanf("%d", &caseNo);
    while (caseNo--) {
        scanf("%d", &n);
        FOR (i, 1, n) adj[i].clear();
        FOR (i, 1, n) {
            scanf("%d", &id);
            scanf("%d %d", &node[id].mafia, &m);
            int val;
            REP(j, m) {
                scanf("%d", &val);
                adj[id].insert(val);
                adj[val].insert(id);
            }
        }
        dfs(1, 0);
        printf("Case %d: %d\n", ++cases, node[1].cost);
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
