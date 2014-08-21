//*****************
// LAM PHAN VIET **
// UVA 10077 - The Stern-Brocot Number System
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

int Compare(int64 a, int64 b, int64 c, int64 d) {
    if (a==c && b==d) return 0;
    return (a*d > b*c)? 1: -1;
}

main() {
//    FileIn("test"); FileOut("test");
    int n, m;
    while (scanf("%d %d", &n, &m)!=EOF) {
        if (n==1 && m==1) break;
        int a = 0, b = 1, c = 1, d = 0;
        while (1) {
            int x = a + c, y = b + d;
            int cmp = Compare(n, m, x, y);
            if (cmp==0) break;
            if (cmp==1) {
                printf("R");
                a = x; b = y;
            }
            else {
                printf("L");
                c = x; d = y;
            }
        }
        printf("\n");
    }
}

/* lamphanviet@gmail.com - 2011 */
