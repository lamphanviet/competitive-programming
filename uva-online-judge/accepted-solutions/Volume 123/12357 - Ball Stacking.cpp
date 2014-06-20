//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : UVa
// Problem Name : 12357 - Ball Stacking
// Time Limit   : 1.000s
// Description  : DP
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
#define maxN 1010
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n;
int64 a[maxN][maxN], maxA[maxN][maxN];

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); outFile("test.out");
    #endif
    int val;
    while (scanf("%d", &n) && n) {
        int64 res = 0;
        FOR (i, 1, n)
            FOR (j, 1, i) {
                scanf("%lld", &a[i][j]);
                a[i][j] += a[i - 1][j];
            }
        maxA[n][1] = a[n][1];
        res = max(res, a[n][1]);
        for (int i = n - 1; i >= 1; i--) {
            res = max(a[i][1], res);
            maxA[i][1] = max(maxA[i + 1][1], a[i][1]);
        }
        FOR (j, 2, n) {
            FOR (i, j, n) {
                a[i][j] = maxA[i-1][j-1] + a[i][j];
                res = max(res, a[i][j]);
            }
            maxA[n][j] = a[n][j];
            for (int i = n - 1; i >= j; i--)
                maxA[i][j] = max(maxA[i+1][j], a[i][j]);
            maxA[j-1][j] = max(maxA[j][j], 0LL);
        }
        printf("%lld\n", res);
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
