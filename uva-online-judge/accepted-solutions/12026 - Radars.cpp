//*****************
// LAM PHAN VIET **
// UVA 12026 - Radars
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
#define REP(i, a, b) for (int i=a; i<=b; i++)
#define REP0(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) (i & -i)
#define Parent(i) (i - Last(i))
#define INF 500000000
#define maxN 1001
#define maxM 1000000
using namespace std;

const int dx[] = { 0, 1, -1, 0 };
const int dy[] = { 1, 0, 0, -1 };
int n, m, nr, a[maxN][maxN];
int x[maxM], y[maxM], Rx[maxM], Ry[maxM];
double d[maxM];
bool Free[maxM];

double Distance(int i, int j) {
    double a = x[i]-Rx[j];
    double b = y[i]-Ry[j];
    return sqrt(a*a + b*b);
}

bool isOK(int x, int y) {
    return (x>=1 && x<=n && y>=1 && y<=n);
}

double Mean(int i, int j) {
    double Count = 0, Sum = 0;
    REP0 (k, 4)
        if (isOK(i+dx[k], j+dy[k])) {
            Count++;
            Sum += a[i+dx[k]][j+dy[k]];
        }
    return Sum/Count;
}

void Solve() {
    memset(Free, true, m+1);
    REP0 (i, m) {
        REP0 (j, nr)
            if (Distance(i, j) <= d[j]) {
                Free[i] = false;
                break;
            }
    }
    int Count = 0;
    REP0 (i, m)
        if (Free[i]) Count++;
    printf("%d\n", Count);
}

main() {
 //   FileIn("test"); FileOut("test");
    int Case;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d", &n);
        m = nr = 0;
        REP (i, 1, n)
            REP (j, 1, n) {
                scanf("%d", &a[i][j]);
                if (a[i][j]) {
                    x[m] = i; y[m++] = j;
                }
            }
        REP (i, 1, n)
            REP (j, 1, n)
                if (!a[i][j]) {
                    d[nr] = Mean(i, j);
                    if (d[nr]<1) continue;
                    Rx[nr] = i; Ry[nr++] = j;
                }
        Solve();
    }
}

/* lamphanviet@gmail.com - 2011 */
