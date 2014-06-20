// 10130 - SuperSale
#include <iostream>
#define N 1005
#define P 105

using namespace std;

main() {
 //   freopen("130.inp", "r", stdin); freopen("130.out", "w", stdout);
    int kase, i, j, k;
    int n, v[N], w[N], np, per[P];
    int maxpr, dp[N][35], sum;
    scanf("%d", &kase);
    while (kase--) {
        scanf("%d", &n);
        for (i=1; i<=n; i++)
            scanf("%d %d", &v[i], &w[i]);
        cin >> np;
        for (i=1, maxpr=0; i<=np; i++) {
            scanf("%d", &per[i]);
            maxpr = max(maxpr, per[i]);
        }
        
        for (j=0; j<=maxpr; j++) dp[0][j] = 0;
        for (i=1; i<=n; i++)
            for (j=0; j<=maxpr; j++) {
                if (w[i]<=j) dp[i][j] = max(dp[i-1][j], v[i]+dp[i-1][j-w[i]]);
                else dp[i][j] = dp[i-1][j];
            }
        for (i=1, sum=0; i<=np; i++)
            sum += dp[n][per[i]];
        cout << sum << endl;
    }
}
