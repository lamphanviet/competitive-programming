//*****************
// LAM PHAN VIET **
// UVA 10790 - How Many Points of Intersection
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

main() {
//    FileIn("test"); FileOut("test");
    int Case = 0;
    uint64 n, m, result;
    while (scanf("%lld %lld", &n, &m) && (n || m)) {
        result = (n*(n-1) * m*(m-1))/4;
        printf("Case %d: %lld\n", ++Case, result);
    }
}

/* lamphanviet@gmail.com - 2011 */
