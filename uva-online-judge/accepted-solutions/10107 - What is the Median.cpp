//*****************
// LAM PHAN VIET **
// UVA 10107 - What is the Median
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
#define maxN 10001
using namespace std;

int n = 0, a[maxN];

main() {
//    FileIn("test"); FileOut("test");
    while (scanf("%d", &a[++n])!=EOF) {
        for (int i=n-1; i>=1; i--)
            if (a[i] > a[i+1]) swap(a[i], a[i+1]);
            else break;
        if (n%2) printf("%d\n", a[(n+1)/2]);
        else printf("%d\n", (a[n/2] + a[n/2+1])/2);
    }
}

/* lamphanviet@gmail.com - 2011 */
