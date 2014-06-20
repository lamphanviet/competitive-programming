/*****************/
/* LAM PHAN VIET */
/* UVA 10929 - You can say 11
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
#define maxN 1001
using namespace std;

main() {
//    FileIn("test"); FileOut("test");
    char s[maxN];
    while (gets(s)) {
        int len = strlen(s);
        if (len == 1 && s[0] == '0') break;
        int n = 0;
        REP(i, len) {
            n = n * 10 + s[i] - 48;
            n %= 11;
        }
        printf("%s is ", s);
        if (n) printf("not ");
        printf("a multiple of 11.\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
