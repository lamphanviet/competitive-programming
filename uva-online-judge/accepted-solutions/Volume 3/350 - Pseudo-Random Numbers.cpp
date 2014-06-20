/*****************/
/* LAM PHAN VIET */
/* UVa: 350 - Pseudo-Random Numbers
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

int mul, add, mod, num;
map<int, int> idx;

main() {
//    FileIn("test"); FileOut("test");
    int Case = 0, n;
    while (scanf("%d %d %d %d", &mul, &add, &mod, &num) != EOF) {
        if (!mul && !add && !mod && !num) break;
        idx.clear();
        idx[num] = n = 1;
        while (true) {
            num = (num * mul + add) % mod;
            int k = idx[num];
            if (!k) idx[num] = ++n;
            else {
                n = n - k + 1;
                break;
            }
        }
        printf("Case %d: %d\n", ++Case, n);
    }
}

/* lamphanviet@gmail.com - 2011 */
