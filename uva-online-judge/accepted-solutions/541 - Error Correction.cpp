/*****************/
/* LAM PHAN VIET */
/* UVA 541 - Error Correction
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
#define maxN 101
using namespace std;

int n, sum_hor[maxN], sum_ver[maxN];

main() {
//    FileIn("test"); FileOut("test");
    int val;
    while (scanf("%d", &n) && n) {
        FOR (k, 1, n)
            sum_ver[k] = sum_hor[k] = 0;
        FOR (i, 1, n)
            FOR (j, 1, n) {
                scanf("%d", &val);
                sum_hor[i] += val;
                sum_ver[j] += val;
            }
        int count_ver = 0, u, count_hor = 0, v;
        FOR (k, 1, n) {
            if (sum_ver[k] % 2) {
                count_ver++; v = k;
            }
            if (sum_hor[k] % 2) {
                count_hor++; u = k;
            }
        }
        if (!count_ver && !count_hor) puts("OK");
        else if (count_ver == 1 && count_hor == 1) printf("Change bit (%d,%d)\n", u, v);
        else puts("Corrupt");
    }
}

/* lamphanviet@gmail.com - 2011 */
