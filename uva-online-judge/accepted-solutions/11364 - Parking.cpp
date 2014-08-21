//*****************
// LAM PHAN VIET **
// UVA 11364 - Parking
// Time limit: 1s
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
#define Last(i) (i & -i)
#define INF 500000000
#define maxN 10000
using namespace std;

main() {
//    FileIn("test"); FileOut("test");
    int Case, n, Min, Max, val;
    for (scanf("%d", &Case); Case--; ) {
        scanf("%d", &n);
        Min = INF; Max = 0;
        while (n--) {
            scanf("%d", &val);
            Min = min(Min, val);
            Max = max(Max, val);
        }
        printf("%d\n", (Max-Min)*2);
    }
}

/* lamphanviet@gmail.com - 2011 */
