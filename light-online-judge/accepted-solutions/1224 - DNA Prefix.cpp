//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1224 - DNA Prefix 
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
#define maxN 2500010
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

struct Node {
    int next[4], num;
    Node() {
        REP(i, 4) next[i] = -1;
        num = 0;
    }
};
vector<Node> node;

int getIdx(char a) {
    switch (a) {
        case 'A': return 0; break;
        case 'T': return 1; break;
        case 'G': return 2; break;
        case 'C': return 3; break;
    }
}

int res;

void dfs(int id, int deep) {
    res = max(res, node[id].num * deep);
    REP(i, 4)
        if (node[id].next[i] != -1)
            dfs(node[id].next[i], deep + 1);
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    char s[55];
    int caseNo, cases = 0, n;
    scanf("%d", &caseNo);
    while (caseNo--) {
        scanf(" %d ", &n);
        node.clear();
        node.pb(Node());
        while (n--) {
            gets(s);
            int id = 0, len = strlen(s);
            REP(i, len) {
                s[i] = getIdx(s[i]);
                if (node[id].next[s[i]] == -1) {
                    node.pb(Node());
                    node[id].next[s[i]] = node.size() - 1;
                    id = node.size() - 1;
                }
                else id = node[id].next[s[i]];
                node[id].num++;
            }
        }
        res = 0;
        dfs(0, 0);
        printf("Case %d: %d\n", ++cases, res);
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
