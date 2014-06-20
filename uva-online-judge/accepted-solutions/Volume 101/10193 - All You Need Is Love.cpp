//*****************
// LAM PHAN VIET **
// UVA 10193 - All You Need Is Love
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
#define maxN 35
using namespace std;

int GCD(int m, int n) {
    if (m%n) return GCD(n, m%n);
    return n;
}

int Convert(char s[]) {
    int len = strlen(s), rs = 0;
    REP (i, len) rs = rs*2 + (s[i]-48);
    return rs;
}

main() {
//    FileIn("test"); FileOut("test");
    char s1[maxN], s2[maxN];
    int Case, n, m;
    scanf("%d", &Case);
    FOR (kk, 1, Case) {
        scanf(" %s %s", &s1, &s2);
        n = Convert(s1); m = Convert(s2);
        printf("Pair #%d: ", kk);
        if (GCD(n, m)>1) puts("All you need is love!");
        else puts("Love is not all you need!");
    }
}

/* lamphanviet@gmail.com - 2011 */
