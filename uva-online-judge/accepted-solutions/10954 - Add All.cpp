//*****************
// LAM PHAN VIET **
// UVA 10954 - Add All
// Time limit: 3.000s
//********************************
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
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

struct cmp {
    bool operator() (int a, int b) const {
        return (a > b);
    };
};

priority_queue<int, vector<int>, cmp> H;

main() {
//    FileIn("test"); FileOut("test");
    int n, val;
    while (scanf("%d", &n) && n) {
        H = priority_queue<int, vector<int>, cmp>();
        FOR (i, 1, n) {
            scanf("%d", &val);
            H.push(val);
        }
        int res = 0, a, b;
        while (H.size()!=1) {
            a = H.top(); H.pop();
            b = H.top(); H.pop();
            res += a + b;
            H.push(a + b);
        }
        printf("%d\n", res);
    }
}

/* lamphanviet@gmail.com - 2011 */
