//=============================//
// Author: LAM PHAN VIET       //
// Online Judge: UVA
// Problem: 1254 - Top 10
// Time limit: 18.000s
//=============================//
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
#define maxN 20002
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int stringCmp(const string &x, const string &y) {
    int i = 0;
    while (i < x.length()) {
        if (x[i] < y[i]) return -1;
        else if (x[i] > y[i]) return 1;
        i++;
    }
    return 0;
}

struct Word {
    string text;
    int id;
    bool operator < (const Word &w) const {
        if (text.length() == w.text.length()) {
            int cmp = stringCmp(text, w.text);
            if (cmp == 0) return id < w.id;
            return cmp < 0;
        }
        return text.length() < w.text.length();
    }
} word[maxN];

struct Node {
    vi qid;
    Node *next[26];
} *trie;

Node *newNode() {
    Node *node = new Node();
    REP(i, 26) node->next[i] = NULL;
    return node;
}

int n, m, len;
char s[100005];
vi res[100005];

int main() {
    #ifndef ONLINE_JUDGE
       // inpFile("test.inp"); outFile("test.out");
    #endif
    scanf("%d ", &n);
    REP(i, n) {
        gets(s);
        word[i].text = s;
        word[i].id = i + 1;
    }
    sort(word, word + n);
    
    scanf("%d ", &m);
    trie = newNode();
    REP(i, m) {
        gets(s);
        len = strlen(s);
        Node *node = trie;
        REP(j, len) {
            if (node->next[s[j] - 'a'] == NULL)
                node->next[s[j] - 'a'] = newNode();
            node = node->next[s[j] - 'a'];
        }
        node->qid.pb(i);
    }
    
    REP(k, n) {
        len = word[k].text.length();
        REP(i, len) {
            Node *node = trie;
            for (int j = i; j < len; j++)
                if (node->next[word[k].text[j] - 'a'] != NULL) {
                    node = node->next[word[k].text[j] - 'a'];
                    REP(t, node->qid.size()) {
                        int id = node->qid[t];
                        if (res[id].size() < 10 && !(res[id].size() && res[id].back() == word[k].id))
                            res[id].pb(word[k].id);
                    }
                }
                else break;
        }
    }
    
    // output
    REP(i, m)
        if (!res[i].size()) puts("-1");
        else {
            printf("%d", res[i][0]);
            for (int j = 1; j < res[i].size(); j++)
                printf(" %d", res[i][j]);
            putchar('\n');
        }
    return 0;
}

// lamphanviet@gmail.com - 2011
