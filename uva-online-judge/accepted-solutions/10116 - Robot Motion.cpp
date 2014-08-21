//*****************
// LAM PHAN VIET **
// UVA 10116 - Robot Motion
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
#define maxN 1001
using namespace std;

int n, m, x_start = 1, y_start;
bool finish;
char s[maxN][maxN];
int d[maxN][maxN];

void dfs(int x, int y, int step) {
    if (x < 0 || x >= n || y < 0 || y >= m)
        printf("%d step(s) to exit\n", step - 1);
    else if (d[x][y])
        printf("%d step(s) before a loop of %d step(s)\n", d[x][y] - 1, step - d[x][y]);
    else {
        d[x][y] = step;
        switch (s[x][y]) {
            case 'S': dfs(x + 1, y, step + 1); break; 
            case 'N': dfs(x - 1, y, step + 1); break;
            case 'E': dfs(x, y + 1, step + 1); break;
            case 'W': dfs(x, y - 1, step + 1); break;
        }
    }
}

main() {
//    FileIn("test"); FileOut("test");
    while (scanf("%d %d %d", &n, &m, &y_start)!=EOF) {
        if (!n && !m && !y_start) break;
        scanf(" ");
        REP(i, n) {
            gets(s[i]);
            REP(j, m)
                d[i][j] = 0;
        }
        finish = false;
        dfs(x_start-1, y_start-1, 1);
    }
}

/* lamphanviet@gmail.com - 2011 */
