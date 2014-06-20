// 11015 - 05-2 Rendezvous
#include <iostream>

using namespace std;

#define INF 100000
#define N 22

main() {
    int n, m, a[N+5][N+5], minsum;
    int k, u, v, i, j, sum, kase=0;
    char name[N+5][10+5];
    
    while (cin >> n >> m) {
        if (!n && !m) break;
        cin.get();
        for (i=1; i<=n; i++) {
            a[i][i] = 0;
            gets(name[i]);
            for (j=i+1; j<=n; j++)
                a[i][j] = a[j][i] = INF;
        }
        for (i=0; i<m; i++) {
            cin >> u >> v >> k;
            a[u][v] = a[v][u] = k;
        }
        
//        for (i=1; i<=n; i++) { for (j=1; j<=n; j++) printf("%5d",a[i][j]); cout << endl; }
        
        for (k=1; k<=n; k++)
            for (u=1; u<=n; u++)
                for (v=1; v<=n; v++)
                    a[u][v] = min(a[u][v], a[u][k] + a[k][v]);
                        
//        for (i=1; i<=n; i++) { for (j=1; j<=n; j++) printf("%5d",a[i][j]); cout << endl; }
        
        for (u=1, k = 0, minsum = INF; u<=n; u++) {
            for (v=1, sum=0; v<=n; v++)
                sum += a[u][v];
            if (sum < minsum) {
                minsum = sum; k = u;
            }
        }
            
        printf("Case #%d : %s\n", ++kase, name[k]);
    }
}
