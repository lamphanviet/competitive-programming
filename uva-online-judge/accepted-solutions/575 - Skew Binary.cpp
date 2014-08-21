/*****************/
/* LAM PHAN VIET */
/* UVA 575 - Skew Binary
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
#define maxN 100
using namespace std;

char s[maxN];

main() {
//    FileIn("test"); FileOut("test");
    while (gets(s)) {
        int len = strlen(s);
        if (len == 1 && s[0] == '0') break;
        int res = 0, pow2 = 2;
        for (int i = len - 1; i >= 0; i--) {
            res += (s[i] - 48) * (pow2 - 1);
            pow2 = pow2 << 1;
        }
        printf("%d\n", res);
    }
}

/* lamphanviet@gmail.com - 2011 */
