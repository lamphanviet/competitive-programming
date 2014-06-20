/*****************/
/* LAM PHAN VIET */
/* UVa: 526 - String Distance and Transform Process
/* Time limit: 3.000s
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

#define InpFile(f) freopen(f, "r", stdin)
#define OutFile(f) freopen(f, "w", stdout)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORR(i, a, b) for (int i = a; i < b; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 100
using namespace std;

int n, m, f[maxN][maxN];
string x, y;

void solve_dp() {
    FOR (i, 0, n) f[i][0] = i;
    FOR (j, 0, m) f[0][j] = j;
    FOR (i, 1, n)
        FOR (j, 1, m)
            if (x[i - 1] == y[j - 1])
                f[i][j] = f[i - 1][j - 1];
            else
                f[i][j] = min(f[i - 1][j], min(f[i - 1][j - 1], f[i][j - 1])) + 1;
}

void result_trace() {
    printf("%d\n", f[n][m]);
    int step = 0, i = n, j = m;
    while (i || j) {
        if (x[i - 1] == y[j - 1]) {
            i--, j--;
            continue;
        }
        printf("%d ", ++step);
        if (i > 0 && f[i][j] == f[i - 1][j] + 1) { // delete
            printf("Delete %d", i);
            x.erase(i - 1, 1);
            i--;
        }
        else if (j > 0 && f[i][j] == f[i][j - 1] + 1) { // insert
            printf("Insert %d,%c", i + 1, y[j - 1]);
            x.insert(i, 1, y[j - 1]);
            j--;
        }
        else if (i > 0 && j > 0) {  // replace
            printf("Replace %d,%c", i, y[j - 1]);
            x[i - 1] = y[j - 1];
            i--, j--;
        }
        putchar('\n');
    }
}

main() {
//    InpFile("test.inp"); OutFile("test.out");
    char str[maxN];
    bool blank_line = false;
    while (gets(str)) {
        x = str;
        getline(cin, y);
        n = x.length(); m = y.length();
        solve_dp();
        if (blank_line) putchar('\n'); blank_line = true;
        result_trace();
    }
}

/* lamphanviet@gmail.com - 2011 */
