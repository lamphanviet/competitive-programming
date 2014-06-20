//*****************
// LAM PHAN VIET **
// UVA 847 - A Multiplication Game
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

main() {
//    FileIn("test"); FileOut("test");
    int64 n, p;
    while (scanf("%lld", &n)!=EOF) {
        bool Stan = true;
        p = 1;
        while (p<n) {
            if (Stan) p *= 9;
            else p *= 2;
            Stan = !Stan;
        }
        if (!Stan) puts("Stan wins.");
        else puts("Ollie wins.");
    }
}

/* lamphanviet@gmail.com - 2011 */
