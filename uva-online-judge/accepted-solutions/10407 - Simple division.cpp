//*****************
// LAM PHAN VIET **
// UVA 10407 - Simple division
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
#define maxN 10000
using namespace std;

int GCD(int m, int n) {
    if (m%n) return GCD(n, m%n);
    return n;
}

main() {
//    FileIn("test"); FileOut("test");
    int a, b, rs;
    while (scanf("%d", &a) && a) {
        rs = 0;
        while (scanf("%d", &b) && b) {
            if (rs==0) rs = abs(b-a);
            else {
                if (abs(b-a)==0) continue;
                rs = GCD(rs, abs(b - a));
            }
            a = b;
        }
        printf("%d\n", rs);
    }
}

/* lamphanviet@gmail.com - 2011 */
