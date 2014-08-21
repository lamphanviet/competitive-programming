//*****************
// LAM PHAN VIET **
// UVA 12049 - Just Prune The List
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

int a[maxN], b[maxN], n, m;

main() {
//    FileIn("test"); FileOut("test");
    int Case;
    for (scanf("%d", &Case); Case--; ) {
        scanf("%d %d", &n, &m);
        FOR (i, 1, n) scanf("%d", &a[i]);
        FOR (i, 1 ,m) scanf("%d", &b[i]);
        sort(a + 1, a + n + 1);
        sort(b + 1, b + m + 1);
        bool f = false;
        int res = 0, j = 1, i = 1;
        while (i <= n && j <= m) {
            if (a[i]==b[j]) {
                i++; j++;
            }
            else if (a[i] < b[j]) {
                while (i<=n && a[i] < b[j]) {
                    res++; i++;
                }
            }
            else {
                while (j<=m && a[i] > b[j]) {
                    res++; j++;
                }
            }
        }
        res += ( n - i + 1) + (m - j + 1);
        printf("%d\n", res);
    }
}

/* lamphanviet@gmail.com - 2011 */
