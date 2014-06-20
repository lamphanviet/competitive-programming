//*****************
// LAM PHAN VIET **
// UVA 11561 - Getting Gold
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
#define INF 500000000
#define maxN 55
using namespace std;

const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };
int n, m, count_gold;
char s[maxN][maxN];

bool is_inside(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs(int x, int y) {
    if (!is_inside(x, y) || s[x][y] == '#') return;
    if (s[x][y] == 'g') {
        s[x][y] = '#';
        count_gold++;
        return;
    }
    if (s[x][y] == 'G') count_gold++;
    s[x][y] = '#';
    REP(i, 4)
        dfs(x + dx[i], y + dy[i]);
}

main() {
//    FileIn("test"); FileOut("test");
    int x, y;
    while (scanf("%d %d ", &m, &n)!=EOF) {
        REP(i, n) {
            gets(s[i]);
            REP(j, m)
                if (s[i][j] == 'P')
                    x = i, y = j;
        }
        REP(i, n)
            REP(j, m)
                if (s[i][j] == 'T') {
                    REP(k, 4) {
                        int x = i + dx[k], y = j + dy[k];
                        if (!is_inside(x, y)) continue;
                        if (s[x][y] == 'G') s[x][y] = 'g';
                        else if (s[x][y] != 'g' && s[x][y] != 'T') s[x][y] = '#';
                    }
                    s[i][j] = '#';
                }
        count_gold = 0;
        dfs(x, y);
        printf("%d\n", count_gold);
    }
}

/* lamphanviet@gmail.com - 2011 */
