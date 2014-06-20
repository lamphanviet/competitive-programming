/*****************/
/* LAM PHAN VIET */
/* UVA 119 - Greedy Gift Givers
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
#define maxN 15
using namespace std;

int n, money[maxN];
char name[maxN][maxN];
map<string, int> idx;

main() {
//    FileIn("test"); FileOut("test");
    char s[maxN];
    bool line = false;
    while (scanf(" %d ", &n) != EOF) {
        idx.clear();
        FOR (i, 1, n) {
            scanf(" %s ", &name[i]);
            idx[name[i]] = i;
            money[i] = 0;
        }
        FOR (i, 1, n) {
            scanf(" %s ", &s);
            int p = idx[s], spent, m, price;
            scanf(" %d %d ", &spent, &m);
            money[p] -= spent;
            if (m) {
                price = spent / m;
                money[p] += spent % m;
            }
            else money[p] += spent;
            while (m--) {
                scanf(" %s ", &s);
                p = idx[s];
                money[p] += price;
            }
        }
        if (line) putchar('\n'); line = true;
        FOR (i, 1, n)
            printf("%s %d\n", name[i], money[i]);
    }
}

/* lamphanviet@gmail.com - 2011 */
