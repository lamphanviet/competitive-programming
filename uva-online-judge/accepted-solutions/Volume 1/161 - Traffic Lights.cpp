//*****************
// LAM PHAN VIET **
// UVA 161 - Traffic Lights
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
#define maxN 105
using namespace std;

int n, light[maxN], time_min;

bool check(int t) {
    FOR (i, 1, n) {
        int m = t / light[i];
        if (m % 2) return false;
        m = t % light[i];
        if (m >= light[i] - 5) return false;
    }
    return true;
}

int solve() {
    int t = time_min << 1, g = time_min - 5;
    while (t <= 18000) {
        FOR (i, 0, g)
            if (t + i > 18000) return -1;
            else if (check(t + i)) return t + i;
        t += time_min << 1;
    }
    return -1;
}

main() {
//    FileIn("test"); FileOut("test");
    while (scanf("%d", &light[1]) != EOF) {
        if (!light[1]) break;
        n = 1;
        time_min = light[1];
        while (light[n]) {
            scanf("%d", &light[++n]);
            if (light[n]) time_min = min(time_min, light[n]);
        }
        n--;
        int res = solve();
        if (res < 0) puts("Signals fail to synchronise in 5 hours");
        else {
            int h = res / 3600;
            int m = (res - h * 3600) / 60;
            int s = res - h * 3600 - m * 60;
            
            if (h < 10) printf("0");
            printf("%d:", h);
            if (m < 10) printf("0");
            printf("%d:", m);
            if (s < 10) printf("0");
            printf("%d\n", s);
        }
    }
    scanf("%d %d", &light[2], &light[3]);
}

/* lamphanviet@gmail.com - 2011 */
