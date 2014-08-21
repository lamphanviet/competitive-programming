/*****************/
/* LAM PHAN VIET */
/* UVA 10622 - Perfect P-th Powers
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
#define maxInt 2147483647
#define maxN 46341
using namespace std;

struct Value {
    int x, p;
};
vector<Value> v;
map<int, int> res;

bool cmp(Value a, Value b) {
    return (a.x < b.x || (a.x == b.x && a.p < b.p));
}

void precal() {
    Value a;
    for (int i = 2; i < maxN; i++) {
        int64 x = i * (int64)i;
        a.p = 2;
        while (x <= maxInt) {
            a.x = x;
            v.pb(a);
            
            x *= (int64)i;
            a.p++;
        }
    }
    sort(all(v), cmp);
    REP(i, v.size()) {
        int val = v[i].x, p = v[i].p;
        res[val] = p;
        if (p % 2) {
            int tmp = res[-val];
            if (!tmp || tmp < p)
                res[-val] = p;
        }
    }
    res[-2147483648] = 31;
}

main() {
//    FileIn("test"); FileOut("test");
    int n;
    precal();
    while (scanf("%d", &n) && n) {
        int ans = res[n];
        if (!ans) ans = 1;
        printf("%d\n", ans);
    }
}

/* lamphanviet@gmail.com - 2011 */
