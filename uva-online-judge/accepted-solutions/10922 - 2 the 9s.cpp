/*****************/
/* LAM PHAN VIET */
/* UVA 10922 - 2 the 9s
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

int degree_count(int n) {
    int deg = 0;
    while (n != 9) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        n = sum;
        deg++;
    }
    return deg;
}

main() {
//    FileIn("test"); FileOut("test");
    char s[maxN];
    while (gets(s)) {
        int len = strlen(s);
        if (len == 1 && s[0] == '0') break;
        int mod = 0, sum = 0;
        REP(i, len) sum += s[i] - 48;
        printf("%s", s);
        if (sum % 9) printf(" is not a multiple of 9.");
        else printf(" is a multiple of 9 and has 9-degree %d.", degree_count(sum) + 1);
        putchar('\n');
    }
}

/* lamphanviet@gmail.com - 2011 */
