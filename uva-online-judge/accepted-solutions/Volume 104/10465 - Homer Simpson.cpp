//*****************
// LAM PHAN VIET **
// UVA 10465 - Homer Simpson
// Time limit: 3.000
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
#define maxN 10001
using namespace std;

int n, m, t, times[maxN];

main() {
//    FileIn("test"); FileOut("test");
    while (scanf("%d %d %d", &n, &m, &t)!=EOF) {
        FOR (i, 0, t) times[i] = 0;
        for (int i = n; i <= t; i += n)
            times[i] = times[i - n] + 1;
        if (!times[m]) times[m] = 1;
        for (int i = 1; i + m <= t; i++)
            if (times[i])
                times[i + m] = max(times[i + m], times[i] + 1);
        if (times[t]) printf("%d\n", times[t]);
        else {
            int num = 0, beer = t;
            for (int i = t; i >= 0; i--)
                if (times[i]) {
                    num = times[i];
                    beer = t - i;
                    break;
                }
            printf("%d %d\n", num, beer);
        }
    }
}

/* lamphanviet@gmail.com - 2011 */
