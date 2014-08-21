//*****************
// LAM PHAN VIET **
// UVA 11957 - Checkers
// Time limit: 1s
//********************************
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxN 105
#define MOD 1000007
int n, dp[maxN][maxN];
char s[maxN][maxN];

bool isOK(int x, int y) {
    return (x>=0 && x<n && y>=0 && y<n);
}

main() {
//    freopen("gg.inp", "r", stdin); freopen("gg.out", "w", stdout);
    int Case, wx, wy;
    scanf("%d", &Case);
    for (int kk=1; kk<=Case; kk++) {
        scanf("%d", &n); gets(s[0]);
        bool found = false;
        for (int i=0; i<n; i++) {
            gets(s[i]);
            if (!found) for (int j=0; j<n; j++)
                if (s[i][j]=='W') {
                    wx = i; wy = j;
                    found = true;
                }
        }
        
        for (int j=0; j<n; j++)
            dp[wx][j] = dp[wx+1][j] = 0;
        dp[wx][wy] = 1;
        for (int i=wx-1; i>=0; i--)
            for (int j=0; j<n; j++) {
                dp[i][j] = 0;
                if (s[i][j]=='.') {
                    if (isOK(i+1, j-1)) {
                        if (s[i+1][j-1]=='B') {
                            if (isOK(i+2, j-2) && s[i+2][j-2]!='B')
                                dp[i][j] += dp[i+2][j-2];
                        }
                        else dp[i][j] += dp[i+1][j-1];
                    }
                    
                    if (isOK(i+1, j+1)) {
                        if (s[i+1][j+1]=='B') {
                            if (isOK(i+2, j+2) && s[i+2][j+2]!='B')
                                dp[i][j] += dp[i+2][j+2];
                        }
                        else dp[i][j] += dp[i+1][j+1];
                    }
                }
                dp[i][j] %= MOD;
            }
        int ans = 0;
        for (int i=0; i<n; i++) {
            ans += dp[0][i];
            ans %= MOD;
        }
        printf("Case %d: %d\n", kk, ans);
    }
}

/* lamphanviet@gmail.com - 2011 */
