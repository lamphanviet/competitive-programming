//*****************
// LAM PHAN VIET **
// UVA 753 - A Plug for UNIX
// Time limit: 3.000s
//********************************
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
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
#define INF 50000000
#define maxN 505
using namespace std;

const int s = 1, t = 2;
int n, m, Trace[maxN];
int f[maxN][maxN], c[maxN][maxN];
map<string, int> IndexPlug;

void ReadInput() {
    IndexPlug.clear();
    REP (i, maxN)
        REP (j, maxN)
            c[i][j] = f[i][j] = 0;
            
    char s1[30], s2[30];
    int k, u, v, idx = 2;
    
    scanf("%d", &k);
    while (k--) {
        scanf(" %s", &s1);
        u = IndexPlug[s1];
        if (u==0) u = IndexPlug[s1] = ++idx;
        c[u][t]++;
    }
    
    scanf("%d", &m);
    n = idx; idx += m;
    FOR (i, 1, m) {
        scanf(" %s %s", &s1, &s2);
        u = n + i;
        v = IndexPlug[s2];
        if (v==0) v = IndexPlug[s2] = ++idx;
        c[s][u]++;
        c[u][v]++;
    }
    
    scanf("%d", &k);
    while (k--) {
        scanf(" %s %s", &s1, &s2);
        u = IndexPlug[s1];
        if (u==0) u = IndexPlug[s1] = ++idx;
        v = IndexPlug[s2];
        if (v==0) v = IndexPlug[s2] = ++idx;
        c[u][v] = INF;
    }
    n = idx;
}

bool FindPath() {
    queue<int> Q;
    FOR (i, 1, n) Trace[i] = 0;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        FOR (v, 1, n) {
            if (Trace[v]==0 && c[u][v] > f[u][v]) {
                Trace[v] = u;
                if (v==t) return true;
                Q.push(v);
            }
        }
    }
    return false;
}

void IncFlow() {
    int Delta = 50000000, u, v;
    v = t;
    do {
        u = Trace[v];
        Delta = min(Delta, c[u][v] - f[u][v]);
        v = u;
    } while (v!=s);
    
    v = t;
    do {
        u = Trace[v];
        f[u][v] += Delta;
        f[v][u] -= Delta;
        v = u;
    } while (v!=s);
}

void Solve() {
    while (FindPath()) IncFlow();
    
    int Res = 0;
    FOR (j, 1, n)
        if (f[s][j]>0) Res += f[s][j];
        
    printf("%d\n", m - Res);
}

main() {
//    FileIn("test"); FileOut("test");
    int Case;
    for (scanf("%d", &Case); Case--; ) {
        ReadInput();
        Solve();
        if (Case) printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
