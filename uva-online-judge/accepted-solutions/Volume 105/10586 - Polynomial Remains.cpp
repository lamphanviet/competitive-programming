/*****************/
/* LAM PHAN VIET */
/* UVA 10586 - Polynomial Remains
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

int n, k, a[maxN];
char buff[maxN * 10];

void read_array() {
    gets(buff);
    int len = strlen(buff), k = 0, m = 0;
    while (k < len)
        if (buff[k] != ' ') {
            int value = 0, sign = 1;
            if (buff[k] == '-')
                sign = -1, k++;
            while (k < len && buff[k] != ' ')
                value = value * 10 + (buff[k++] - 48);
            a[m++] = value * sign;
        }
        else k++;
}

void print(int n) {
    if (!n) { putchar('0'); return; };
    if (n < 0)
        putchar('-'), n = -n;
    char s[10]; int m = 0;
    while (n) {
        s[m++] = n % 10 + 48;
        n /= 10;
    }
    while (m > 0) putchar(s[--m]);
}

void solve() {
    int i = n;
    while (i >= k) {
        a[i - k] -= a[i];
        a[i] = 0;
        i--;
    }
    while (i >= 0 && !a[i]) i--;
    bool space = false;
    FOR (j, 0, i) {
        if (space) putchar(' ');
        print(a[j]);
        space = true;
    }
    if (!space) putchar('0');
    putchar('\n');
}

main() {
//    FileIn("test"); FileOut("test");
    while (scanf("%d %d ", &n, &k) != EOF) {
        if (n == -1 && k == -1) break;
        read_array();
        solve();
    }
}

/* lamphanviet@gmail.com - 2011 */
