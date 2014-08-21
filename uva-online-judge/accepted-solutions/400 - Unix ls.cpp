/*****************/
/* LAM PHAN VIET */
/* UVA 400 - Unix ls
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
#define maxN 150
using namespace std;

int n, len[maxN], len_max;
string s[maxN];

main() {
//    FileIn("test"); FileOut("test");
    while (scanf(" %d ", &n) != EOF) {
        REP(i, n) cin >> s[i];
        sort(s, s + n);
        len_max = 0;
        REP(i, n) {
            len[i] = s[i].length();
            len_max = max(len[i], len_max);
        }
        int col = (60 + 2) /  (len_max + 2);
        int row = (int)ceil(n / (double)col);
        int width = len_max + 2;
        
        REP(i, 60) putchar('-');
        putchar('\n');
        REP(i, row) {
            for (int j = i; j < n; j += row) {
                cout << s[j];
                if (j + row < n) {
                    while (len[j]++ < width)
                        putchar(' ');
                }
            }
            putchar('\n');
        }
    }
}

/* lamphanviet@gmail.com - 2011 */
