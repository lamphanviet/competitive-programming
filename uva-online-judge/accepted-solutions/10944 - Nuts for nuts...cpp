/*****************/
/* LAM PHAN VIET */
/* UVA 10944 - Nuts for nuts..
/* Time limit: 3.000s
/********************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
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
#define INF 500
#define maxN 17
using namespace std;

int n, x[maxN], y[maxN];
int d[maxN][maxN], dp[maxN][bit(maxN)];

void solve_dp() {
    REP(i, n)
        REP(j, bit(n))
            dp[i][j] = INF;
    dp[0][1] = 0;
    
    int bit_max = bit(n);
    for (int x = 1; x < bit_max; x += 2) {
        REP(i, n) {
            if ((x & bit(i)) == 0 || dp[i][x] == INF) continue;
            REP(j, n)
                if ((x & bit(j)) == 0) {
                    int xx = x | bit(j);
                    if (dp[j][xx] > dp[i][x] + d[i][j])
                        dp[j][xx] = dp[i][x] + d[i][j];
                }
        }
    }
    
    int res = INF;
    REP(i, n)
        res = min(res, dp[i][bit_max-1] + d[i][0]);
    printf("%d\n", res);
}

main() {
//    FileIn("test"); FileOut("test");
    int r, c;
    char s[30][30];
    while (scanf(" %d %d ", &r, &c) != EOF) {
        n = 1;
        REP(i, r) {
            gets(s[i]);
            REP(j, c)
                if (s[i][j] == 'L')
                    x[0] = i, y[0] = j;
                else if (s[i][j] == '#')
                    x[n] = i, y[n] = j, n++;
        }
        REP(i, n) {
            FOR (j, i+1, n-1) {
                r = abs(x[i] - x[j]);
                c = abs(y[i] - y[j]);
                d[i][j] = d[j][i] = max(r, c);
            }
            d[i][i] = 0;
        }
        solve_dp();
    }
}

/* lamphanviet@gmail.com - 2011 */
