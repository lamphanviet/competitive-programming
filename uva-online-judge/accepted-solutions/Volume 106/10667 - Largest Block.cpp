// 10667 - Largest Block
#include <iostream>

using namespace std;

main() {
//    freopen("667.inp", "r", stdin); freopen("667.out", "w", stdout);
    int a[105][105], n, m;
    int kase, i, j, k;
    for (i=0; i<105; i++) a[0][i] = 0;
    cin >> kase;
    while (kase--) {
        cin >> n;
        for (i=1; i<=n; i++)
            for (j=i; j<=n; j++)
                a[i][j] = a[j][i] = 0;
            
        cin >> m;
        while (m--) {
            int sx, sy, fx, fy;
            cin >> sx >> sy >> fx >> fy;
            for (j=sx; j<=fx; j++)
                for (k=sy; k<=fy; k++)
                    a[j][k] = 1;
        }
        
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++)
                a[i][j] += a[i-1][j];
        
        int tempsum, temp, maxsum=!a[1][1];
        for (i=1; i<=n; i++)
            for (j=i; j<=n; j++) {
                tempsum = 0;
                for (k=1; k<=n; k++) {
                    temp = a[j][k] - a[i-1][k];
                    if (temp==0) tempsum+=j-i+1;
                    else tempsum = 0;
                    if (tempsum>maxsum) maxsum = tempsum;
                }
            }
            
        cout << maxsum << endl;
    }
}
