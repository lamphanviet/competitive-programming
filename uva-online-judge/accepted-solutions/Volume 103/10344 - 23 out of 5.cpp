//*****************
// LAM PHAN VIET **
// UVA 10344 - 23 out of 5
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
#define maxN 7
using namespace std;

const int n = 5;
int a[maxN];
bool flag[maxN], solved;

bool readinput() {
    FOR (i, 1, n) scanf("%d", &a[i]);
    FOR (i, 1, n)
        if (a[i]) return true;
    return false;
}

void back_tracking(int res, int k) {
    if (solved) return;
    if (res == 23 && k > n) {
        solved = true;
        return;
    }
    
    FOR (i, 1, n)
        if (flag[i]) {
            flag[i] = false;
            back_tracking(res + a[i], k + 1);
            back_tracking(res - a[i], k + 1);
            back_tracking(res * a[i], k + 1);
            flag[i] = true;
        }
}

main() {
//    FileIn("test"); FileOut("test");
    while (readinput()) {
        solved = false;
        Fill(flag, true);
        FOR (i, 1, n) {
            flag[i] = false;
            back_tracking(a[i], 2);
            flag[i] = true;
            if (solved) break;
        }
        if (solved) puts("Possible");
        else puts("Impossible");
    }
}

/* lamphanviet@gmail.com - 2011 */
