//*****************
// LAM PHAN VIET **
// UVA 167 - The Sultan's Successors
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
#define maxN 10
using namespace std;

const int n = 8;
int m, solution[92][maxN], x[maxN];
bool free_h[maxN], free_v1[maxN << 1], free_v2[maxN << 1];
int c[maxN][maxN];

void initialize() {
    Fill(free_h, true);
    Fill(free_v1, true);
    Fill(free_v2, true);
    m = 0;
}

void back_tracking(int j) {
    if (j > n) {
        FOR (i, 1, n)
            solution[m][i] = x[i];
        m++;
    }
    
    FOR (i, 1, n)
        if (free_h[i] && free_v1[i + j] && free_v2[i - j + n]) {
            free_h[i] = false;
            free_v1[i + j] = false;
            free_v2[i - j + n] = false;
            x[j] = i;
            back_tracking(j + 1);
            free_h[i] = true;
            free_v1[i + j] = true;
            free_v2[i - j + n] = true;
        }
}

main() {
//    FileIn("test"); FileOut("test");
    initialize();
    back_tracking(1);
    int Case;
    for (scanf("%d", &Case); Case--; ) {
        FOR (i, 1, n)
            FOR (j, 1, n)
                scanf("%d", &c[i][j]);
        int sum_max = 0;
        REP(i, m) {
            int sum_tmp = 0;
            FOR (j, 1, n)
                sum_tmp += c[solution[i][j]][j];
            sum_max = max(sum_tmp, sum_max);
        }
        printf("%5d\n", sum_max);
    }
}

/* lamphanviet@gmail.com - 2011 */
