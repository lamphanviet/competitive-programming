//*****************
// LAM PHAN VIET **
// UVA 11085 - Back to the 8-Queens
// Time limit: 3.000s
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
int x[maxN];
int m, solution[100][maxN], rx[maxN];
bool hrz_free[maxN], ver1_free[maxN*2], ver2_free[maxN*2];

void back_tracking(int j) {
    if (j > n) {
        ++m;
        FOR (i, 1, n) solution[m][i] = rx[i];
        return;
    }
    
    FOR (i, 1, n)
        if (hrz_free[i] && ver1_free[i + j] && ver2_free[i - j + n]) {
            hrz_free[i] = false;
            ver1_free[i + j] = false;
            ver2_free[i - j + n] = false;
            
            rx[j] = i;
            back_tracking(j + 1);
            
            hrz_free[i] = true;
            ver1_free[i + j] = true;
            ver2_free[i - j + n] = true;
        }
}

void precal() {
    Fill(hrz_free, true);
    Fill(ver1_free, true);
    Fill(ver2_free, true);
    m = 0;
    back_tracking(1);
}

main() {
//    FileIn("test"); FileOut("test");
    precal();
    int Case = 0;
    while (scanf("%d", &x[1]) != EOF) {
        FOR (i, 2, n)
            scanf("%d", &x[i]);
        int res = INF;
        FOR (i, 1, m) {
            int tmp = 0;
            FOR (j, 1, n)
                if (solution[i][j] != x[j]) tmp++;
            res = min(tmp, res);
            if (!res) break;
        }
        printf("Case %d: %d\n", ++Case, res);
    }
}

/* lamphanviet@gmail.com - 2011 */
