//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : UVa
// Problem Name : 12366 - King's Poker
// Time Limit   : 1.000s
// Description  : Ad hoc
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
#define maxN 100010
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int a[5];

void solve() {
    sort(a, a + 3);
    if (a[0] != a[1] && a[1] != a[2]) {
        printf("1 1 2");
        return;
    }
    if (a[0] == a[1] && a[1] == a[2]) {
        if (a[0] == 13) printf("*");
        else printf("%d %d %d", a[0] + 1, a[0] + 1, a[0] + 1);
        return;
    }
    if (a[1] == a[2]) swap(a[0], a[2]);
    if (a[2] != 13) {
        if (a[2] + 1 == 13 && a[2] + 1 == a[0]) {
            printf("1 1 1");
            return;
        }
        if (a[2] + 1 == a[0]) a[2] += 2;
        else a[2]++;
        sort(a, a + 3);
        printf("%d %d %d", a[0], a[1], a[2]);
        return;
    }
    printf("1 %d %d", a[0] + 1, a[0] + 1);
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); outFile("test.out");
    #endif
    while (scanf("%d %d %d", &a[0], &a[1], &a[2]) != EOF) {
        if (!a[0] && !a[1] && !a[2]) break;
        solve();
        putchar('\n');
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
