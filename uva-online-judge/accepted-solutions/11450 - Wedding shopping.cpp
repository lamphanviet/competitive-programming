// 11450 - Wedding shopping
#include <iostream>
#include <vector>
#define N 25

using namespace std;

int dp[205][N], M, n;
vector <int> G[N];

main() {
//    freopen("450.inp", "r", stdin); freopen("450.out", "w", stdout);
    int kase, i, j, k, temp;
    cin >> kase;
    while (kase--) {
        cin >> M >> n;
        for (i=1; i<=n; i++) {
            cin >> k;
            G[i].resize(k);
            for (j=0; j<k; j++)
                cin >> G[i][j];
        }
        
        for (i=0; i<=M; i++)
            for (j=0; j<=n; j++)
                dp[i][j] = -2;
        dp[0][0] = 0;
        for (i=1; i<=M; i++) {
            dp[i][0] = 0;
            for (j=1; j<=n; j++) {
                dp[i][j] = -2;
                for (k=0; k<G[j].size(); k++) {
                    if (i-G[j][k]<0 || dp[ i-G[j][k] ][ j-1 ]<0) temp = -2;
                    else temp = dp[ i-G[j][k] ][ j-1 ] + G[j][k];
                    dp[i][j] = max(dp[i][j], temp);
                }
            }
        }
        
 //       for (i=1; i<=M; i++) { for (j=1; j<=n; j++) printf("%4d", dp[i][j]); cout << endl; }
        
        
        if (dp[M][n]>=0) cout << dp[M][n];
        else cout << "no solution";
        cout << endl;
    }
}
