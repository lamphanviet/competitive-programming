//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1114 - Easily Readable
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
    int end, next[52];
} node[maxN];
int last;

void newNode(bool f = false) {
    if (f) last = 0;
    else last++;
    node[last].end = 0;
    REP(i, 52) node[last].next[i] = -1;
}

int getIdx(char a) {
    if ('a' <= a && a <= 'z') return a - 'a';
    return a - 'A' + 26;
}

char s[maxN], word[111];

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    int caseNo, cases = 0, m;
    scanf("%d", &caseNo);
    while (caseNo--) {
        scanf(" %d ", &m);
        newNode(true);
        while (m--) {
            scanf(" %s ", &word);
            int len = strlen(word), id = 0;
            if (len > 2) sort(word + 1, word + len - 1);
            REP(i, len) {
                word[i] = getIdx(word[i]);
                if (node[id].next[word[i]] == -1) {
                    newNode();
                    node[id].next[word[i]] = last;
                    id = last;
                }
                else id = node[id].next[word[i]];
            }
            node[id].end++;
        }
        scanf(" %d ", &m);
        printf("Case %d:\n", ++cases);
        while (m--) {
            gets(s);
            int len = strlen(s);
            int64 res = 1;
            for (int i = 0, j; i < len && res; )
                if (isalpha(s[i])) {
                    for (j = i; j < len && isalpha(s[j]); j++);
                    if (j - i > 2) sort(s + i + 1, s + j - 1);
                    int id = 0;
                    while (i < j && res) {
                        s[i] = getIdx(s[i]);
                        if (node[id].next[s[i]] != -1)
                            id = node[id].next[s[i]];
                        else res = 0;
                        i++;
                    }
                    res *= node[id].end;
                    i = j;
                }
                else i++;
            printf("%lld\n", res);
        }
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
