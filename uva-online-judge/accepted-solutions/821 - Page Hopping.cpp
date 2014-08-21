// 821 - Page Hopping
#include <iostream>

using namespace std;

#define INF 999

main() {
    int kase, u, v, i, j, k;
    int sum, n, a[105][105], cs[105];
    while (cin >> u >> v && (u || v)) {
        for (i=1;i<=100;i++) {
            cs[i] = 0;
            a[i][i] = 0;
            for (j=i+1;j<=100;j++)
                a[i][j] = a[j][i] = INF;
        }
        n = 0;
        do {
            if (!cs[u]) cs[u] = ++n;
            if (!cs[v]) cs[v] = ++n;
            a[cs[u]][cs[v]] = 1;
            cin >> u >> v;
        } while (u || v);
 /*       for (u=1;u<=n;u++) {
            for (v=1;v<=n;v++) {
                printf("%4d",a[u][v]);
            }
            cout << endl;
        }   */
        
        // Floyd
        for (k=1;k<=n;k++)
            for (u=1;u<=n;u++)
                for (v=1;v<=n;v++) {
                    a[u][v] = min(a[u][v], a[u][k] + a[k][v]);
  //                  a[v][u] = min(a[v][u], a[v][k] + a[k][u]);
                }
        sum = 0;
        for (u=1;u<=n;u++) {
            for (v=1;v<=n;v++) {
                sum += a[u][v];
  //              printf("%4d",a[u][v]);
            }
  //          cout << endl;
        }
        printf("Case %d: average length between pages = %.3lf clicks\n",++kase, (double)sum/(n*(n-1)));
    }
}
