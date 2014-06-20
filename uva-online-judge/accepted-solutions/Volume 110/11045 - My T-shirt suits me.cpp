//*****************
// LAM PHAN VIET **
// UVA 11045 - My T-shirt suits me
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
#define maxN 40
using namespace std;

int n, m, adj[maxN][2];
int mX[maxN], mY[maxN], Trace[maxN];

int Convert(char s[]) {
    if (s[0]=='L') return 1;
    if (s[0]=='M') return 2;
    if (s[0]=='S') return 3;
    if (s[1]=='S') return 4;
    if (s[1]=='L') return 5;
    return 6;
}

int FindAugmentingPath() {
    FOR (i, 1, n) Trace[i] = 0;
    queue<int> Q;
    FOR (i, 1, m)
        if (mX[i]==0) Q.push(i);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        REP (i, 2) {
            int v = adj[u][i];
            while (v<=n) {
                if (!Trace[v]) {
                    Trace[v] = u;
                    if (mY[v]==0) return v;
                    Q.push(mY[v]);
                }
                v += 6;
            }
        }
    }
    return 0;
}

void Enlarge(int f) {
    int x, next;
    do {
        x = Trace[f];
        next = mX[x];
        mX[x] = f;
        mY[f] = x;
        f = next;
    } while (f);
}

bool Solve() {
    REP (i, maxN) mX[i] = mY[i] = 0;
    int finish = 0;
    do {
        finish = FindAugmentingPath();
        if (finish) Enlarge(finish);
    } while (finish);
    FOR (i, 1, m)
        if (!mX[i]) return false;
    return true;
}

main() {
//    FileIn("test"); FileOut("test");
    int Case;
    char a[10], b[10];
    for (scanf("%d", &Case); Case--; ) {
        scanf("%d %d", &n, &m);
        FOR (i, 1, m) {
            scanf(" %s %s", &a, &b);
            adj[i][0] = Convert(a);
            adj[i][1] = Convert(b);
        }
        if (Solve()) puts("YES");
        else puts("NO");
    }
}

/* lamphanviet@gmail.com - 2011 */
