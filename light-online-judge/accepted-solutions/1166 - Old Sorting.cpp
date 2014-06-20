//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1166 - Old Sorting
// Time Limit   : 2.000s
// Description  : 
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
#define maxN 111
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, a[maxN];

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    int caseNo, cases = 0;
    scanf("%d", &caseNo);
    while (caseNo--) {
        scanf("%d", &n);
        FOR (i, 1, n) scanf("%d ", &a[i]);
        int res = 0;
        FOR (i, 1, n) {
            FOR (j, i, n)
                if (a[j] == i) {
                    if (j != i) res++;
                    swap(a[j], a[i]);
                    break;
                }
        }
        printf("Case %d: %d\n", ++cases, res);
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
