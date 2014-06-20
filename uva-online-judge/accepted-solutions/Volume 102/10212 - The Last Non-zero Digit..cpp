//*****************
// LAM PHAN VIET **
// UVA 10212 - The Last Non-zero Digit.
// Time limit: 10.000s
//********************************
#include <algorithm>
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

int power(int n, int k) {
    if (k == 1) return n;
    int tmp = power(n, k >> 1);
    if (k % 2) return (tmp * tmp * n) % 10;
    return (tmp * tmp) % 10;
}

main() {
//    FileIn("test"); FileOut("test");
    int n, m, count_2, count_5;
    while (scanf("%d %d", &n, &m) != EOF) {
        int64 res = 1;
        count_2 = count_5 = 0;
        if (m) {
            FOR (i, n - m + 1, n) {
                int ii = i;
                while (ii % 2 == 0) {
                    count_2++;
                    ii /= 2;
                }
                while (ii % 5 == 0) {
                    count_5++;
                    ii /= 5;
                }
                res = (res * ii) % 10;
            }
            if (count_2 > count_5)
                res *= power(2, count_2 - count_5);
            else if (count_2 < count_5)
                res *= power(5, count_5 - count_2);
        }
        printf("%d\n", (int)(res % 10));
    }
}

/* lamphanviet@gmail.com - 2011 */
