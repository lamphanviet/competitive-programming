//*****************
// LAM PHAN VIET **
// UVA 11418 - Clever Naming Patterns
// Time limit: 1.000s
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
#define maxN 30
using namespace std;

int n, Trace[maxN], TraceP[maxN];
int mX[maxN], mY[maxN], mYp[maxN];
vector<string> name[maxN];

int FindAugmentingPath() {
    FOR (i, 1, n) Trace[i] = 0;
    queue<int> Q;
    FOR (i, 1, n)
        if (mX[i]==0) Q.push(i);
    while (!Q.empty()) {
        int i = Q.front(); Q.pop();
        REP (k, name[i].size()) {
            int j = (int)(toupper(name[i][k][0]) - 64);
            if (Trace[j]==0) {
                Trace[j] = i;
                TraceP[j] = k;
                if (mY[j]==0) return j;
                Q.push(mY[j]);
            }
        }
    }
    return 0;
}

void Enlarge(int f) {
    int x, xp, next;
    while (f) {
        x = Trace[f];
        xp = TraceP[f];
        next = mX[x];
        mX[x] = f;
        mY[f] = x;
        mYp[f] = xp;
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
    int Case, k;
    scanf("%d", &Case);
    FOR (kk, 1, Case) {
        scanf("%d", &n);
        FOR (i, 1, n) {
            scanf("%d", &k);
            name[i].resize(k);
            REP (j, k) cin >> name[i][j];
            mX[i] = mY[i] = 0;
        }
        Solve();
        printf("Case #%d:\n", kk);
        FOR (j, 1, n) {
            int x = mY[j], y = mYp[j], len = name[x][y].length()-1;
            printf("%c", toupper(name[x][y][0]));
            FOR (i, 1, len) printf("%c", tolower(name[x][y][i]));
            printf("\n");
        }
    }
}

/* lamphanviet@gmail.com - 2011 */
