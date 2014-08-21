// 11848 - Cargo Trains
// Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=226&page=show_problem&problem=2948
#include <iostream>
using namespace std;

#define MAXN 110
#define INF 2000000000

int n,a[MAXN][MAXN],b[MAXN][MAXN];
double hsa,hsb;

void Init() {
    for (int i=0;i<=n;i++) {
        a[i][i] = b[i][i] = 0;
        for (int j=i+1;j<=n;j++)
            a[i][j]=a[j][i] = b[i][j]=b[j][i] = INF;
    }
}

double Dijkstra() {
    double d[n+2],min,temp;
    int u,v,i;
    bool Free[n+2];
    for (u=0;u<n;u++) {
        d[u] = INF;
        Free[u] = true;
    }
    d[0] = 0;
    while (1) {
        u = -1; min = INF;
        for (i=0;i<n;i++)
            if (Free[i] && d[i]<min) {
                min = d[i]; u = i;
            }
        if (u==-1 || u==n-1) break;
        Free[u] = false;
        for (v=0;v<n;v++) {
            if (a[u][v]==INF) temp = b[u][v];
            else if (b[u][v]==INF) temp = a[u][v];
            else temp = hsa*a[u][v]+hsb*b[u][v];
            
            if (Free[v] && d[v]>d[u]+temp) {
                d[v] = d[u]+temp;
            }
        }
    }
    return d[n-1];
}
/*
void Print() {
    int i,j;
    cout << "a" << endl;
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++)
            printf("%5d",a[i][j]);
        cout << endl;
    }
    cout << "b" << endl;
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++)
            printf("%5d",b[i][j]);
        cout << endl;
    }
}
*/
main() {
//    freopen("848.inp","r",stdin);
//    freopen("848.out","w",stdout);
    int kase,i,u,v,ma,mb,w;
    while (cin >> n >> ma >> mb >> kase) {
        if (n<0 && ma<0 && mb<0 && kase<0) break;
        Init();
        for (i=1;i<=ma;i++) {
            cin >> u >> v >> w;
            a[v][u] = a[u][v] = w;
        }
        for (i=1;i<=mb;i++) {
            cin >> u >> v >> w;
            b[v][u] = b[u][v] = w;
        }
 //       Print();
        while (kase--) {
            cin >> hsa;
            hsb=1.0-hsa;
            cout << (int)Dijkstra() << endl;
        }
    }
}
