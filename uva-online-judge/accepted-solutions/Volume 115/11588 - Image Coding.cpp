//*****************
// LAM PHAN VIET **
// UVA 11588 - Image Coding
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
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 30
using namespace std;

int n, m, a, b, region_size[maxN];
char s[maxN][maxN];

main() {
//    FileIn("test"); FileOut("test");
    int Case;
    scanf("%d", &Case);
    FOR (kk, 1, Case) {
        scanf("%d %d %d %d ", &n, &m, &a, &b);
        Fill(region_size, 0);
        REP(i, n) {
            gets(s[i]);
            REP(j, m)
                region_size[s[i][j] - 65]++;
        }
        int size_max = 0;
        REP(i, 26)
            size_max = max(size_max, region_size[i]);
        int res = 0;
        REP(i, 26)
            if (region_size[i] == size_max)
                res += region_size[i] * a;
            else
                res += region_size[i] * b;
        printf("Case %d: %d\n", kk, res);
    }
}

/* lamphanviet@gmail.com - 2011 */
