/*****************/
/* LAM PHAN VIET */
/* UVA 10746 - Crime Wave - The Sequel
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
#define maxN 25
using namespace std;

int n, m, k, start, finish;
double c[maxN][maxN], fX[maxN], fY[maxN];;
int match_X[maxN], match_Y[maxN], trace[maxN];

void initialize() {
    k = max(n, m);
    FOR (i, 1, k) {
        match_X[i] = match_Y[i] = 0;
        fX[i] = fY[i] = 0;
        FOR (j, 1, k)
            c[i][j] = INF;
    }
}

double getC(int i, int j) {
    return c[i][j] - fX[i] - fY[j];
}

int find_path() {
    FOR (j, 1, k) trace[j] = 0;
    queue<int> Q;
    Q.push(start);
    while (!Q.empty()) {
        int i = Q.front(); Q.pop();
        FOR (j, 1, k)
            if (!trace[j] && (getC(i, j) <= 1e-7)) {
                trace[j] = i;
                if (!match_Y[j]) return j;
                Q.push(match_Y[j]);
            }
    }
    return 0;
}

void subX_addY() {
    bool vX[k + 1], vY[k + 1];
    Fill(vX, false);
    Fill(vY, false);
    vX[start] = true;
    FOR (j, 1, k)
        if (trace[j]) {
            vX[match_Y[j]] = true;
            vY[j] = true;
        }
    double delta = INF;
    FOR (i, 1, k)
        if (vX[i])
            FOR (j, 1, k)
                if (!vY[j])
                    delta = min(delta, getC(i, j));
    FOR (t, 1, k) {
        if (vX[t]) fX[t] += delta;
        if (vY[t]) fY[t] -= delta;
    }
}

void enlarge() {
    int i, next;
    while (finish) {
        i = trace[finish];
        next = match_X[i];
        match_X[i] = finish;
        match_Y[finish] = i;
        finish = next;
    }
}

void solve() {
    FOR (i, 1, k) {
        start = i; finish = 0;
        do {
            finish = find_path();
            if (!finish) subX_addY();
        } while (!finish);
        enlarge();
    }
    
    double res = 0;
    FOR (i, 1, n)
        res += c[i][match_X[i]];
    res /= n;
    printf("%.2lf\n", res);
}

main() {
//    FileIn("test"); FileOut("test");
    while (scanf("%d %d", &n, &m) && (n || m)) {
        initialize();
        FOR (i, 1, n)
            FOR (j, 1, m)
                scanf("%lf", &c[i][j]);
        solve();
    }
}

/* lamphanviet@gmail.com - 2011 */
