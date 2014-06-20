//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1129 - Consistency Checker
// Time Limit   : 2.000s
// Description  : trie
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

struct Node {
    int next[10];
    bool isEnd;
} node[maxN];
int last;

int newNode() {
    ++last;
    REP(i, 10) node[last].next[i] = -1;
    node[last].isEnd = false;
    return last;
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    char s[15];
    int caseNo, cases = 0, n;
    scanf("%d", &caseNo);
    while (caseNo--) {
        scanf(" %d ", &n);
        last = -1;
        newNode();
        bool yes = true;
        while (n--) {
            gets(s);
            if (!yes) continue;
            int m = strlen(s), id = 0;
            REP(i, m) {
                s[i] -= 48;
                if (node[id].next[s[i]] == -1)
                    node[id].next[s[i]] = newNode();
                else if (i == m - 1) yes = false;
                id = node[id].next[s[i]];
                if (node[id].isEnd) yes = false;
            }
            node[id].isEnd = true;
        }
        printf("Case %d: ", ++cases);
        if (yes) puts("YES");
        else puts("NO");
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
