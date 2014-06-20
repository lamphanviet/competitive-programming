//*****************
// LAM PHAN VIET **
// UVA 10036 - Divisibility
// Time limit: 3.000s
//********************************
#include <algorithm>
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
#define maxN 10005
#define maxK 105
using namespace std;

int n, k, a[maxN];
bool dp[maxN][maxK];

main() {
//    FileIn("test"); FileOut("test");
    int Case;
    for (scanf("%d", &Case); Case--; ) {
        scanf("%d %d", &n, &k);
        FOR (i, 1, n) {
            scanf("%d", &a[i]);
            memset(dp[i], false, k + 1);
        }
        int value = a[1] % k;
        if (value < 0) value += k;
        dp[1][value] = true;
        FOR (i, 2, n)
            REP (j, k)
                if (dp[i-1][j]) {
                    value = j + a[i];
                    value %= k;
                    if (value < 0) value += k;
                    dp[i][value] = true;
                    
                    value = j - a[i];
                    value %= k;
                    if (value < 0) value += k;
                    dp[i][value] = true;
                }
        if (dp[n][0]) puts("Divisible");
        else puts("Not divisible");
    }
}

/* lamphanviet@gmail.com - 2011 */
