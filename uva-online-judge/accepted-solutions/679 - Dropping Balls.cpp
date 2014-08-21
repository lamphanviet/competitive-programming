//*****************
// LAM PHAN VIET **
// UVA 679 - Dropping Balls
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
using namespace std;

main() {
//    FileIn("test"); FileOut("test");
    int Case, d, k;
    for (scanf("%d", &Case); Case--; ) {
        scanf("%d %d", &d, &k);
        if (d==-1) break;
        int n = bit(d)-1, p = 1;
        while (p+p <= n) {
            if (k%2) p += p ;
            else p += p + 1;
            k = (k+1)/2;
        }
        printf("%d\n", p);
    }
    scanf("%d", &Case);
}

/* lamphanviet@gmail.com - 2011 */
