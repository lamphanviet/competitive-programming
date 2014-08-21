// UVA Problem 10600 - ACM Contest and Blackout
// Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1541
#include <iostream>

using namespace std;

#define MAXN 105
#define INF 100000

int a[MAXN][MAXN], n, m;
int Trace[3][MAXN];

void Enter() {
    int i,j,u,v,cost;
    cin >> n >> m;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            a[i][j] = a[j][i] = INF;
    for (i=1;i<=m;i++) {
        cin >> u >> v >> cost;
        a[u][v] = a[v][u] = cost;
    }
}

int Prim(int ace) {
    int u,v,k, d[n+2], min, sum;
    bool Free[n+2], Connected = true;
    
    for (v=1;v<=n;v++) {
        d[v]=INF; Free[v]=true;
    }
    d[1] = 0;
    
    for (k=1;k<=n;k++) {
        u = 0; min = INF;
        for (v=1;v<=n;v++)
            if (Free[v] && d[v]<min) {
                u = v; min = d[v];
            }
        if (u==0) {
            Connected = false; break;
        }
        Free[u] = false;
        for (v=1;v<=n;v++)
            if (Free[v] && d[v]>a[u][v]) {
                d[v] = a[u][v];
                Trace[ace][v] = u;
            }
    }
    
    if (!Connected) return -1;
    sum = 0;
    for (v=2;v<=n;v++)
        sum += a[v][Trace[ace][v]];
    return sum;
}

main() {
//    freopen("600.inp","r",stdin);
//    freopen("600.out","w",stdout);
    int kase, i, first, second, k;
    cin >> kase;
    while (kase--) {
        Enter();
        first = Prim(0);
        second = INF;
        for (i=2;i<=n;i++) {
            int temp = a[i][Trace[0][i]];
            a[i][Trace[0][i]] = a[Trace[0][i]][i] = INF;
            
            k = Prim(1);
            if (k>=0 && k<second) second = k;
            a[i][Trace[0][i]] = a[Trace[0][i]][i] = temp;
        }
        if (second == INF) second = first;
        printf("%d %d\n",first,second);
    }
}
