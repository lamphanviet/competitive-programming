//*****************
// LAM PHAN VIET **
// UVA 11094 - Continents
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
#define maxN 10000
using namespace std;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };
int n, m, count_regions;
char s[maxN][maxN];

void dfs(int x, int y, char ch) {
    if (x < 0 || x >= n || y < 0 || y >= m || s[x][y] != ch) return;
    s[x][y] = ' ';
    count_regions++;
    REP(i, 4) {
        int xx = x + dx[i], yy = y + dy[i];
        if (yy >= m) yy = 0;
        else if (yy < 0) yy = m - 1;
        dfs(xx, yy, ch);
    }
}

main() {
//    FileIn("test"); FileOut("test");
    int x, y;
    while (scanf("%d %d ", &n, &m)!=EOF) {
        REP(i, n) gets(s[i]);
        scanf("%d %d ", &x, &y);
        
        char ch = s[x][y];
        dfs(x, y, ch);
        int result = 0;
        REP(i, n)
            REP(j, m)
                if (s[i][j] == ch) {
                    count_regions = 0;
                    dfs(i, j, ch);
                    result = max(result, count_regions);
                }
        printf("%d\n", result);
    }
}

/* lamphanviet@gmail.com - 2011 */
