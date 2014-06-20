//*****************
// LAM PHAN VIET **
// UVA 382 - Perfection
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
#define INF 500000000
#define maxN 60000
using namespace std;

main() {
//    FileIn("test"); FileOut("test");
    int n, factor_sum;
    puts("PERFECTION OUTPUT");
    while (scanf("%d", &n)!=EOF && n) {
        factor_sum = 0;
        for (int i = 1; i < n; i++)
            if (n % i == 0) factor_sum += i;
        printf("%5d  ", n);
        if (factor_sum == n)
            puts("PERFECT");
        else if (factor_sum < n)
            puts("DEFICIENT");
        else
            puts("ABUNDANT");
    }
    puts("END OF OUTPUT");
}

/* lamphanviet@gmail.com - 2011 */
