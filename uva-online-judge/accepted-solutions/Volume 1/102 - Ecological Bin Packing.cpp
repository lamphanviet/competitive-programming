/*****************/
/* LAM PHAN VIET */
/* UVA 102 - Ecological Bin Packing
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
#define maxN 5
using namespace std;

struct Rec {
    int b, g, c;
};
Rec r1, r2, r3;
int blue_sum, green_sum, clear_sum, result;
string config;

void Try(Rec a, Rec b, Rec c, string conf) {
    int tmp = blue_sum - a.b;
    tmp += green_sum - b.g;
    tmp += clear_sum - c.c;
    if (tmp < result) {
        result = tmp;
        config = conf;
    }
}

main() {
//    FileIn("test"); FileOut("test");
    while (scanf("%d", &r1.b) != EOF) {
        scanf("%d %d", &r1.g, &r1.c);
        scanf("%d %d %d", &r2.b, &r2.g, &r2.c);
        scanf("%d %d %d", &r3.b, &r3.g, &r3.c);
        blue_sum = r1.b + r2.b + r3.b;
        green_sum = r1.g + r2.g + r3.g;
        clear_sum = r1.c + r2.c + r3.c;
        result = INF;
        Try(r1, r3, r2, "BCG");
        Try(r1, r2, r3, "BGC");
        Try(r2, r3, r1, "CBG");
        Try(r3, r2, r1, "CGB");
        Try(r2, r1, r3, "GBC");
        Try(r3, r1, r2, "GCB");
        cout << config;
        printf(" %d\n", result);
    }
}

/* lamphanviet@gmail.com - 2011 */
