/*****************/
/* LAM PHAN VIET */
/* UVA 392 - Polynomial Showdown
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
#define maxN 10
using namespace std;

int n = 8, a[maxN];
char buff[100];

bool read_input() {
    if (!gets(buff)) return false;
    int len = strlen(buff), k = 0, m = n;
    while (m >= 0 && k < len)
        if (buff[k] != ' ') {
            int sign = 1, value = 0;
            if (buff[k] == '-')
                sign = -1, k++;
            while (k < len && buff[k] != ' ') {
                value = value * 10 + (buff[k] - 48);
                k++;
            }
            a[m--] = value * sign;
        }
        else k++;
    return true;
}

main() {
//    FileIn("test"); FileOut("test");
    while (read_input()) {
        bool first = true;
        for (int i = n; i >= 0; i--)
            if (a[i]) {
                if (first) {
                    if (a[i] < 0) printf("-");
                }
                else {
                    if (a[i] < 0) printf(" - ");
                    else printf(" + ");
                }
                
                a[i] = abs(a[i]);
                if (a[i] != 1 || i == 0) printf("%d", a[i]);
                if (i == 1) printf("x");
                else if (i > 1) printf("x^%d", i);
                first = false;
            }
        if (first) printf("0");
        puts("");
    }
}

/* lamphanviet@gmail.com - 2011 */
