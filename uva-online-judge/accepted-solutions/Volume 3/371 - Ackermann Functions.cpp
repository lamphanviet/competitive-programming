/*****************/
/* LAM PHAN VIET */
/* UVA 371 - Ackermann Functions
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
#define maxN 10000
using namespace std;

int produce(int64 n) {
    int length = 0;
    do {
        if (n % 2) n = 3 * n + 1;
        else n /= 2;
        length++;
    } while (n != 1);
    return length;
}

main() {
//    FileIn("test"); FileOut("test");
    int n, m;
    while (scanf("%d %d", &n, &m) && (n || m)) {
        int len_max = 0, number = 0;
        if (n > m) swap(n, m);
        FOR (i, n, m) {
            int len = produce(i);
            if (len > len_max) {
                len_max = len;
                number = i;
            }
        }
        printf("Between %d and %d, %d generates the longest sequence of %d values.\n", n, m, number, len_max);
    }
}

/* lamphanviet@gmail.com - 2011 */
