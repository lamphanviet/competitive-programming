//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1249 - Chocolate Thief
// Time Limit   : 1.000s
// Description  : beginner
//============================================================================
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define inpFile(f) freopen(f, "r", stdin)
#define outFile(f) freopen(f, "w", stdout)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define ff first
#define ss second
#define bit(n) (1<<(n))
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 110
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

char name[maxN][22];

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); outFile("test.out");
    #endif
    int caseNo, cases = 0, n, a, b, c;
    for (scanf("%d", &caseNo); caseNo--; ) {
        scanf(" %d ", &n);
        int x = 0, y = 0, minV = INF, maxV = -INF;
        REP(i, n) {
            scanf(" %s %d %d %d ", &name[i], &a, &b, &c);
            a = a * b * c;
            if (a < minV) {
                x = i;
                minV = a;
            }
            if (a > maxV) {
                y = i;
                maxV = a;
            }
        }
        printf("Case %d: ", ++cases);
        if (minV == maxV)
            puts("no thief");
        else printf("%s took chocolate from %s\n", name[y], name[x]);
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
