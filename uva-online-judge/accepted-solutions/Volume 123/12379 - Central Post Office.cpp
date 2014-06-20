//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : UVa
// Problem Name : 12379 - Central Post Office
// Time Limit   : 3.000s
// Description  : dfs + tree - travel through all nodes of a tree > (n - 1) * 2 - maxLength
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
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 10010
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, maxLength;
vi adj[maxN];
bool visited[maxN];

int visit(int p, int u) {
    int max1 = 0, max2 = 0;
    REP(i, adj[u].size()) {
        int v = adj[u][i];
        if (v == p) continue;
        int tmp = visit(u, v) + 1;
        if (tmp > max1) {
            max2 = max1;
            max1 = tmp;
        }
        else if (tmp > max2)
            max2 = tmp;
    }
    maxLength = max(maxLength, max1 + max2);
    return max(max1, max2);
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); outFile("test.out");
    #endif
    int Case, m;
    for (scanf("%d", &Case); Case--; ) {
        scanf("%d", &n);
        FOR (i, 1, n) {
            scanf("%d", &m);
            adj[i].resize(m);
            REP(j, m) scanf("%d", &adj[i][j]);
            visited[i] = false;
        }
        maxLength = 0;
        visit(0, 1);
        printf("%d\n", (n - 1) * 2 - maxLength);
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
