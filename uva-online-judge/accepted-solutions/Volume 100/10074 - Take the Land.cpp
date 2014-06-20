// 10074 - Take the Land
#include <iostream>

using namespace std;

main() {
//    freopen("074.inp", "r", stdin); freopen("074.out", "w", stdout);
    int i, j, k;
    int a[105][105], n, m;
    for (i=0; i<=100; i++) a[0][i] = 0;
    while (cin >> n >> m) {
        if (!n && !m) break;
        for (i=1; i<=n; i++)
            for (j=1; j<=m; j++) {
                cin >> a[i][j];
                a[i][j] += a[i-1][j];
            }
        
        int tempsum, temp, maxsum = 0;
        maxsum = !a[1][1];
        for (i=1; i<=n; i++)
            for (j=i; j<=n; j++) {
                tempsum = 0;
                for (k=1; k<=m; k++) {
                    temp = a[j][k] - a[i-1][k];
                    if (!temp) tempsum += j-i+1;
                    else tempsum = 0;
                    if (tempsum>maxsum) maxsum = tempsum;
                }
            }
        cout << maxsum << endl;
    }
}
