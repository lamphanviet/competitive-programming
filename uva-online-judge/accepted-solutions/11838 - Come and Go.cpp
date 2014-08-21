// UVA Problem 11838 - Come and Go
// Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=226&page=show_problem&problem=2938
#include <iostream>

using namespace std;
int n,m;
bool a[2020][2020];

void Print() {
    int i,j;
    for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++)
            printf("%3d",a[i][j]);
        cout << endl;
    }
}

main() {
//    freopen("i.inp","r",stdin);
//    freopen("i.out","w",stdout);
    while (cin >> n >> m) {
        int i,j,u,v,p,k;
        if (n==0 && m==0) break;
        for (i=1;i<=n;i++) {
            memset(a[i],false,n+4);
            a[i][i]=1;
        }
        while (m--) {
            cin >> u >> v >> p;
            a[u][v]=1;
            if (p==2) a[v][u]=1;
        }
   //     Print();
        for (k=1;k<=n;k++)
            for (u=1;u<=n;u++)
                for (v=1;v<=n;v++)
          //          if (a[k][v] && a[v][u]) a[k][u]=1;
                    if (a[u][k] && a[k][v]) a[u][v]=1;
        
        int f=1;
        for (i=1;i<=n;i++) {
            for (j=1;j<=n;j++)
                if (!a[i][j]) {
                    f=0;
                    break;
                }
            if (!f) break;
        }
    //    Print();
        if (f) cout << "1";
        else cout << "0";
        cout << endl;
    }
}
