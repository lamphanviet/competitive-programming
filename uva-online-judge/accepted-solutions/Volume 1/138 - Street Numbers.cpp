/*****************/
/* LAM PHAN VIET */
/* UVA 138 - Street Numbers
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
#define maxN 10000
using namespace std;

int res[] = { 6, 8, 35, 49, 204, 288, 1189, 1681, 6930, 9800, 40391, 57121, 235416, 332928, 1372105, 1940449, 7997214, 11309768, 46611179, 65918161 };

main() {
    for (int i = 0; i < 20; i += 2)
        printf("%10d%10d\n", res[i], res[i+1]);
}

/*=======================10 second===============================

int64 check(int64 sum_left, int64 L, int64 R) {
    while (L <= R) {
        int64 mid = (L + R) / 2;
        int64 sum_right = mid * (mid + 1);
        if (sum_left == sum_right)
            return mid;
        
        if (sum_left < sum_right)
            R = mid - 1;
        else L = mid + 1;
    }
    return 0;
}

main() {
    FileIn("test"); FileOut("test");
    int Count = 0;
    for (int64 n = 5; Count < 10 ; n++) {
        int64 sum_left = 2 * n * n;
        int64 R = (int64)sqrt(sum_left);
        int64 m = check(sum_left, n + 1, R);
        if (m) {
            printf("%lld, %lld\n", n, m);
            Count++;
        }
    }
}
==========================================================*/
/* lamphanviet@gmail.com - 2011 */
