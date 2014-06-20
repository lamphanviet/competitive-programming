//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1141 - Number Transformation
// Time Limit   : 2.000s
// Description  : bfs - easy
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
#define maxN 1010
#define sq(x) ((x) * (x))
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int d[110][maxN];
vi adj[maxN];

void bfs(int s) {
    FOR (i, 1, 1000) d[s][i] = -1;
    d[s][s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        REP(i, adj[u].size()) {
            int v = u + adj[u][i];
            if (v > 1000 || d[s][v] != -1) continue;
            d[s][v] = d[s][u] + 1;
            q.push(v);
        }
    }
}

void preCal() {
    FOR (i, 1, 1000) {
        int m = i;
        for (int j = 2; j * j <= m; j++)
            if (m % j == 0) {
                adj[i].pb(j);
                while (m % j == 0) m /= j;
            }
        if (m != 1 && m != i) adj[i].pb(m);
    }
    FOR (i, 1, 100) bfs(i);
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    preCal();
    int caseNo, cases = 0, s, t;
    scanf("%d", &caseNo);
    while (caseNo--) {
        scanf("%d %d", &s, &t);
        printf("Case %d: %d\n", ++cases, d[s][t]);
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
