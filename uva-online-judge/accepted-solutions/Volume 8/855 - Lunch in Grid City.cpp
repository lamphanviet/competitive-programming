//*****************
// LAM PHAN VIET **
// UVA 855 - Lunch in Grid City
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
#define Last(i) (i & -i)
#define INF 500000000
#define maxN 1001
using namespace std;

int n, m, x[maxN], y[maxN];

main() {
//    FileIn("test"); FileOut("test");
    int Case, a, b, k;
    for (scanf("%d", &Case); Case--; ) {
        scanf("%d %d %d", &a, &b, &n);
        m = max(a, b);
        for (int i=1; i<=m; i++)
            x[i] = y[i] = 0;
        k = (n%2)? n/2+1 : n/2;
        while (n--) {
            scanf("%d %d", &a, &b);
            x[a]++; y[b]++;
        }
        bool fa = false, fb = false;
        a = b = 0;
        for (int i=1; i<=m; i++) {
            if (!fa) {
                a += x[i];
                if (a>=k)
                    a = i, fa = true;
            }
            if (!fb) {
                b += y[i];
                if (b>=k)
                    b = i, fb = true;
            }
            if (fa && fb) break;
        }
        printf("(Street: %d, Avenue: %d)\n", a, b);
    }
}

/* lamphanviet@gmail.com - 2011 */
