//*****************
// LAM PHAN VIET **
// UVA 305 - Joseph
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
#define maxN 30
using namespace std;

/*
bool check(int k, int m) {
    int good = k, bad = k, p = 0;
    while (bad) {
        int next = (p + m) % (good + bad);
        if (!next) next = good + bad;
        if (next <= k) return false;
        bad--;
        p = next - 1;
    }
    return true;
}

int solve(int k) {
    int m = k;
    while (++m)
        if (check(k, m))
            return m;
    return 0;
}
*/
const int res[] = { 0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881 };

main() {
//    FileIn("test"); FileOut("test");
    int n;
    while (scanf("%d", &n) && n)
        printf("%d\n", res[n]);
}


/* lamphanviet@gmail.com - 2011 */
