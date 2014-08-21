//*****************
// LAM PHAN VIET **
// UVA 11581 - Grid Successors
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
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 6
#define maxM 520
using namespace std;

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };
int a[maxN][maxN], b[maxN][maxN];
bool Free[maxM];

int getValue(int a[maxN][maxN]) {
    int res = 0;
    FOR (i, 1, 3)
        FOR (j, 1, 3)
            res = (res << 1) + a[i][j];
    return res;
}

int change(int a[maxN][maxN], int b[maxN][maxN]) {
    FOR (i, 1, 3)
        FOR (j, 1, 3) {
            b[i][j] = 0;
            REP(k, 4)
                b[i][j] += a[i + dx[k]][j + dy[k]];
            b[i][j] %= 2;
        }
    return getValue(b);
}

int solve() {
    if (!getValue(a)) return -1;
    int res = 0, val;
    Fill(Free, true);
    Free[getValue(a)] = false;
    while (1) {
        res++;
        if (res % 2) val = change(a, b);
        else val = change(b, a);
        
        if (!Free[val]) break;
        Free[val] = false;
    }
    return res - 2;
}

main() {
//    FileIn("test"); FileOut("test");
    int Case;
    char s[maxN][maxN];
    REP(i, 5)
        REP(j, 5) a[i][j] = b[i][j] = 0;
    for (scanf(" %d ", &Case); Case--; ) {
        scanf(" ");
        REP(i, 3) {
            gets(s[i]);
            REP(j, 3)
                a[i+1][j+1] = b[i+1][j+1] = s[i][j] - 48;
        }
        printf("%d\n", solve());
    }
}

/* lamphanviet@gmail.com - 2011 */
