//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1293 - Document Analyzer 
// Time Limit   : 3.000s
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
#define maxN 50010
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, m, a[maxN], p, q, b[maxN];
map<string, int> id;

int getIdx(const string &s) {
    int i = id[s];
    if (!i) i = id[s] = ++m;
    return i;
}

void parseInput() {
    char s[111];
    id.clear();
    n = m = 0;
    while (scanf(" %s ", &s)) {
        if (strcmp(s, "END") == 0) break;
        int len = strlen(s);
        for (int i = 0; i < len; )
            if (isalpha(s[i])) {
                string tmp = "";
                while (i < len && isalpha(s[i]))
                    tmp += s[i++];
                a[++n] = getIdx(tmp);
            }
            else i++;
    }
}

void solve() {
    FOR (i, 1, m) b[i] = 0;
    p = 0, q = INF;
    int counter = 0;
    for (int f = 1, s = 1; f <= n; f++) {
        if (++b[a[f]] == 1) counter++;
        while (s < f && b[a[s]] > 1)
            b[a[s++]]--;
        if (counter == m && f - s < q - p) {
            p = s;
            q = f;
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    int caseNo, cases = 0;
    scanf("%d ", &caseNo);
    while (caseNo--) {
        parseInput();
        solve();
        printf("Case %d: %d %d\n", ++cases, p, q);
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
