//*****************
// LAM PHAN VIET **
// UVA 11267 - The Hire-a-Coder Business Model
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
#define maxN 202
using namespace std;

int n, c[maxN][maxN];
int d[maxN], b[maxN];
bool Free[maxN], valid;

int Solve_Prim() {
    if (!valid) return INF;
    d[1] = 0;
    while (1) {
        int u = 0, Min = INF;
        FOR (i, 1, n)
            if (Free[i] && d[i] < Min) {
                u = i; Min = d[i];
            }
        if (u==0 || d[u]==INF) break;
        Free[u] = false;
        FOR (v, 1, n) {
            if (Free[v] && d[v] > c[u][v]) {
                d[v] = c[u][v];
            }
        }
    }
    int Cost = 0;
    FOR (i, 1, n) {
        if (d[i] < INF) {
            if (d[i]>0) Cost += d[i];
        }
        else return INF;
        FOR (j, i+1, n)
            if (c[i][j]<0) Cost += c[i][j];
    }
    return Cost;
}

main() {
//    FileIn("test"); FileOut("test");
    int m, u, v, w;
    while (scanf("%d", &n) && n) {
        scanf("%d", &m);
        FOR (i, 1, n) {
            FOR (j, 1, n) c[i][j] = INF;
            d[i] = INF;
            b[i] = 0;
            Free[i] = true;
        }
        valid = true;
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            if (b[u]==2 || b[v]==1) valid = false;
            if (!valid) continue;
            b[u] = 1; b[v] = 2;
            c[u][v] = c[v][u] = min(c[u][v], w);
        }
        int ans = Solve_Prim();
        if (ans==INF) puts("Invalid data, Idiot!");
        else printf("%d\n", ans);
    }
}

/* lamphanviet@gmail.com - 2011 */
