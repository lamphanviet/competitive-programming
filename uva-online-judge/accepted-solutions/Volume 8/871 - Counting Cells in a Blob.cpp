//*****************
// LAM PHAN VIET **
// UVA 871 - Counting Cells in a Blob
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
#define maxN 30
using namespace std;

const int dx[] = {0, 0, -1, 1, 1, 1, -1, -1};
const int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
int n, m;
char s[maxN][maxN];

int Visit(int x, int y) {
    if (x<0 || x>=n || y<0 || y>=m || s[x][y]!='1') return 0;
    s[x][y] = '0';
    int Count = 1;
    REP (i, 8)
        Count += Visit(x + dx[i], y + dy[i]);
    return Count;
}

main() {
//    FileIn("test"); FileOut("test");
    int Case;
    scanf("%d", &Case); gets(s[0]); gets(s[0]);
    while (Case--) {
        n = 0;
        while (gets(s[n]) && s[n][0]!='\0') n++;
        m = strlen(s[0]);
        int Max = 0;
        REP (i, n)
            REP (j, m)
                if (s[i][j]=='1')
                    Max = max(Max, Visit(i, j));
        printf("%d\n", Max);
        if (Case) printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
