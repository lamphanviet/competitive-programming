//*****************
// LAM PHAN VIET **
// UVA 825 - Walking on the Safe Side
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
#define INF 500000000
#define maxN 1001
using namespace std;

int n, m;
int64 d[maxN][maxN];
bool a[maxN][maxN];

bool isOK(int x, int y) {
    return (x>=1 && x<=n && y>=1 && y<=m);
}

void Solve() {
    d[1][1] = 1;
    REP (i, 1, n)
        REP (j, 1, m) {
            if (isOK(i+1, j) && a[i+1][j]) d[i+1][j] += d[i][j];
            if (isOK(i, j+1) && a[i][j+1]) d[i][j+1] += d[i][j];
        }
    printf("%lld\n", d[n][m]);
}

main() {
//    FileIn("test"); FileOut("test");
    int Case, x, y;
    char s[maxN];
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d %d", &n, &m);
        REP (i, 1, n) {
            REP (j, 1, m) {
                a[i][j] = true; d[i][j] = 0;
            }
            scanf("%d", &x);
            gets(s);
            int len = strlen(s), k = 0;
            while (k<len) {
                while (k<len && s[k]==' ') k++;
                if (k<len) {
                    sscanf(s+k, "%d", &y);
                    a[x][y] = false;
                    while (k<len && s[k]!=' ') k++;
                }
            }
        }
        Solve();
        if (Case) printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
