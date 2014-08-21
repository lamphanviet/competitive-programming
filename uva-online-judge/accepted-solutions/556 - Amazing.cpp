//*****************
// LAM PHAN VIET **
// UVA 556 - Amazing
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
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 1001
using namespace std;

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };
int n, m, num_move[maxN][maxN];
char s[maxN][maxN];

bool isInside(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void move(int x, int y, int k) {
    if (x==n-1 && y==0 && num_move[x][y]) return;
    int kk = (k + 1)%4;
    int xx = x + dx[kk], yy = y + dy[kk];
    if (isInside(xx, yy) && s[xx][yy]=='0') {
        num_move[x][y]++;
        move(xx, yy, kk);   // turn right
    }
    else {
        xx = x + dx[k], yy = y + dy[k];
        if (!isInside(xx, yy) || s[xx][yy]=='1')
            move(x, y, (k + 3)%4);  // turn left
        else {
            num_move[x][y]++;
            move(x + dx[k], y + dy[k], k);  // foward
        }
    }
}

main() {
//    FileIn("test"); FileOut("test");
    while (scanf(" %d %d ", &n, &m) && (n || m)) {
        REP(i, n) {
            gets(s[i]);
            REP(j, m) num_move[i][j] = 0;
        }
        move(n - 1, 0, 1);
        int res[5];
        REP(i, 5) res[i] = 0;
        REP(i, n)
            REP(j, m)
                if (s[i][j]=='0') res[num_move[i][j]]++;
                
        REP(i, 5) printf("%3d", res[i]);
        puts("");
    }
}

/* lamphanviet@gmail.com - 2011 */
