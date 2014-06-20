//*****************
// LAM PHAN VIET **
// UVA 926 - Walking Around Wisely
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
#define Parent(i) (i - Last(i))
#define INF 500000000
#define maxN 33
using namespace std;

int n, sx, sy, fx, fy;
uint64 d[maxN][maxN];
bool a[maxN][maxN][5];

bool isOK(int x, int y) {
    return (x>=1 && x<=n && y>=1 && y<=n);
}

void ReadInput() {
    scanf("%d", &n);
    scanf("%d %d %d %d", &sx, &sy, &fx, &fy);
    swap(sx, sy); swap(fx, fy);
    Fill(a, true);
    int m, x, y;
    char ch;
    scanf("%d", &m);
    while (m--) {
        scanf("%d %d %c", &x, &y, &ch);
        swap(x, y);
        if (ch=='N') a[x][y][1] = false;
        else if (ch=='S') a[x-1][y][1] = false;
        else if (ch=='W') a[x][y-1][4] = false;
        else a[x][y][4] = false;
    }
}

void Solve() {
    Fill(d, 0);
    d[sx][sy] = 1;
    REP (i, sx, fx)
        REP (j, sy, fy) {
            if (a[i][j][1] && isOK(i+1, j)) d[i+1][j] += d[i][j];
            if (a[i][j][4] && isOK(i, j+1)) d[i][j+1] += d[i][j];
        }
    printf("%lld\n", d[fx][fy]);
}

main() {
//    FileIn("test"); FileOut("test");
    int Case;
    scanf("%d", &Case);
    while (Case--) {
        ReadInput();
        Solve();
    }
}

/* lamphanviet@gmail.com - 2011 */
