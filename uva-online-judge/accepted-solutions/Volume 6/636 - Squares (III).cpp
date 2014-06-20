//*****************
// LAM PHAN VIET **
// UVA 636 - Squares (III)
// Time limit: 3.000s
//********************************
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
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
#define Last(i) (i & -i)
#define INF 500000000
#define maxN 101
using namespace std;

int len;
char s[maxN];

bool Check(int base) {
    uint64 n = 0;
    REP (i, len)
        n = n*base + (s[i]-48);
    uint64 nn = (uint64)sqrt(n);
    return (nn*nn == n);
}

main() {
//    FileIn("test"); FileOut("test");
    while (gets(s)) {
        len = strlen(s);
        if (len==1 && s[0]=='0') break;
        int Max = 0;
        REP (i, len) Max = max(Max, s[i]-48); Max++;
        FOR (i, Max, 100)
            if (Check(i)) {
                printf("%d\n", i);
                break;
            }
    }
}

/* lamphanviet@gmail.com - 2011 */
