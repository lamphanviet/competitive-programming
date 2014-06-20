//*****************
// LAM PHAN VIET **
// UVA 637 - Booklet Printing
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
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 10000
using namespace std;

main() {
//    FileIn("test"); FileOut("test");
    int n, m, x, y, sheet;
    while (scanf("%d", &n) && n) {
        m = (n % 4)? (n / 4 + 1) * 4: n;
        sheet = 1;
        x = 1, y = m;
        printf("Printing order for %d pages:\n", n);
        while (x < y) {
            printf("Sheet %d, front: ", sheet);
            if (y > n) printf("Blank, %d\n", x);
            else printf("%d, %d\n", y, x);
            x++, y--;
            if (n==1) break;
            printf("Sheet %d, back : ", sheet);
            if (y > n) printf("%d, Blank\n", x);
            else printf("%d, %d\n", x, y);
            x++, y--;
            sheet++;
        }
    }
}

/* lamphanviet@gmail.com - 2011 */
