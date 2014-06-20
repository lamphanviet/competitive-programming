/*****************/
/* LAM PHAN VIET */
/* UVa: 760 - DNA Sequencing
/* Time limit: 3.000s
/********************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 303
using namespace std;

struct Node {
    bool end[2];
    Node *next[4];
};
int n, length_max, get_int[150];
char s[maxN], get_char[4];
Node *trie;

Node* new_node() {
    Node *node = new Node();
    node->end[0] = node->end[1] = false;
    REP(i, 4) node->next[i] = NULL;
    return node;
}

void initialize() {
    get_int['a'] = 0;
    get_int['c'] = 1;
    get_int['g'] = 2;
    get_int['t'] = 3;
    get_char[0] = 'a';
    get_char[1] = 'c';
    get_char[2] = 'g';
    get_char[3] = 't';
}

void build_trie(int k) {
    REP(start, n) {
        Node *node = trie;
        FOR (i, start, n - 1) {
            int j = get_int[s[i]];
            if (node->next[j] == NULL) node->next[j] = new_node();
            node = node->next[j];
            node->end[k] = true;
            if (node->end[0] && node->end[1])
                length_max = max(length_max, i - start + 1);
        }
    }
}

void result(Node *node, int length) {
    if (length == length_max && node->end[0] && node->end[1]) {
        REP(i, length)
            putchar(s[i]);
        putchar('\n');
        return;
    }
    REP(i, 4)
        if (node->next[i] != NULL) {
            s[length] = get_char[i];
            result(node->next[i], length + 1);
        }
}

main() {
//    FileIn("test"); FileOut("test");
    initialize();
    bool line = false;
    while (gets(s)) {
        trie = new_node();
        length_max = 0;
        n = strlen(s);
        build_trie(0);
        
        gets(s);
        n = strlen(s);
        build_trie(1);
        
        if (line) putchar('\n'); line = true;
        if (length_max) result(trie, 0);
        else puts("No common sequence.");
        
        gets(s); // blank line
        free(trie);
    }
}

/* lamphanviet@gmail.com - 2011 */
