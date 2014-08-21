//*****************
// LAM PHAN VIET **
// UVA 12024 - Hats
// Time limit: 1.000s
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
#define REP(i, a, b) for (int i=a; i<=b; i++)
#define REP0(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) (i & -i)
#define Parent(i) (i - Last(i))
#define INF 500000000
#define maxN 115
using namespace std;

uint64 a[maxN], GT[maxN], C[maxN][maxN];

void PreCalc() {
    GT[1] = 1;
    REP (i, 2, 12) GT[i] = GT[i-1]*i;
    C[0][0] = 1;
    REP (i, 1, 12) {
        C[i][0] = C[i][i] = 1;
        REP (j, 1, i-1) C[i][j]  = C[i-1][j] + C[i-1][j-1];
    }
    a[2] = 1;
    REP (i, 3, 12) {
        a[i] = GT[i] - 1;
        REP (j, 2, i-1)
            a[i] -= a[j] * C[i][j];
   //     a[i] -= C[i][1];
    }
}

main() {
 //   FileIn("test"); FileOut("test");
    PreCalc();
    int Case, n;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d", &n);
        printf("%lld/%lld\n", a[n], GT[n]);
    }
}

/* lamphanviet@gmail.com - 2011 */
