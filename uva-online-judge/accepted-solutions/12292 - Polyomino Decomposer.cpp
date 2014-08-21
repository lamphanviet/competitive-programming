//=============================//
// Author: LAM PHAN VIET       //
// Online Judge: UVa
// Problem: 12292 - Polyomino Decomposer
// Time limit: 3.000s
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
#define maxN 12
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };
int n;
char s[maxN][maxN];
vii ps, p;
bool solved;

bool isInside(int x, int y, const int &n, const int &m) { return (0 <= x && x < n && 0 <= y && y < m); }

void result(int size) {
 //   REP(i, size) printf("solved %d %d\n", p[i].A, p[i].B);
    char ch = 'A';
    REP(i, n)
        REP(j, n)
            if (s[i][j] == '*') {
                REP(k, size)
                    s[i + p[k].A][j + p[k].B] = ch;
                ch++;
            }
    REP(i, n) {
        REP(j, n) putchar(s[i][j]);
        putchar('\n');
    }
}

bool accept(int size) {
    int n = 0, m = 0, x_min = INF, y_min = INF;
    REP(i, size) {
        n = max(p[i].A, n), m = max(p[i].B, m);
        x_min = min(x_min, p[i].A);
        y_min = min(y_min, p[i].B);
    }
    n = n - x_min + 1;
    m = m - y_min + 1;
    char tmp[n][m];
    fill(tmp, '.');
    for (int i = 1; i < size; i++)
        tmp[p[i].A - x_min][p[i].B - y_min] = '*';
    int x, y, xx, yy;
    queue<ii> Q;
    Q.push(ii(p[0].A - x_min, p[0].B - y_min));
    while (!Q.empty()) {
        x = Q.front().A;
        y = Q.front().B; Q.pop();
        REP(i, 4) {
            xx = x + dx[i];
            yy = y + dy[i];
            if (isInside(xx, yy, n, m) && tmp[xx][yy] == '*') {
                tmp[xx][yy] = '.';
                Q.push(ii(xx, yy));
            }
        }
    }
    REP(i, n) REP(j, m)
        if (tmp[i][j] == '*') return false;
    return true;
}

void check(int size) {
    if (!accept(size)) return;
    char tmp[maxN][maxN];
    memcpy(tmp, s, sizeof(s));
    int x, y;
    REP(i, n) REP(j, n)
        if (tmp[i][j] == '*')
            REP(k, size) {
                x = i + p[k].A;
                y = j + p[k].B;
                if (!isInside(x, y, n, n) || tmp[x][y] != '*')
                    return;
                tmp[x][y] = '.';
            }
    REP(i, n) REP(j, n)
        if (tmp[i][j] == '*') return;
    result(size);
    solved = true;
}

void trySolve(int size, int k, int Count) {
    if (solved) return;
    if (Count >= 2) {
        if (p[Count - 2].A + 1 < ps[k].A) return;
   //     if (p[Count - 1].A == p[k].A && p[Count - 1].B + 1 < p[k].B) return;
    }
    p[Count - 1] = ps[k];
    if (Count == size) {
        check(size);
        return;
    }
    Count++;
    for (int i = k + 1; i < ps.size(); i++) {
        if (solved) return;
        trySolve(size, i, Count);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); outFile("test.out");
    #endif
    while (scanf("%d ", &n) != EOF && n) {
        solved = false;
        ps.clear();
        REP(i, n) {
            gets(s[i]);
            REP(j, n) if (s[i][j] == '*')
                ps.pb(ii(i, j));
        }
        for (int i = 1; i < ps.size(); i++)
            ps[i].A -= ps[0].A, ps[i].B -= ps[0].B;
        ps[0].A = ps[0].B = 0;
        p.resize(ps.size());
        for (int i = ps.size() / 2; i >= 1; i--)
            if (ps.size() % i == 0) {
                trySolve(i, 0, 1);
                if (solved) break;
            }
        if (!solved) {
            char ch = 'A';
            REP(i, n) {
                REP(j, n)
                    if (s[i][j] == '*') putchar(ch++);
                    else putchar('.');
                putchar('\n');
            }
        }
        putchar('\n');
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
