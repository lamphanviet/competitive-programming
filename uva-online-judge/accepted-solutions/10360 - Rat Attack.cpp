//*****************
// LAM PHAN VIET **
// UVA 10360 - Rat Attack
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
#define INF 500000000
#define maxN 1030
using namespace std;

const int n = 1024;

int d, value[maxN][maxN], sum[maxN][maxN];

main() {
//    FileIn("test"); FileOut("test");
    int Case, m, u, v, w;
    for (scanf("%d", &Case); Case--; ) {
        scanf("%d %d", &d, &m);
        Fill(value, 0);
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            value[u][v] = w;
        }
        FOR (i, 0, n)
            sum[i][0] = value[i][0], sum[0][i] = value[0][i];
        FOR (i, 1, n)
            FOR (j, 1, n)
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + value[i][j];
        int x, y, size_max = 1, x1, y1, x2, y2;
        FOR (i, 0, n)
            FOR (j, 0, n) {
                x1 = max(i - d, 0);
                y1 = max(j - d, 0);
                x2 = min(i + d, n);
                y2 = min(j + d, n);
                int size_tmp = sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
                if (size_tmp > size_max) {
                    size_max = size_tmp;
                    x = i; y = j;
                }
            }
        printf("%d %d %d\n", x, y, size_max);
    }
}

/* lamphanviet@gmail.com - 2011 */
