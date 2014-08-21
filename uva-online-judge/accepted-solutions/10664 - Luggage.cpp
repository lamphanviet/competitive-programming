/*****************/
/* LAM PHAN VIET */
/* UVA 10664 - Luggage
/* Time limit: 3.000s
/********************************/
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
#define maxN 25
#define maxS 205
using namespace std;

int n, a[maxN], sum;
bool dp[maxS];

main() {
//    FileIn("test"); FileOut("test");
    int Case;
    char s[maxS];
    for (scanf("%d ", &Case); Case--; ) {
        gets(s); 
        n = sum = 0;
        int len = strlen(s), k = 0;
        while (k < len) {
            while (k < len && s[k] == ' ') k++;
            if (k < len) {
                sscanf(s + k, "%d", &a[++n]);
                sum += a[n];
                while (k < len && s[k] != ' ') k++;
            }
        }
        if (sum % 2) puts("NO");
        else {
            sum /= 2;
            memset(dp, false, sum + 1);
            dp[0] = true;
            FOR (i, 1, n)
                for (int j = sum; j >= 0; j--)
                    if (dp[j] && j + a[i] <= sum)
                        dp[j + a[i]] = true;
            if (dp[sum]) puts("YES");
            else puts("NO");
        }
    }
}

/* lamphanviet@gmail.com - 2011 */
