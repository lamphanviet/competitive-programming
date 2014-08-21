/*****************/
/* LAM PHAN VIET */
/* UVA 10267 - Graphical Editor
/* Time limit: 5.000s
/********************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
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
#define maxN 255
using namespace std;

int n, m, len, k;
char table[maxN][maxN], color[5];

void commandI() {
    scanf("%d %d", &m, &n);
    FOR (i, 1, n)
        FOR (j, 1, m)
            table[i][j] = 'O';
}

void commandC() {
    FOR (i, 1, n)
        FOR (j, 1, m)
            table[i][j] = 'O';
}

void commandL() {
    int x, y;
    scanf("%d %d %s", &y, &x, &color);
    table[x][y] = color[0];
}

void commandV() {
    int x1, x2, y;
    scanf("%d %d %d %s", &y, &x1, &x2, &color);
    if (x1 > x2) swap(x1, x2);
    FOR (i, x1, x2)
        table[i][y] = color[0];
}

void commandH() {
    int x, y1, y2;
    scanf("%d %d %d %s", &y1, &y2, &x, &color);
    if (y1 > y2) swap(y1, y2);
    FOR (j, y1, y2)
        table[x][j] = color[0];
}

void commandK() {
    int x1, x2, y1, y2;
    scanf("%d %d %d %d %s", &y1, &x1, &y2, &x2, &color);
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    FOR (i, x1, x2)
        FOR (j, y1, y2)
            table[i][j] = color[0];
}

void fillF(int x, int y, char preClr, char clr) {
    if (x < 1 || x > n || y < 1 || y > m || table[x][y] != preClr) return;
    table[x][y] = clr;
    fillF(x - 1, y, preClr, clr);
    fillF(x + 1, y, preClr, clr);
    fillF(x, y - 1, preClr, clr);
    fillF(x, y + 1, preClr, clr);
}

void commandF() {
    int x, y;
    scanf("%d %d %s", &y, &x, &color);
    if (table[x][y] != color[0])
        fillF(x, y, table[x][y], color[0]);
}

void commandS() {
    char name[1000];
    scanf("%s", &name);
    printf("%s\n", name);
    FOR (i, 1, n) {
        FOR (j, 1, m)
            putchar(table[i][j]);
        putchar('\n');
    }
}

main() {
//    FileIn("test"); FileOut("test");
    char s[maxN];
    while (scanf("%s", &s) != EOF) {
        if (s[0] == 'X') break;
        switch (s[0]) {
            case 'I': commandI(); break;
            case 'C': commandC(); break;
            case 'L': commandL(); break;
            case 'V': commandV(); break;
            case 'H': commandH(); break;
            case 'K': commandK(); break;
            case 'F': commandF(); break;
            case 'S': commandS(); break;
            default: gets(s);
        }
    }
}

/* lamphanviet@gmail.com - 2011 */
