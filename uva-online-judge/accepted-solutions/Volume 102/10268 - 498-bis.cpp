/*****************/
/* LAM PHAN VIET */
/* UVA 10268 - 498-bis
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
#define maxN 1000001
using namespace std;

int n, x, a[maxN];
char buf[maxN];

void read_array() {
    n = -1;
    gets(buf);
    int len = strlen(buf), k = 0;
    while (k < len)
        if (buf[k] != ' ') {
            int sign = 1;
            if (buf[k] == '-')
                sign = -1, k++;
            if (k < len) {
                int64 value = 0;
                while (k < len && '0' <= buf[k] && buf[k] <= '9') {
                    value = value * 10 + (buf[k] - 48);
                    k++;
                }
                a[++n] = value * sign;
            }
        }
        else k++;
//    FOR (i, 0, n) printf("%d ", a[i]); puts("");
}

main() {
//    FileIn("test"); FileOut("test");
    int len, k;
    while (scanf(" %d ", &x) != EOF) {
        read_array();
        int64 res = 0, nn = n;
        REP(i, n) {
            res *= x;
            res += (nn--) * a[i];
        }
        printf("%lld\n", res);
    }
}

/* lamphanviet@gmail.com - 2011 */
