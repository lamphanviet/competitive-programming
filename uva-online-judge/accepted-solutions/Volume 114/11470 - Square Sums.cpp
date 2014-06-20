//*****************
// LAM PHAN VIET **
// UVA 11470 - Square Sums
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
#define maxN 12
using namespace std;

int n, a[maxN][maxN];
int k, res[maxN];

main() {
//    FileIn("test"); FileOut("test");
    int Case = 0;
    while (scanf("%d", &n) && n) {
        FOR (i, 1, n) {
            FOR (j, 1, n)
                scanf("%d", &a[i][j]);
            res[i] = 0;
        }
        int k = n/2;
        for (int i=1, u=n; i<=k; i++, u--)
            for (int j=1, v=n; j<=n; j++, v--) {
                int x = min(i, min(j, n-j+1));
                res[x] += a[i][j] + a[u][v];
            }
        if (n%2) {
            k++;
            FOR (j, 1, n)
                res[min(j, n-j+1)] += a[k][j];
        }
        printf("Case %d:", ++Case);
        FOR (i, 1, k) printf(" %d", res[i]);
        printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
