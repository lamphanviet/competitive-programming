// 990 - Diving for Gold
#include <iostream>
#define N 1005

using namespace std;

main() {
//    freopen("990.inp", "r", stdin); freopen("990.out", "w", stdout);
    int i, j, m, End = 0;
    int n, maxt, w[35], v[35], w1[35], dp[35][N];
    while (cin >> maxt >> m) {
        cin >> n;
        for (i=1; i<=n; i++) {
            scanf("%d %d", &w1[i], &v[i]);
            w[i] = 3*w1[i]*m;
        }
        
        for (j=0; j<=maxt; j++) dp[0][j] = 0;
        for (i=1; i<=n; i++)
            for (j=0; j<=maxt; j++)
                if (w[i]<=j) dp[i][j] = max(dp[i-1][j], v[i]+dp[i-1][j-w[i]]);
                else dp[i][j] = dp[i-1][j];
        if (End) cout << endl; End=1;
        
        int ans[35], k=0, sum=0;
        while (n>0) {
            if (dp[n][maxt]!=dp[n-1][maxt]) {
                ans[k++] = n;
                maxt -= w[n];
                sum += v[n];
            }
            n--;
        }
        printf("%d\n", sum);
        printf("%d\n", k);
        for (i=k-1; i>=0; i--)
            printf("%d %d\n", w1[ans[i]], v[ans[i]]);
    }
}
