//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1189 - Sum of Factorials 
// Time Limit   : 0.500s
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
#define maxN 21
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int64 fact[maxN], n;
int a[maxN];

int solve() {
    int m = 0;
    for (int i = maxN - 1; i >= 0 && n; i--)
        if (n >= fact[i]) {
            n -= fact[i];
            a[m++] = i;
        }
    if (n) return -1;
    return m;
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); outFile("test.out");
    #endif
    fact[0] = 1LL;
    for (int i = 1; i < maxN; i++)
        fact[i] = fact[i - 1] * i;
    int caseNo, cases = 0;
    for (scanf("%d", &caseNo); caseNo--; ) {
        scanf("%lld", &n);
        printf("Case %d:", ++cases);
        n = solve();
        if (n < 0) printf(" impossible");
        else for (int i = n - 1; i >= 0; i--) {
            if (i == n-1) putchar(' ');
            else putchar('+');
            printf("%d!", a[i]);
        }
        puts("");
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
