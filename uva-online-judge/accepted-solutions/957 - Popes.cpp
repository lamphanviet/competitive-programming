//*****************
// LAM PHAN VIET **
// UVA 957 - Popes
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
#define maxN 100001
using namespace std;

int n, Y, a[maxN];
int Max, L, R;

main() {
//    FileIn("test"); FileOut("test");
    while (scanf("%d %d", &Y, &n)!=EOF) {
        FOR (i, 1, n) scanf("%d", &a[i]);
        Max = 0;
        int s = 1, f = 2;
        while (f<=n) {
            while (f <= n && a[f]-a[s]+1 <= Y) f++;
            if (f-s > Max) {
                Max = f - s;
                L = a[s]; R = a[f-1];
            }
            s++;
        }
        printf("%d %d %d\n", Max, L, R);
    }
}

/* lamphanviet@gmail.com - 2011 */
