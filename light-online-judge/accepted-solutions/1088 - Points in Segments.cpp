//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1088 - Points in Segments 
// Time Limit   : 2.000s
// Description  : binary search
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
#define maxM 50005
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n;
vi point;

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    int caseNo, cases = 0, n, m, x, y;
    scanf("%d", &caseNo);
    while (caseNo--) {
        scanf("%d %d", &n, &m);
        point.clear();
        while (n--) {
            scanf("%d", &x);
            point.pb(x);
        }
        printf("Case %d:\n", ++cases);
        while (m--) {
            scanf("%d %d", &x, &y);
            x = (int)(lower_bound(all(point), x) - point.begin());
            y = (int)(upper_bound(all(point), y) - point.begin());
            printf("%d\n", y - x);
        }
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
