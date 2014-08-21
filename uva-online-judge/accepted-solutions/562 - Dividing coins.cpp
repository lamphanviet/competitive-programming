/*****************/
/* LAM PHAN VIET */
/* UVA 562 - Dividing coins
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
#define maxN 500005
using namespace std;

int a[105], dp[maxN], n;

main() {
//    FileIn("test"); FileOut("test");
    int Case, asum, hsum;
    for (scanf("%d", &Case); Case--; ) {
        scanf("%d", &n);
        asum = 0;
        FOR (i, 1, n) {
            scanf("%d", &a[i]);
            asum += a[i];
        }
        hsum = asum/2;
        FOR (i, 1, hsum) dp[i] = 0;
        dp[0] = 1;
        FOR (i, 1, n) {
            for (int j = hsum; j >= 0; j--)
                if (j >= a[i] && dp[j-a[i]])
                    dp[j] = 1;
        }
        
        int k = 0;
        for (int i = hsum; i >= 1; i--)
            if (dp[i]) {
                k = i; break;
            }
        printf("%d\n", asum - k * 2);
    }
}
