//*****************
// LAM PHAN VIET **
// UVA 10377 - Maze Traversal
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
#define maxN 70
using namespace std;

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };
int n, m, x, y, direction;
char s[maxN][maxN];

void move() {
    int xx = x + dx[direction], yy = y + dy[direction];
    if (s[xx][yy] == '*') return;
    x = xx; y = yy;
}

main() {
//    FileIn("test"); FileOut("test");
    int Case;
    char command[1000];
    for (scanf("%d", &Case); Case--; ) {
        scanf("%d %d ", &n, &m);
        REP(i, n) gets(s[i]);
        scanf(" %d %d ", &x, &y);
        x--, y--;
        direction = 0;
        bool finish = false;
        while (gets(command)) {
            int c_length = strlen(command);
            if (!c_length) break;
            REP(i, c_length) {
                switch (command[i]) {
                    case 'R': direction = (direction + 1) % 4; break;
                    case 'L': direction = (direction + 3) % 4; break;
                    case 'F': move(); break;
                    case 'Q': finish = true; break;
                }
                if (finish) break;
            }
            if (finish) break;
        }
        printf("%d %d ", x + 1, y + 1);
        switch (direction) {
            case 0: puts("N"); break;
            case 1: puts("E"); break;
            case 2: puts("S"); break;
            case 3: puts("W"); break;
        }
        if (Case) printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
