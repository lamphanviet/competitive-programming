//*****************
// LAM PHAN VIET **
// UVA 12036 - Stable Grid
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
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) (i & -i)
#define INF 500000000
#define maxN 101
using namespace std;

int n, num[maxN][maxN];

bool Check() {
    REP (i, maxN) {
        int Count = 0;
        FOR (j, 1, n)
            Count += num[j][i];
        if (Count>n) return false;
    }
    return true;
}

main() {
//    FileIn("test"); FileOut("test");
    int Case, val;
    scanf("%d", &Case);
    FOR (kk, 1, Case) {
        scanf("%d", &n);
        FOR (i, 1, n)
            REP (j, maxN) num[i][j] = 0;
        FOR (i, 1, n) {
            FOR (j, 1, n) {
                scanf("%d", &val);
                num[i][val]++;
            }
        }
        printf("Case %d: ", kk);
        if (Check()) puts("yes");
        else puts("no");
    }
}

/* lamphanviet@gmail.com - 2011 */
