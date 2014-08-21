//*****************
// LAM PHAN VIET **
// UVA 116 - Unidirectional TSP
// Time limit: 3.000
//********************************
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 10000
using namespace std;

main() {
 //   freopen("116.inp", "r", stdin); freopen("116.out", "w", stdout);
    int n, m, a[15][105], dp[15][105], Trace[15][105];
    int ans, temp, u, k;
    while (scanf("%d %d", &n, &m) != EOF) {
        FOR (i, 1, n)
            FOR (j, 1, m)
                scanf("%d", &a[i][j]);
        FOR (i, 1, n)
            dp[i][m] = a[i][m];
            
        for (int j=m-1; j>=1; j--)
            FOR (i, 1, n) {
                dp[i][j] = a[i][j] + dp[i][j+1]; Trace[i][j] = i;
                
                if (i==1) k=n; else k=i-1;
                temp = a[i][j] + dp[k][j+1];
                if (temp<dp[i][j] || (temp==dp[i][j] && k<Trace[i][j])) {
                    dp[i][j] = temp; Trace[i][j] = k;
                }
                
                if (i==n) k=1; else k=i+1;
                temp = a[i][j] + dp[k][j+1];
                if (temp<dp[i][j] || (temp==dp[i][j] && k<Trace[i][j])) {
                    dp[i][j] = temp; Trace[i][j] = k;
                }
            }
        
        ans = dp[1][1], u = 1;
        FOR (i, 2, n)
            if (dp[i][1]<ans) {
                ans = dp[i][1];
                u = i;
            }
        printf("%d", u); u = Trace[u][1];
        FOR (i, 2, m) {
            printf(" %d", u);
            u = Trace[u][i];
        }
        printf("\n%d\n", ans);
    }
}
