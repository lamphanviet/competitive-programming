//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : UVa
// Problem Name : 820 - Internet Bandwidth
// Time Limit   : 3.000s
// Description  : Maximum flow
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
#define maxN 102
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

using namespace std;

int n, s, t;
int c[maxN][maxN], f[maxN][maxN], trace[maxN];

bool findPath() {
    FOR (i, 1, n) trace[i] = 0;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        FOR (v, 1, n)
            if (!trace[v] && c[u][v] > f[u][v]) {
                trace[v] = u;
                if (v == t) return true;
                Q.push(v);
            }
    }
    return false;
}

void incFlow() {
    int u, v, delta = INF;
    v = t;
    do {
        u = trace[v];
        delta = min(delta, c[u][v] - f[u][v]);
        v = u;
    } while (v != s);
    
    v = t;
    do {
        u = trace[v];
        f[u][v] += delta;
        f[v][u] -= delta;
        v = u;
    } while (v != s);
}

int solve() {
    while (findPath()) incFlow();
    int res = 0;
    FOR (i, 1, n)
        if (f[s][i] > 0) res += f[s][i];
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); outFile("test.out");
    #endif
    int Case = 0, u, v, w, m;
    while (scanf("%d", &n) && n) {
        scanf("%d %d %d", &s, &t, &m);
        FOR (i, 1, n)
            FOR (j, i, n)
                f[i][j] = f[j][i] = c[i][j] = c[j][i] = 0;
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            c[u][v] += w; c[v][u] = c[u][v];
        }
        printf("Network %d\n", ++Case);
        printf("The bandwidth is %d.\n\n", solve());
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
