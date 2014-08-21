/*****************/
/* LAM PHAN VIET */
/* UVA 10719 - Quotient Polynomial
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
#define maxN 10005
using namespace std;

int n, m, k, a[maxN];
char buff[maxN * 10];

void read_array() {
    gets(buff);
    int len = strlen(buff), k = 0;
    n = -1;
    while (k < len)
        if (buff[k] != ' ') {
            int sign = 1, value = 0;
            if (buff[k] == '-')
                sign = -1, k++;
            while (k < len && buff[k] != ' ') {
                value = value * 10 + (buff[k] - 48);
                k++;
            }
            a[++n] = value * sign;
        }
        else k++;
}

void print(int n) {
    char s[10];
    putchar(' ');
    if (!n) { putchar('0'); return; }
    int m = 0;
    if (n < 0)
        putchar('-'), n = -n;
    while (n) {
        s[m++] = n % 10;
        n /= 10;
    }
    while (m > 0) putchar(s[--m]+48);
}

void solve() {
    printf("q(x):");
    FOR (i, 0, n-1) {
        print(a[i]);
        a[i+1] += a[i] * k;
    }
    putchar('\n');
    putchar('r'); putchar(' '); putchar('='); print(a[n]);
    putchar('\n');
    putchar('\n');
}

main() {
//    FileIn("test"); FileOut("test");
    while (scanf(" %d ", &k) != EOF) {
        read_array();
        solve();
    }
}

/* lamphanviet@gmail.com - 2011 */
