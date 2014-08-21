//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : UVa
// Problem Name : 12380 - Glimmr in Distress
// Time Limit   : 1.000s
// Description  : Quad tree
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
#define maxN 100010
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

char s[maxN];
int len, ans;

int nextPos(int i, int lvl) {
    if (ans == -1) return 0;
    ans = max(ans, lvl);
    if (i >= len) {
        ans = -1;
        return 0;
    }
    if (s[i] == '2') {
        if (i + 4 >= len) return 0;
        if (s[i + 1] != '2') {
            bool f = true;
            for (int j = i + 2; j <= i + 4; j++)
                if (s[j] != s[i + 1]) {
                    f = false;
                    break;
                }
            if (f) return 0;
        }
        i = nextPos(i + 1, lvl + 1);
        if (i == 0) return 0;
        REP(_, 3) {
            i = nextPos(i, lvl + 1);
            if (i == 0) break;
        }
        return i;
    }
    return i + 1;
}

int solve() {
    if (len == 1) {
        if (s[0] == '2') return -1;
        return 0;
    }
    ans = 1;
    int k = nextPos(0, 0);
    if (k != len) return -1;
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); outFile("test.out");
    #endif
    int Case;
    for (scanf("%d ", &Case); Case--; ) {
        gets(s);
        len = strlen(s);
        int res = solve();
        if (res == -1) puts("Not Possible");
        else printf("2^%d*2^%d\n", res, res);
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
