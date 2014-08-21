//*****************
// LAM PHAN VIET **
// UVA 108 - Maximum Sum
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
#define maxN 105
using namespace std;

int n, a[maxN][maxN];

main() {
    while (scanf("%d", &n) != EOF) {
        FOR (j, 1, n) a[0][j] = 0;
        FOR (i, 1, n)
            FOR (j, 1, n) {
                scanf("%d", &a[i][j]);
                a[i][j] += a[i-1][j];
            }
        int sum_max = a[1][1];
        FOR (i, 1, n)
            FOR (j, i, n) {
                int sum_tmp = a[j][1] - a[i - 1][1];
                sum_max = max(sum_max, sum_tmp);
                FOR (k, 2, n) {
                    sum_tmp += a[j][k] - a[i-1][k];
                    sum_max = max(sum_max, sum_tmp);
                    if (sum_tmp < 0) sum_tmp = 0;
                }
            }
        printf("%d\n", sum_max);
    }
}
