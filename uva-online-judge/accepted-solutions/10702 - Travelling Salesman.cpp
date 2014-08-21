// 10702 - Travelling Salesman
#include <iostream>

using namespace std;

main() {
//    freopen("702.inp", "r", stdin); freopen("702.out", "w", stdout);
    int n, S, E, T, a[105][105], dp[1005][105];
    int i, j, k, tempmax, ans;
    while (cin >> n >> S >> E >> T) {
        if (!n && !S && !E && !T) break;
        for (i=1; i<=n; i++) {
            for (j=1; j<=n; j++)
                cin >> a[i][j];
        }
        
        for (i=1; i<=n; i++)
            dp[1][i] = a[S][i];
        
        for (k=2; k<=T; k++) {
            for (i=1; i<=n; i++) {
                dp[k][i] = -1;
                for (j=1; j<=n; j++)
                    if (j!=i) dp[k][i] = max(dp[k][i], a[j][i]+dp[k-1][j]);
            }
        }
        
        for (i=1, ans=-1; i<=E; i++) {
            cin >> k;
            ans = max(ans, dp[T][k]);
        }
        cout << ans << endl;
    }
}
