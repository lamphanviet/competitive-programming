/*****************/
/* LAM PHAN VIET */
/* UVA 11371 - Number Theory for Newbies
/* Time limit: 1.000s
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
#define maxN 20
using namespace std;

bool cmp(char a, char b) { return a > b; }

int64 convert_to_int(char *s, int len) {
    int64 res = 0;
    REP(i, len)
        res = res * 10 + s[i] - 48;
    return res;
}

main() {
//    FileIn("test"); FileOut("test");
    char s[maxN];
    int64 n, m;
    while (scanf("%s", &s) != EOF) {
        int len = strlen(s);
        sort(s, s + len, cmp);
        n = convert_to_int(s, len);
        sort(s, s + len);
        int k = 0;
        while (k < len && s[k] == '0') k++;
        if (k < len) swap(s[0], s[k]);
        m = convert_to_int(s, len);
        printf("%lld - %lld = %lld = 9 * %lld\n", n, m, n - m, (n - m) / 9);
    }
}

/* lamphanviet@gmail.com - 2011 */
