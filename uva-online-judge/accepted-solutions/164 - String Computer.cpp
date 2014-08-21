/*****************/
/* LAM PHAN VIET */
/* UVa: 164 - String Computer
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
#define maxN 22
using namespace std;

int n, m, f[maxN][maxN];
string x, y;

void solve() {
    FOR (i, 0, n) f[i][0] = i;
    FOR (j, 0, m) f[0][j] = j;
    FOR (i, 1, n)
        FOR (j, 1, m)
            if (x[i - 1] == y[j - 1])
                f[i][j] = f[i - 1][j - 1];
            else
                f[i][j] = min(f[i - 1][j - 1], min(f[i][j - 1], f[i - 1][j])) + 1;
}

void result() {
    int i = n, j = m;
    while (i || j) {
        if (x[i - 1] == y[j - 1]) {
            i--, j--;
            continue;
        }
        if (j > 0 && f[i][j] == f[i][j - 1] + 1) {   // insert
            printf("I%c", y[j - 1]);
            if (i + 1 < 10) putchar('0');
            printf("%d", i + 1);
            x.insert(i, 1, y[j - 1]);
            j--;
        }
        else if ((i > 0 && j > 0) && f[i][j] == f[i - 1][j - 1] + 1) {  // replace
            printf("C%c", y[j - 1]);
            if (i < 10) putchar('0');
            printf("%d", i);
            x[i - 1] = y[j - 1];
            i--, j--;
        }
        else if (i > 0) { // f[i][j] == f[i - 1][j] + 1  ==> delete
            printf("D%c", x[i - 1]);
            if (i < 10) putchar('0');
            printf("%d", i);
            x.erase(i - 1, 1);
            i--;
        }
     //   cout << x << endl;
    }
    puts("E");
//    printf("%d\n", f[n][m]);
}

main() {
 //   InpFile("test.inp"); OutFile("test.out");
    while (cin >> x) {
        if (x[0] == '#') break;
        cin >> y;
        n = x.length();
        m = y.length();
        solve();
        result();
    }
}

/* lamphanviet@gmail.com - 2011 */
