/*****************/
/* LAM PHAN VIET */
/* UVA 498 - Polly the Polynomial
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

int n, c[maxN];
void solve(int x) {
    int64 res = 0, xx = 1;
    for (int i = n - 1; i >= 0; i--) {
        res += c[i] * xx;
        xx *= x;
    }
    printf("%lld", res);
}

main() {
//    FileIn("test"); FileOut("test");
    int len, k, x;
    char s[maxN];
    while (gets(s)) {
        len = strlen(s), k = 0;
        n = 0;
        while (k < len) {
            while (k < len && s[k] == ' ') k++;
            if (k < len) {
                sscanf(s + k, "%d", &c[n++]);
                while (k < len && s[k] != ' ') k++;
            }
        }
        
        gets(s);
        len = strlen(s), k = 0;
        bool space = false;
        while (k < len) {
            while (k < len && s[k] == ' ') k++;
            if (k < len) {
                sscanf(s + k, "%d", &x);
                if (space) printf(" "); space = true;
                solve(x);
                while (k < len && s[k] != ' ') k++;
            }
        }
        printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
