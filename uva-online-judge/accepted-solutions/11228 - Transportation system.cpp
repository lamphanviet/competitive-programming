// LAM PHAN VIET **
// UVA 11228 - Transportation system.
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
#define maxN 1001
using namespace std;

double a[maxN][maxN], road, rail, len;
int n, x[maxN], y[maxN], state;

double Distance(int i, int j) {
    double a = x[i]-x[j];
    double b = y[i]-y[j];
    return sqrt(a*a + b*b);
}

void Enter_Distance() {
    scanf("%d %lf", &n, &len);
    FOR (i, 1, n) {
        scanf("%d %d", &x[i], &y[i]);
        a[i][i] = 0.0;
        FOR (j, 1, i-1)
            a[i][j] = a[j][i] = Distance(i, j);
    }
}

void Prim() {
    double d[n+2];
    bool Free[n+2];
    int Trace[n+2];
    FOR (u, 1, n) {
        d[u]=INF; Free[u]=true;
    }
    d[1] = 0;
    
    while (1) {
        int u = 0;
        double Min = INF;
        FOR (i, 1, n)
            if (Free[i] && d[i]<Min) {
                u = i; Min = d[i];
            }
        if (u==0) break;
        Free[u] = false;
        FOR (v, 1, n)
            if (Free[v] && d[v] > a[u][v]) {
                d[v] = a[u][v];
                Trace[v] = u;
            }
    }
    state = 1; road = 0; rail = 0;
    FOR (u, 2, n) {
        double temp = a[u][Trace[u]];
        if (temp>len) {
            rail += temp; state++;
        }
        else road += temp;
    }
}

main() {
//    FileIn("test"); FileOut("test");
    int Case;
    scanf("%d", &Case);
    FOR (kk, 1, Case) {
        Enter_Distance();
        Prim();
        printf("Case #%d: %d %.0lf %.0lf\n", kk, state, road, rail);
    }
}
