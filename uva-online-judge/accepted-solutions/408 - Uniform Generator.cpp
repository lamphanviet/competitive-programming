/*****************/
/* LAM PHAN VIET */
/* UVA 408 - Uniform Generator
/* Time limit: 3.000s
/********************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
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

int gcd(int n, int m) {
    if (n % m) return gcd(m, n % m);
    return m;
}

main() {
//    FileIn("test"); FileOut("test");
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        printf("%10d%10d", n, m);
        printf("    ");
        if (gcd(n, m) == 1) printf("Good Choice");
        else printf("Bad Choice");
        putchar('\n');
        putchar('\n');
    }
}

/* lamphanviet@gmail.com - 2011 */
