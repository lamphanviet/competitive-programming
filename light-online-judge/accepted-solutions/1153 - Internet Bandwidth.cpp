//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1153 - Internet Bandwidth
// Time Limit   : 2.000s
// Description  : max flow
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
#define maxN 111
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, s, t;
int c[maxN][maxN], f[maxN][maxN];
int trace[maxN];

bool findPath() {
    FOR (i, 1, n) trace[i] = 0;
    queue<int> q;
    q.push(s);
    trace[s] = n + 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        FOR (v, 1, n)
            if (!trace[v] && c[u][v] > f[u][v]) {
                trace[v] = u;
                if (v == t) return true;
                q.push(v);
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

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    int caseNo, cases = 0, m, u, v, w;
    scanf("%d", &caseNo);
    while (caseNo--) {
        scanf("%d", &n);
        FOR (i, 1, n) FOR (j, 1, n)
            c[i][j] = 0, f[i][j] = 0;
        scanf("%d %d %d", &s, &t, &m);
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            c[u][v] += w;
            c[v][u] += w;
        }
        while (findPath()) incFlow();
        int res = 0;
        FOR (i, 1, n)
            if (f[s][i] > 0)
                res += f[s][i];
        printf("Case %d: %d\n", ++cases, res);
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
