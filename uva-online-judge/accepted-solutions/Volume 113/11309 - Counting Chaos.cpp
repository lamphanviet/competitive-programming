/*****************/
/* LAM PHAN VIET */
/* UVA 11309 - Counting Chaos
/* Time limit: 5.000s
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
#define maxN 2370
using namespace std;

bool palind[maxN];

bool isPalin(int n) {
    char s[10];
    int m = 0;
    while (n) {
        s[m++] = n % 10 + 48;
        n /= 10;
    }
    for (int i = 0, j = m - 1; i < j; i++, j--)
        if (s[i] != s[j]) return false;
    return true;
}

void precal() {
    Fill(palind, false);
    for (int h = 0; h < 24; h++)
        for (int m = 0; m < 60; m++)
            palind[h * 100 + m] = isPalin(h * 100 + m);
}

void solve(int h, int m) {
    bool f = false;
    h = h * 100 + m;
    for (h++; h <= 2359; h++)
        if (palind[h]) {
            f = true; break;
        }
    if (!f) {
        for (h = 0; h <= 2359; h++)
            if (palind[h]) {
                f = true; break;
            }
    }
    m = h % 100;
    h /= 100;
    if (h < 10) putchar('0');
    printf("%d:", h);
    if (m < 10) putchar('0');
    printf("%d\n", m);
}

main() {
 //   FileIn("test"); FileOut("test");
    precal();
    int Case, h, m;
    for (scanf("%d ", &Case); Case--; ) {
        scanf("%d:%d", &h, &m);
        solve(h, m);
    }
}

/* lamphanviet@gmail.com - 2011 */
