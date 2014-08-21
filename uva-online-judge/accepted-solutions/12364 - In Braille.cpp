//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : UVa
// Problem Name : 12364 - In Braille
// Time Limit   : 1.000s
// Description  : Ad hoc
//============================================================================
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
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define ff first
#define ss second
#define bit(n) (1<<(n))
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 110
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n;
char s[maxN], a[4][maxN * 4];
char num[10][3][2];

void preCal() {
    REP(i, 10) REP(j, 3) REP(k, 2) num[i][j][k] = '.';
    num[1][0][0] = '*';
    num[2][0][0] = num[2][1][0] = '*';
    num[3][0][0] = num[3][0][1] = '*';
    num[4][0][0] = num[4][0][1] = num[4][1][1] = '*';
    num[5][0][0] = num[5][1][1] = '*';
    num[6][0][0] = num[6][0][1] = num[6][1][0] = '*';
    num[7][0][0] = num[7][0][1] = num[7][1][0] = num[7][1][1] = '*';
    num[8][0][0] = num[8][1][0] = num[8][1][1] = '*';
    num[9][1][0] = num[9][0][1] = '*';
    num[0][1][0] = num[0][0][1] = num[0][1][1] = '*';
}

char getDigit(int x, int y) {
    REP(d, 10) {
        bool ok = true;
        REP(i, 3) {
            REP(j, 2)
                if (num[d][i][j] != a[x + i][y + j]) {
                    ok = false;
                    break;
                }
            if (!ok) break;
        }
        if (ok) return d + 48;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); outFile("test.out");
    #endif
    char tmp[10];
    preCal();
    while (scanf("%d ", &n) != EOF && n) {
        scanf(" %s ", &tmp);
        if (tmp[0] == 'S') {
            gets(s);
            REP(i, 3) {
                REP(j, n) {
                    if (j) putchar(' ');
                    int id = s[j] - 48;
                    printf("%c%c", num[id][i][0], num[id][i][1]);
                }
                putchar('\n');
            }
        }
        else {
            REP(i, 3) gets(a[i]);
            REP(i, n) putchar(getDigit(0, i * 3));
            putchar('\n');
        }
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
