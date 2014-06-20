/*****************/
/* LAM PHAN VIET */
/* UVA 216 - Getting in Line
/* Time limit: 3.000s
/********************************/
#include <algorithm>
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
#define maxN 10
using namespace std;

int n, x[maxN], y[maxN];
double d[maxN][maxN], length_min;
int res[maxN], b[maxN];
bool flag[maxN];

double Distance(int i, int j) {
    double a = x[i] - x[j];
    double b = y[i] - y[j];
    return sqrt(a*a + b*b);
}

void back_tracking(int u, int k, double length) {
    if (k > n) {
        if (length < length_min) {
            FOR (i, 1, n)
                res[i] = b[i];
            length_min = length;
        }
        return;
    }
    
    FOR (v, 1, n)
        if (flag[v]) {
            flag[v] = false;
            b[k] = v;
            back_tracking(v, k + 1, length + d[u][v]);
            flag[v] = true;
        }
}

void result(int &Case) {
    puts("**********************************************************");
    printf("Network #%d\n", ++Case);
    FOR (i, 2, n) {
        int i1 = res[i-1], i2 = res[i];
        printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", x[i1], y[i1], x[i2], y[i2], d[i1][i2]);
    }
    printf("Number of feet of cable required is %.2lf.\n", length_min);
}

main() {
//    FileIn("test"); FileOut("test");
    int Case = 0;
    while (scanf("%d", &n) && n) {
        FOR (i, 1, n) {
            scanf("%d %d", &x[i], &y[i]);
            FOR (j, 1, i-1)
                d[i][j] = d[j][i] = Distance(i, j) + 16.;
            d[i][i] = 0;
        }
        length_min = INF;
        Fill(flag, true);
        FOR (i, 1, n) {
            flag[i] = false;
            b[1] = i;
            back_tracking(i, 2, 0);
            flag[i] = true;
        }
        result(Case);
    }
}

/* lamphanviet@gmail.com - 2011 */
