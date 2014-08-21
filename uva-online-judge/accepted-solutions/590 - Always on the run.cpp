//*****************
// LAM PHAN VIET **
// UVA 590 - Always on the run
// Time limit: 3.000s
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
#define Last(i) (i & -i)
#define INF 500000000
#define maxN 11
#define maxK 1001
using namespace std;

int n, k, dp[maxN][maxK];
vector<int> c[maxN][maxK];

main() {
//    FileIn("test"); FileOut("test");
    int Case = 0;
    while (scanf("%d %d", &n, &k) && (n || k)) {
        FOR (i, 1, n) {
            int tmp;
            FOR (j, 1, n)
                if (i!=j) {
                    scanf("%d", &tmp);
                    c[i][j].resize(tmp);
                    REP (t, tmp)
                        scanf("%d", &c[i][j][t]);
                }
            FOR (kk, 1, k) dp[i][kk] = INF;
        }
        FOR (i, 2, n)   // k = 1
            dp[i][1] = c[1][i][0];
        dp[1][1] = 0;
        FOR (kk, 2, k)
            FOR (i, 1, n) {
                FOR (j, 1, n)
                    if (i!=j && dp[j][kk-1]!=0) {
                        int x = (kk - 1) % c[j][i].size();
                        int cost = c[j][i][x];
                        if (cost==0) continue;
                        dp[i][kk] = min(dp[i][kk], dp[j][kk-1] + cost);
                    }
            }
        printf("Scenario #%d\n", ++Case);
        if (dp[n][k]<INF) printf("The best flight costs %d.\n", dp[n][k]);
        else puts("No flight possible.");
        printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
