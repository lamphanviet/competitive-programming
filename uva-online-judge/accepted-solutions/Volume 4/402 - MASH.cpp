/*****************/
/* LAM PHAN VIET */
/* UVA 402 - M*A*S*H
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
#define maxN 55
using namespace std;

int n, lucky;
bool Free[maxN];
char gab[200];

main() {
//    FileIn("test"); FileOut("test");
    int Case = 0, val;
    while (scanf("%d", &n) != EOF) {
        scanf("%d", &lucky);
        lucky = min(lucky, n);
        memset(Free, true, n + 1);
        int in_count = n;
        FOR (i, 1, 20) {
            if (in_count == lucky) break;
            scanf("%d", &val);
            int Count = 0;
            FOR (j, 1, n)
                if (Free[j]) {
                    Count++;
                    if (Count == val) {
                        Free[j] = false;
                        in_count--;
                        Count = 0;
                        if (in_count == lucky) break;
                    }
                }
        }
        gets(gab);
        bool space = false;
        printf("Selection #%d\n", ++Case);
        FOR (i, 1, n)
            if (Free[i]) {
                if (space) putchar(' '); space = true;
                printf("%d", i);
            }
        putchar('\n');
        putchar('\n');
    }
}

/* lamphanviet@gmail.com - 2011 */
