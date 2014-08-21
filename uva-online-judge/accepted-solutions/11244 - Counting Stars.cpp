//*****************
// LAM PHAN VIET **
// UVA 11244 - Counting Stars
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
#define Last(i) (i & -i)
#define INF 500000000
#define maxN 105
using namespace std;

const int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
const int dy[] = {0, -1, 1, 0, -1, 1, -1, 1};
int n, m;
char s[maxN][maxN];

int Visit(int x, int y) {
    if (x<0 || x>=n || y<0 || y>=m || s[x][y]!='*') return 0;
    s[x][y] = '.';
    int Count = 1;
    REP (i, 8)
        Count += Visit(x + dx[i], y + dy[i]);
    return Count;
}

main() {
//    FileIn("test"); FileOut("test");
    while (scanf("%d %d", &n, &m) && (n || m)) {
        gets(s[0]);
        REP (i, n) gets(s[i]);
        int res = 0;
        REP (i, n)
            REP (j, m)
                if (s[i][j]=='*') {
                    int Count = Visit(i, j);
                    if (Count==1) res++;
                }
        printf("%d\n", res);
    }
}

/* lamphanviet@gmail.com - 2011 */
