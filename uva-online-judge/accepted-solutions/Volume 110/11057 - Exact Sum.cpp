/*****************/
/* LAM PHAN VIET */
/* UVa: 11057 - Exact Sum
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

#define InpFile(f) freopen(f, "r", stdin)
#define OutFile(f) freopen(f, "w", stdout)
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
#define maxN 10001
using namespace std;

int n, m, a[maxN];

void solve() {
    int x, y;
    for (int i = 1, mm = m / 2; i <= n && a[i] <= mm; i++) {
        int L = i + 1, R = n, key = m - a[i];;
        while (L <= R) {
            int mid = (L + R) >> 1;
            if (a[mid] == key) {
                x = a[i]; y = key;
                break;
            }
            else if (a[mid] < key)
                L = mid + 1;
            else
                R = mid - 1;
        }
    }
    printf("%d and %d.\n", x, y);
}

main() {
//    InpFile("test.inp"); OutFile("test.out");
    while (scanf("%d", &n) != EOF) {
        FOR (i, 1, n) scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        scanf("%d", &m);
        printf("Peter should buy books whose prices are ");
        solve();
        putchar('\n');
    }
}

/* lamphanviet@gmail.com - 2011 */
