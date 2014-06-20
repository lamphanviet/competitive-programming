//*****************
// LAM PHAN VIET **
// UVA 11321 - Sort! Sort!! and Sort!!!
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

int a[maxN], n, MOD;

bool cmp(int a, int b) {
    int ma = a % MOD, mb = b % MOD;
    if (ma<mb) return true;
    else if (ma>mb) return false;
    
    if (a%2 && b%2) return (a > b);
    if (a%2==0 && b%2==0) return (a < b);
    
    return (a%2);
}

main() {
//    FileIn("test"); FileOut("test");
    while (scanf("%d %d", &n, &MOD) && (n || MOD)) {
        printf("%d %d\n", n, MOD);
        REP (i, n) scanf("%d", &a[i]);
        sort(a, a + n, cmp);
        REP (i, n) printf("%d\n", a[i]);
    }
    puts("0 0");
}

/* lamphanviet@gmail.com - 2011 */
