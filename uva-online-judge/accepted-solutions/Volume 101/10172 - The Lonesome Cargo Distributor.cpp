//*****************
// LAM PHAN VIET **
// UVA 10172 - The Lonesome Cargo Distributor
// Time limit: 3.000
//********************************
#include <algorithm>
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

int n, stack_max, queue_max;
queue<int> Q[maxN];
stack<int> S;

void initialize() {
    FOR (i, 1, n) {
        Q[i] = queue<int>();
    }
    S = stack<int>();
}

int solve() {
    int i = 1, res = 0;
    while (1) {
        // unload
        while (!S.empty()) {
            int cargo = S.top();
            if (cargo != i) {
                if (Q[i].size() == queue_max) break;
                Q[i].push(cargo);
            }
            S.pop();
            res++;
        }
        // upload
        while (S.size() < stack_max && !Q[i].empty()) {
            S.push(Q[i].front()); Q[i].pop();
            res++;
        }
        if (S.empty()) {
            bool finish = true;
            for (int i = 1; i <= n && finish; i++)
                if (!Q[i].empty()) finish = false;
            if (finish) break;
        }
        i = (i % n) + 1;
        res += 2;
    }
    return res;
}

main() {
//    FileIn("test"); FileOut("test");
    int Case, m, val;
    for (scanf("%d", &Case); Case--; ) {
        scanf("%d %d %d", &n, &stack_max, &queue_max);
        initialize();
        FOR (i, 1, n) {
            scanf("%d", &m);
            while (m--) {
                scanf("%d", &val);
                Q[i].push(val);
            }
        }
        printf("%d\n", solve());
    }
}

/* lamphanviet@gmail.com - 2011 */
