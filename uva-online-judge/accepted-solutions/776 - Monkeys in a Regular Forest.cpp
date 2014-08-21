//*****************
// LAM PHAN VIET **
// UVA 776 - Monkeys in a Regular Forest
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
#define Last(i) (i & -i)
#define INF 500000000
#define maxN 1001
using namespace std;

const int dx[] = {0, 0, -1, -1, -1, 1, 1, 1 };
const int dy[] = {-2, 2, 0, -2, 2, 0, -2, 2};
int n, m, len, a[maxN][maxN], d[maxN];
char s[maxN][maxN*2];

void FillM(int i, int j, int val, char ch) {
    if (i<0 || i>=n || j<0 || j>=len || s[i][j]!=ch) return;
    s[i][j] = '*';
    a[i][j/2] = val;
    REP (k, 8)
        FillM(i + dx[k], j + dy[k], val, ch);
}

int Cal(int j) {
    int Max = 1;
    REP (i, n)
        while (Max <= a[i][j]) Max *= 10;
    return Max/10;
}

main() {
//    FileIn("test"); FileOut("test");
    int Count;
    while (gets(s[0])) {
        n = 1;
        while (gets(s[n]))
            if (s[n][0]=='%') break;
            else n++;
        len = strlen(s[0]);
        m = (len + 1)/2;
        Count = 0;
        REP (i, n)
            for (int j=0; j<len; j+=2)
                if (s[i][j]!='*') FillM(i, j, ++Count, s[i][j]);
        REP (j, m) d[j] = Cal(j);
        REP (i, n) {
            REP (j, m) {
                int k = d[j];
                while (k>1) {
                    if (k > a[i][j]) printf(" ");
                    else break;
                    k /= 10;
                }
                if (j) printf(" ");
                printf("%d", a[i][j]);
            }
            printf("\n");
        }
        puts("%");
    }
}

/* lamphanviet@gmail.com - 2011 */
