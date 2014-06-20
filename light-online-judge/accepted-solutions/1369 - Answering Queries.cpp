//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1369 - Answering Queries
// Time Limit   : 2.000s
// Description  : basic math - data structure
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
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, a[maxN];

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    int caseNo, cases = 0, m, id, q, val;
    scanf("%d", &caseNo);
    while (caseNo--) {
        int64 sum = 0, f = 0;
        scanf("%d %d", &n, &m);
        FOR (i, 1, n) {
            scanf("%d", &a[i]);
            f += sum - a[i] * (int64)(i - 1);
            sum += a[i];
        }
        printf("Case %d:\n", ++cases);
        while (m--) {
            scanf("%d", &q);
            if (q) printf("%lld\n", f);
            else {
                scanf("%d %d", &id, &val); id++;
                f += (n - id) * (int64)(val - a[id]);
                f += (id - 1) * (int64)(a[id] - val);
                a[id] = val;
            }
        }
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
