//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : UVa
// Problem Name : 12378 - Ball Blasting Game
// Time Limit   : 1.000s
// Description  : brute force + trick
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

int len, n, a[maxN];
char s[maxN];

int check() {
    for (int i = 1; i <= n; i++)
        if (i & 1 && a[i] != a[1]) return -1;
        else if (!(i & 1) && a[i] != a[2]) return -1;
    int s = max(1, n / 2 - 2);
    int f = min(n, s + 5), res = 0;
    FOR (i, s, f) {
        int cnt = 1, x = i - 1, y = i + 1;
        while (x >= 1 && y <= n && a[x] == a[y])
            x--, y++, cnt++;
        res = max(res, cnt);
    }
    return res;
}

int solve() {
    int res = check();
    if (res != -1) return res;
    res = 0;
    FOR (i, 1, n) {
        int cnt = 1, x = i - 1, y = i + 1;
        while (x >= 1 && y <= n && a[x] == a[y])
            x--, y++, cnt++;
        res = max(res, cnt);
    }
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); outFile("test.out");
    #endif
    int Case;
    for (scanf("%d ", &Case); Case--; ) {
        gets(s);
        len = strlen(s);
        a[1] = s[0] - 'A' + 1;
        n = 1;
        for (int i = 1; i < len; i++)
            if (s[i] != s[i - 1])
                a[++n] = s[i] - 'A' + 1;
    //    printf("a: "); FOR (i, 1, n) printf("%d ", a[i]); puts("");
        printf("%d\n", solve());
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
