//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1005 - Rooks
// Time Limit   : 2.000s
// Description  : dp - math
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
#define Last(i) ( (i) & (-i) )
#define sq(x) ((x) * (x))
#define INF 500000000
#define maxN 33
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int64 C[maxN][maxN], fact[maxN];

void preCal() {
    fact[0] = 1LL;
    C[0][0] = 1LL;
    for (int i = 1; i < maxN; i++) {
        fact[i] = fact[i - 1] * i;
        C[i][0] = C[i][i] = 1LL;
        for (int j = 1; j < i; j++)
            C[i][j] = C[i-1][j] + C[i-1][j-1];
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    preCal();
    int caseNo, cases = 0, n, k;
    scanf("%d", &caseNo);
    while (caseNo--) {
        scanf("%d %d", &n, &k);
        printf("Case %d: ", ++cases);
        if (k > n) puts("0");
        else printf("%lld\n", C[n][k] * C[n][k] * fact[k]);
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
