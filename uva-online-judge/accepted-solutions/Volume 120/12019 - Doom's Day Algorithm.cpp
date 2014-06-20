//*****************
// LAM PHAN VIET **
// UVA 12019 - Doom's Day Algorithm
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
#define maxN 10000
using namespace std;

char Day[][15] = {"0", "1", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
int MaxDay[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int ans[15][35];

void PreCalc() {
    int m = 1, d = 1, days = 7;
    while (m!=13) {
        ans[m][d] = days;
        d++;
        if (d>MaxDay[m]) {
            d = 1; m++;
        }
        days++;
        if (days==9) days = 2;
    }
}

main() {
 //   FileIn("test"); FileOut("test");
    PreCalc();
    int Case, m, d;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d %d", &m, &d);
        printf("%s\n", Day[ans[m][d]]);
    }
}

/* lamphanviet@gmail.com - 2011 */
