//*****************
// LAM PHAN VIET **
// UVA 12015 - Google is Feeling Lucky
// Time limit: 1.000s
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
#define For(i, a, b) for (int i=a; i<=b; i++)
#define Forv(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) (i & -i)
#define Parent(i) (i - Last(i))
#define INF 500000000
#define maxN 11
using namespace std;

int n, val[maxN];
char name[maxN][105];

main() {
//    FileIn("test"); FileOut("test");
    int Case;
    scanf("%d", &Case);
    For (kk, 1, Case) {
        int Max = 0;
        Forv(i, 10) {
            scanf(" %s %d", &name[i], &val[i]);
            Max = max(val[i], Max);
        }
        printf("Case #%d:\n", kk);
        Forv (i, 10)
            if (val[i]==Max) puts(name[i]);
    }
}

/* lamphanviet@gmail.com - 2011 */
