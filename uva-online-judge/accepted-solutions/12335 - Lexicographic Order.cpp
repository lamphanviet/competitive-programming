//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : UVA
// Problem Name : 12335 - Lexicographic Order
// Time Limit   : 1.000s
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
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 22
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int64 fact[maxN], n;
char s[maxN], res[maxN];
int order[maxN], m;
bool Free[maxN];

int getPos(int p) {
    int counter = 0;
    REP(i, m)
        if (Free[i] && ++counter == p) {
            Free[i] = false;
            return i;
        }
}

void solve() {
    m = strlen(s);
    fill(Free, true);
    REP(i, m) {
        int pos = (int)ceil(n / (double)fact[m - i - 1]);
        order[i] = getPos(pos);
        n -= fact[m - i - 1] * (pos - 1);
    }
    REP(i, m) res[order[i]] = s[i];
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); outFile("test.out");
    #endif
    fact[0] = 1LL;
    FOR (i, 1, 20) fact[i] = fact[i - 1] * i;
    int Case;
    scanf("%d ", &Case);
    FOR (test, 1, Case) {
        scanf("%s %lld ", &s, &n);
        printf("Case %d: ", test);
        solve();
        REP(i, m) putchar(res[i]);
        putchar('\n');
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
