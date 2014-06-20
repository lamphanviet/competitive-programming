// 10313 - Pay the Price
#include <iostream>
#define N 300

using namespace std;

main() {
    int i, j;
    long long dp[N+5][N+5];
    for (j=1; j<=N; j++)
        dp[0][j] = 0;
    dp[0][0] = 1;
    for (i=1; i<=N; i++)
        for (j=0; j<=N ;j++)
            if (i<=j) dp[i][j] = dp[i][j-i] + dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
    
    int n, a, b, th, len;
    char s[20];
    while (gets(s)) {
        sscanf(s, "%d", &n); th=1;
        
        i = 0; len = strlen(s);
        while (i<len && s[i]==' ');
        while (i<len && isdigit(s[i])) i++;
        if (i<len) {
            sscanf(s+i, "%d", &a); th=2;
            while (i<len && s[i]==' ') i++;
        }
        while (i<len && isdigit(s[i])) i++;
        if (i<len) {
            sscanf(s+i, "%d", &b); th=3;
        }
        
        long long ans;
        switch (th) {
            case 1: ans = dp[n][n]; break;
            case 2:  {
                if (a>n) a=n;
                ans = dp[a][n]; break;
            }
            case 3: {
                if (b>n) b=n;
                if (a>n) a=n+1;
                if (a) ans = dp[b][n] - dp[a-1][n];
                else ans = dp[b][n];
            }
        }
        cout << ans << endl;
    }
}
