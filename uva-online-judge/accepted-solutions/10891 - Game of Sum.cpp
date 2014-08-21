// 10891 - Game of Sum
#include <iostream>
#define N 105
#define INF -100000000

using namespace std;

int n, a[N], lef[N], rig[N];
int best[N][N];

void Solve() {
    int i, j, k, maxtemp;
    for (i=1; i<=n; i++)
        best[i][i] = a[i];
    
    int u, v, len, temp1, temp2;
    for (len=2; len<=n; len++)
        for (u=1, v=u+len-1; v<=n; u++, v++) {
            for (i=u, maxtemp = INF; i<v; i++) {
                temp1 = rig[i+1] - rig[v+1];
                temp2 = lef[i] - lef[u-1];
                maxtemp = max(maxtemp, max(temp1 - best[u][i], temp2 - best[i+1][v]));
            }
            
            best[u][v] = max(maxtemp, lef[v]-lef[u-1]);
        }
    
//    for (i=1; i<=n; i++) {
//        for (j=1; j<=n; j++) printf("%5d", best[i][j]);
//        cout << endl;
//    }
}

main() {
 //   freopen("891.inp", "r", stdin); freopen("891.out", "w", stdout);
    int i;
    while (cin >> n && n) {
        lef[0] = 0;
        for (i=1; i<=n; i++) {
            scanf("%d", &a[i]);
            lef[i] = a[i]+lef[i-1];
        }
        rig[n+1] = 0;
        for (i=n; i>=1; i--)
            rig[i] = a[i]+rig[i+1];
 //       for (i=1; i<=n; i++) printf("%4d", lef[i]); cout << endl;
 //       for (i=1; i<=n; i++) printf("%4d", rig[i]); cout << endl;
        
        Solve();
        printf("%d\n", best[1][n]);
    }
}
