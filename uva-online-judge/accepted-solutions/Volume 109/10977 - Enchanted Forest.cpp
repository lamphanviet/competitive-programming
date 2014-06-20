//*****************
// LAM PHAN VIET **
// UVA 10977 - Enchanted Forest
// Time limit: 3.000s
//********************************
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
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
#define maxN 205
using namespace std;

class Point {
public:
    int x, y;
    Point() {}
    Point(int xx, int yy) {
        x = xx; y = yy;
    }
};
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };
int n, m, d[maxN][maxN], l[maxN];
bool Free[maxN][maxN];
Point p[maxN];

int getDistance(int x1, int y1, int x2, int y2) {
    x1 -= x2; y1 -= y2;
    return (x1 * x1 + y1 * y1);
}

bool bfs() {
    queue<Point> Q;
    Q.push(Point(1, 1));
    d[1][1] = 0;
    if (!Free[1][1]) return false;
    Free[1][1] = false;
    while(!Q.empty()) {
        int x = Q.front().x, y = Q.front().y; Q.pop();
        if (x==n && y==m) return true;
        REP(i, 4) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && Free[xx][yy]) {
                Free[xx][yy] = false;
                d[xx][yy] = d[x][y] + 1;
                Q.push(Point(xx, yy));
            }
        }
    }
    return false;
}

main() {
//    FileIn("test"); FileOut("test");
    int k, x, y;
    while (scanf("%d %d", &n, &m) && (n || m)) {
        FOR (i, 1, n)
            memset(Free[i], true, m + 1);
        scanf("%d", &k);
        while (k--) {
            scanf("%d %d", &x, &y);
            Free[x][y] = false;
        }
        scanf("%d", &k);
        REP (i, k) {
            scanf("%d %d %d", &p[i].x, &p[i].y, &l[i]);
            l[i] *= l[i];
        }
        FOR (i, 1, n)
            FOR (j, 1, m) {
                if (Free[i][j]) {
                    REP (t, k)
                        if (getDistance(i, j, p[t].x, p[t].y) <= l[t]) {
                            Free[i][j] = false;
                            break;
                        }
                }
                d[i][j] = INF;
            }
        if (bfs()) printf("%d\n", d[n][m]);
        else puts("Impossible.");
    }
}

/* lamphanviet@gmail.com - 2011 */
