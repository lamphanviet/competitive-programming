/*****************/
/* LAM PHAN VIET */
/* UVA 348 - Optimal Array Multiplication Sequence
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
#define INF 500000000
#define maxN 12
using namespace std;

int n, r[maxN], c[maxN];
int dp[maxN][maxN], trace[maxN][maxN];
int pr_open[maxN], pr_close[maxN];

void solve_dp() {
    FOR (len, 2, n) {
        for (int i = 1, j = i + len - 1; j <= n; i++, j++) {
            int cost = r[i] * c[j];
            dp[i][j] = INF;
            FOR (k, i, j-1) {
                int cost_tmp = cost * c[k];
                cost_tmp += dp[i][k] + dp[k+1][j];
                if (cost_tmp < dp[i][j]) {
                    dp[i][j] = cost_tmp;
                    trace[i][j] = k;
                }
            }
        }
    }
}

void cal_pr(int i, int j) {
    if (i == j) return;
    pr_open[i]++; pr_close[j]++;
    int k = trace[i][j];
    cal_pr(i, k);
    cal_pr(k + 1, j);
}

void result(int &Case) {
    cal_pr(1, n);
    printf("Case %d: ", ++Case);
    while (pr_open[1]--) putchar('(');
    printf("A1");
    while (pr_close[1]--) putchar(')');
    FOR (i, 2, n) {
        putchar(' '); putchar('x'); putchar(' ');
        while (pr_open[i]--) putchar('(');
        printf("A%d", i);
        while (pr_close[i]--) putchar(')');
    }
    putchar('\n');
}

main() {
//    FileIn("test"); FileOut("test");
    int Case = 0;
    while (scanf("%d", &n) && n) {
        FOR (i, 1, n) {
            scanf("%d %d", &r[i], &c[i]);
            dp[i][i] = 0;
            pr_open[i] = pr_close[i] = 0;
        }
        solve_dp();
        result(Case);
    }
}

/* lamphanviet@gmail.com - 2011 */
