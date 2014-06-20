//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1214 - Large Division 
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
#define maxN 222
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

char s[maxN];

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); outFile("test.out");
    #endif
    int caseNo, cases = 0, n, len;
    for (scanf("%d", &caseNo); caseNo--; ) {
        scanf(" %s %d ", &s, &n);
        len = strlen(s);
        if (s[0] == '-') s[0] = '0';
        if (n < 0) n = -n;
        int64 remainder = 0;
        REP(i, len)
            remainder = (remainder * 10LL + (s[i] - 48)) % n;
        printf("Case %d: ", ++cases);
        if (remainder) printf("not ");
        puts("divisible");
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
