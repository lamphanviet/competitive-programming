//*****************
// LAM PHAN VIET **
// UVA 11559 - Event Planning
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
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 10000
using namespace std;

main() {
//    FileIn("test"); FileOut("test");
    int n, budget, hotel, week;
    while (scanf("%d", &n) != EOF) {
        scanf("%d %d %d", &budget, &hotel, &week);
        int res = INF, price, num;
        while (hotel--) {
            scanf("%d", &price);
            bool can_try = false;
            REP(i, week) {
                scanf("%d", &num);
                if (num >= n) can_try = true;
            }
            if (can_try) {
                price = price * n;
                if (price <= budget && price < res)
                    res = price;
            }
        }
        if (res == INF) puts("stay home");
        else printf("%d\n", res);
    }
}

/* lamphanviet@gmail.com - 2011 */
