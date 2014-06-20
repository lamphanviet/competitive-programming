//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1082 - Array Queries
// Time Limit   : 2.000s
// Description  : using RMQ O(nlogn, 1)
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
#define maxN 100010
#define maxLN 20
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, M[maxN][maxLN];

void processRMQ() {
    for (int j = 1; bit(j) <= n; j++)
        for (int i = 1; i + bit(j) - 1 <= n; i++)
            M[i][j] = min(M[i][j - 1], M[i + bit(j - 1)][j - 1]);
}

int get(int x, int y) {
    int k = (int)log2(y - x + 1);
    return min(M[x][k], M[y - bit(k) + 1][k]);
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    int caseNo, cases = 0, m, x, y;
    scanf("%d", &caseNo);
    while (caseNo--) {
        scanf("%d %d", &n, &m);
        FOR (i, 1, n) scanf("%d", &M[i][0]);
        processRMQ();
        printf("Case %d:\n", ++cases);
        while (m--) {
            scanf("%d %d", &x, &y);
            printf("%d\n", get(x, y));
        }
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
