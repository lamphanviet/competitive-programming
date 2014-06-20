//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1338 - Hidden Secret! 
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

int n, m, a[26], b[26];
char x[maxN], y[maxN];

bool isSame() {
    REP(i, 26) a[i] = b[i] = 0;
    n = strlen(x); m = strlen(y);
    REP(i, n) if (x[i] != ' ')
        a[tolower(x[i]) - 'a']++;
    REP(i, m) if (y[i] != ' ')
        b[tolower(y[i]) - 'a']++;
    REP(i, 26)
        if (a[i] != b[i]) return false;
    return true;
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); outFile("test.out");
    #endif
    int caseNo, cases = 0;
    for (scanf("%d ", &caseNo); caseNo--; ) {
        gets(x); gets(y);
        printf("Case %d: ", ++cases);
        if (isSame()) puts("Yes");
        else puts("No");
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
