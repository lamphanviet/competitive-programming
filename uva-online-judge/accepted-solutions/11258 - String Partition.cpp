/*****************/
/* LAM PHAN VIET */
/* UVa: 11258 - String Partition
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

#define InpFile(f) freopen(f, "r", stdin)
#define OutFile(f) freopen(f, "w", stdout)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORR(i, a, b) for (int i = a; i < b; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) ( i & -i )
#define INF 500000000
#define maxInt 2147483647
#define maxN 210
using namespace std;

int n;
int64 sum[maxN];
char s[maxN];

main() {
//    InpFile("test.inp"); OutFile("test.out");
    int Case;
    for (scanf("%d ", &Case); Case--; ) {
        gets(s);
        int n = strlen(s);
        sum[0] = 0;
        FOR (i, 1, n) {
            sum[i] = 0;
            int j = i;
            int64 hs = 1, value = 0;
            while (j >= 1) {
                value += (s[j - 1] - 48) * hs;
                if (value > maxInt) break;
                sum[i] = max(sum[i], sum[j - 1] + value);
                hs *= 10;
                j--;
            }
        }
        printf("%lld\n", sum[n]);
    }
}

/* lamphanviet@gmail.com - 2011 */
