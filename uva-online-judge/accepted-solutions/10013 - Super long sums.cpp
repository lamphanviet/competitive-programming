//*****************
// LAM PHAN VIET **
// UVA 10013 - Super long sums
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
#define maxN 1000001
using namespace std;

char a[maxN];

main() {
//    FileIn("test"); FileOut("test");
    int Case, n, d1, d2;
    for (scanf("%d", &Case); Case--; ) {
        scanf("%d", &n);
        REP (i, n) {
            scanf("%d %d", &d1, &d2);
            a[i] = d1 + d2;
        }
        int k = 0;
        for (int i=n-1; i>=0; i--) {
            k += a[i];
            a[i] = k%10;
            k /= 10;
        }
        k = 0;
        while (k<n && a[k]==0) k++;
        while (k<n) printf("%d", a[k++]);
        printf("\n");
        if (Case) printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
