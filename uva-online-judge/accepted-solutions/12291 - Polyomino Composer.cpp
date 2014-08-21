//=============================//
// Author: LAM PHAN VIET       //
// Online Judge: UVa
// Problem: 12291 - Polyomino Composer
// Time limit: 1.000s
//=============================//
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define inpFile(f) freopen(f, "r", stdin)
#define outFile(f) freopen(f, "w", stdout)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define A first
#define B second
#define bit(n) (1<<(n))
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 15
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, m, r, c;
char s[maxN][maxN], a[maxN][maxN];

ii findFirst(char s[maxN][maxN], int n, int m) {
    REP(i, n) REP(j, m)
        if (s[i][j] == '*')
            return (ii(i, j));
    return ii(-1, -1);
}

bool isInside(int x, int y) { return (0 <= x && x < n && 0 <= y && y < m); }

bool solve() {
    vii p;
    ii fa = findFirst(a, r, c);
    REP(i, r) REP(j, c)
        if (a[i][j] == '*')
            p.pb(ii(i - fa.A, j - fa.B));
    int x, y;
    REP(i, n) REP(j, m)
        if (s[i][j] == '*')
            REP(k, p.size()) {
                x = i + p[k].A;
                y = j + p[k].B;
                if (!isInside(x, y) || s[x][y] != '*')
                    return false;
                s[x][y] = '.';
            }
    REP(i, n) REP(j, m)
        if (s[i][j] == '*') return false;
    return true;
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); outFile("test.out");
    #endif
    while (scanf("%d %d ", &n, &r) && (n || r)) {
        REP(i, n) gets(s[i]);
        REP(i, r) gets(a[i]);
        m = strlen(s[0]);
        c = strlen(a[0]);
        if (solve()) puts("1");
        else puts("0");
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
