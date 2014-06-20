//*****************
// LAM PHAN VIET **
// UVA 278 - Chess
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
#define maxN 10000
using namespace std;

main() {
//    FileIn("test"); FileOut("test");
    int Case, m, n, res;
    char c;
    for (scanf(" %d ", &Case); Case--; ) {
        scanf(" %c %d %d ", &c, &n, &m);
        if (c == 'r' || c == 'Q') res = min(n, m);
        else if (c == 'k') res = (n * m + 1) / 2;
        else if (c == 'K') res = ((n + 1)/2) * ((m + 1)/2);
        printf("%d\n", res);
    }
}

/* lamphanviet@gmail.com - 2011 */
