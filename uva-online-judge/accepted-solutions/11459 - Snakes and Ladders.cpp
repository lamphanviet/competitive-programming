//*****************
// LAM PHAN VIET **
// UVA 11459 - Snakes and Ladders
// Time limit: 10.000s
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
#define maxN 1000001
using namespace std;

int n, m, player[maxN];
int send[101];

main() {
//    FileIn("test"); FileOut("test");
    int Case, k, x, y;
    for (scanf("%d", &Case); Case--; ) {
        scanf("%d %d %d", &n, &m, &k);
        FOR (i, 1, n) player[i] = 1;
        FOR (i, 1, 100) send[i] = 0;
        while (m--) {
            scanf("%d %d", &x, &y);
            send[x] = y;
        }
        int p = 1;
        bool finish = false;
        while (k--) {
            scanf("%d", &x);
            if (finish) continue;
            player[p] = min(player[p] + x, 100);
            if (send[player[p]])
                player[p] = send[player[p]];
            if (player[p] == 100) finish = true;
            p = p%n + 1;
        }
        FOR (i, 1, n)
            printf("Position of player %d is %d.\n", i, player[i]);
    }
}

/* lamphanviet@gmail.com - 2011 */
