// 10681 - Teobaldo's Trip
#include <iostream>

using namespace std;

main() {
 //   freopen("681.inp", "r", stdin); freopen("681.out", "w", stdout);
    int n, m, a[105][105], s, f, D;
    int i, j, k, dp[105][205];
    while (cin >> n >> m) {
        if (!n && !m) break;
        for (i=1; i<=n; i++)
            for (j=i; j<=n; j++)
                a[i][j] = a[j][i] = 0;
        while (m--) {
            cin >> i >> j;
            a[i][j] = a[j][i] = 1;
        }
        cin >> s >> f >> D;
        for (i=1; i<=n; i++)
            dp[i][1] = a[s][i];
        for (k=2; k<=D; k++)
            for (i=1; i<=n; i++) {
                int ok=0; j=1;
                while (j<=n && !ok) {
                    if (i!=j && dp[j][k-1] && a[i][j]) ok=1;
                    j++;
                }
                dp[i][k] = ok;
            }
  //      for (i=1; i<=n; i++) { for (j=1; j<=D; j++) printf("%4d", dp[i][j]); cout << endl; }
        
        if ((D==0 && s==f)|| dp[f][D]) cout << "Yes, Teobaldo can travel.";
        else cout << "No, Teobaldo can not travel.";
        cout << endl;
    }
}
