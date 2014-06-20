// 624 - CD        Knapsack 0_1
#include <iostream>
#define Max 20000

using namespace std;

main() {
 //   freopen("624.inp", "r", stdin); freopen("624.out", "w", stdout);
    int a[25], n, N, i, j, dp[25][Max+5];;
    while (scanf("%d", &N)==1) {
        scanf("%d", &n);
        for (i=1; i<=n; i++)
            scanf("%d", &a[i]);
        for (j=0; j<=N; j++)
            dp[0][j] = 0;
        for (i=1; i<=n; i++)
            for (j=0; j<=N; j++)
                if (a[i]<=j) dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i]] + a[i]);
                else dp[i][j] = dp[i-1][j];
        int sum=dp[n][N], ans[n], k=0;
        
        while (n!=0) {
            if (dp[n][N]!=dp[n-1][N]) {
                ans[k++] = a[n];
                N -= a[n];
            }
            n--;
        }
        for (k--; k>=0; k--) printf("%d ", ans[k]);
        printf("sum:%d\n", sum);
    }
}
