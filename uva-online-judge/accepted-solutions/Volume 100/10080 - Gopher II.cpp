//*****************
// LAM PHAN VIET **
// UVA 10080 - Gopher II
// Time limit: 3.000s
//********************************
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
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
#define maxN 102
using namespace std;

int n, m, mX[maxN], mY[maxN], Trace[maxN];
double s, v, gx[maxN], gy[maxN], hx[maxN], hy[maxN];
bool cnt[maxN][maxN];

bool isConnect(int i, int j) {
    double a = gx[i] - hx[j];
    double b = gy[i] - hy[j];
    return (sqrt(a*a + b*b) <= s);
}

int FindAugmentingPath() {
    FOR (j, 1, m) Trace[j] = 0;
    queue<int> Q;
    FOR (i, 1, n)
        if (mX[i]==0) Q.push(i);
    while (!Q.empty()) {
        int i = Q.front(); Q.pop();
        FOR (j, 1, m)
            if (Trace[j]==0 && cnt[i][j]) {
                Trace[j] = i;
                if (mY[j]==0) return j;
                Q.push(mY[j]);
            }
    }
    return 0;
}

void Enlarge(int f) {
    int x, next;
    while (f) {
        x = Trace[f];
        next = mX[x];
        mX[x] = f;
        mY[f] = x;
        f = next;
    }
}

void Solve() {
    int finish;
    do {
        finish = FindAugmentingPath();
        if (finish) Enlarge(finish);
    } while (finish);
}

main() {
//    FileIn("test"); FileOut("test");
    while (scanf("%d %d %lf %lf", &n, &m, &s, &v)!=EOF) {
        s *= v;
        FOR (i, 1, n) {
            scanf("%lf %lf", &gx[i], &gy[i]);
            mX[i] = 0;
        }
        FOR (j, 1, m) {
            mY[j] = 0;
            scanf("%lf %lf", &hx[j], &hy[j]);
            FOR (i, 1, n) cnt[i][j] = isConnect(i, j);
        }
        Solve();
        int Count = 0;
        FOR (i, 1, n)
            if (mX[i]==0) Count++;
        printf("%d\n", Count);
    }
}

/* lamphanviet@gmail.com - 2011 */
