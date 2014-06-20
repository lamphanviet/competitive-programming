/*****************/
/* LAM PHAN VIET */
/* UVA 10298 - Power Strings
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

int len;
char s[maxN];

bool check(int n) {
    n = len / n;
    for (int i = 0; i < n; i++) {
        for (int j = i + n; j < len; j += n) {
            if (s[j] != s[i]) return false;
        }
    }
    return true;
}

main() {
//    FileIn("test"); FileOut("test");
    while (gets(s)) {
        len = strlen(s);
        if (len == 1 && s[0] == '.') break;
        int n = len + 1;
        while (n-- > 2) {
            if (len % n) continue;
            if (check(n)) break;
        }
        printf("%d\n", n);
    }
}

/* lamphanviet@gmail.com - 2011 */
