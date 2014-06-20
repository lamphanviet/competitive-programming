// UVA Problem 10147 - Highways
// Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1088
#include <iostream>
#include <math.h>

using namespace std;

#define INF 1000000000
#define MAXN 755

int n, x[MAXN], y[MAXN], Trace[MAXN];
double a[MAXN][MAXN];

void Distance() {
    for (int i=1;i<=n;i++) {
        a[i][i] = 0;
        for (int j=i+1;j<=n;j++)
            a[i][j] = a[j][i] = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    }
}

void Enter() {
    int k,u,v,m;
    cin >> n;
    for (k=1;k<=n;k++) {
        cin >> x[k] >> y[k];
    }
    Distance();
    cin >> m;
    for (k=1;k<=m;k++) {
        cin >> u >> v;
        a[u][v] = a[v][u] = -1.0;
    }
}

void Prim() {
    bool Free[n+2];
    double d[n+2], min;
    int k, u, v;
    for (k=1;k<=n;k++) {
        Free[k] = true; d[k] = INF;
    }
    d[1] = 0;
    for (k=1;k<=n;k++) {
        u = 0; min = INF;
        for (v=1;v<=n;v++)
            if (Free[v] && d[v]<min) {
                u = v; min = d[v];
            }
        Free[u] = false;
        for (v=1;v<=n;v++)
            if (Free[v] && d[v]>a[u][v]) {
                d[v] = a[u][v];
                Trace[v] = u;
            }
    }
}

void Result() {
    bool non = true;
    for (int u=2;u<=n;u++)
        if (a[u][Trace[u]]>=0) {
            cout << u << " " << Trace[u] << endl;
            non = false;
        }
    if (non) cout << "No new highways need" << endl;
}

main() {
//    freopen("147.inp","r",stdin);
//    freopen("147.out","w",stdout);
    int kase;
    cin >> kase;
    while (kase--) {
        Enter();
        Prim();
        Result();
        if (kase) cout << endl;
    }
}
