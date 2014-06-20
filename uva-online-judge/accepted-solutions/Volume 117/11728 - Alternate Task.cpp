//*****************
// LAM PHAN VIET **
// UVA 11728 - Alternate Task
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

int sumfact[maxN];
int res[maxN];

void PreCal() {
    REP (i, maxN)
        sumfact[i] = 0, res[i] = -1;
    FOR (i, 1, maxN-1)
        for (int j=i; j<maxN; j+=i)
            sumfact[j] += i;
    FOR (i, 1, maxN-1)
        if (sumfact[i] < maxN) {
            int s = sumfact[i];
            res[s] = max(res[s], i);
        }
}

main() {
//    FileIn("test"); FileOut("test");
    int Case = 0, n = 0;
    PreCal();
    while (scanf("%d", &n) && n) {
        printf("Case %d: %d\n", ++Case, res[n]);
    }
}

/* lamphanviet@gmail.com - 2011 */
