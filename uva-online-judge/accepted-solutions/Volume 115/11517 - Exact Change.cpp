// 11517 - Exact Change
#include <iostream>
#define N 10000

using namespace std;

main() {
    int kase, n, W, i, j;
    int dp[N+5], coin[105];
    cin >> kase;
    while (kase--) {
        cin >> W >> n;
        for (i=1; i<=n; i++)
            cin >> coin[i];
        for (i=1; i<=N; i++)
            dp[i] = N;
        dp[0] = 0;
        sort(coin+1, coin+n+1);
        for (i=1; i<=n; i++)
            for (j=N; j>=0; j--)
                if (j+coin[i]<=N && dp[j+coin[i]]>dp[j]+1)
                    dp[j+coin[i]] = dp[j]+1;
        for (i=W; i<=N; i++)
            if (dp[i]!=N) break;
        printf("%d %d\n", i, dp[i]);
    }
}
