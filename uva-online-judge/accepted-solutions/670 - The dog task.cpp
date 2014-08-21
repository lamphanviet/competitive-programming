//*****************
// LAM PHAN VIET **
// UVA 670 - The dog task
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
#define maxN 101
using namespace std;

struct Point {
    int x, y;
};
int n, m, Trace[maxN];
int mX[maxN], mY[maxN];
Point b[maxN], d[maxN];
bool cnt[maxN][maxN];

double Distance(Point p, Point q) {
    double a = p.x - q.x;
    double b = p.y - q.y;
    return sqrt(a*a + b*b);
}

int FindPath() {
    FOR (j, 1, m) Trace[j] = 0;
    queue<int> Q;
    FOR (i, 1, n-1)
        if (mX[i]==0) Q.push(i);
    while (!Q.empty()) {
        int i = Q.front(); Q.pop();
        FOR (j, 1, m)
            if (cnt[i][j] && Trace[j]==0) {
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
    FOR (i, 1, n-1) {
        double dis = Distance(b[i], b[i+1]) * 2.0;
        FOR (j, 1, m) {
            double tmp = Distance(b[i], d[j]) + Distance(d[j], b[i+1]);
            cnt[i][j] = (dis >= tmp);
        }
    }

    int finish;
    do {
        finish = FindPath();
        if (finish) Enlarge(finish);
    } while (finish);
}

void Result() {
    vector<Point> res;
    res.pb(b[1]);
    FOR (i, 1, n-1) {
        if (mX[i]) res.pb(d[mX[i]]);
        res.pb(b[i+1]);
    }
    printf("%d\n", res.size());
    printf("%d %d", res[0].x, res[0].y);
    FOR (i, 1, res.size()-1)
        printf(" %d %d", res[i].x, res[i].y);
    printf("\n");
}

main() {
//    FileIn("test"); FileOut("test");
    int Case;
    for (scanf("%d", &Case); Case--; ) {
        scanf("%d %d", &n, &m);
        FOR (i, 1, n) {
            scanf("%d %d", &b[i].x, &b[i].y);
            mX[i] = 0;
        }
        FOR (i, 1, m) {
            scanf("%d %d", &d[i].x, &d[i].y);
            mY[i] = 0;
        }
        Solve();
        Result();
        if (Case) printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
