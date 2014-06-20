//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 12526- Cellphone Typing
// Time Limit   : .000s
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

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100011

struct Node {
    bool end, only;
    vi next;
    Node() {
        next.resize(26);
        rep(i, 26) next[i] = -1;
        end = only = false;
    }
};
vector<Node> tree;
int n, root, len[maxN];
char word[maxN][100];

int newNode() {
    tree.pb(Node());
    return tree.size() - 1;
}

void visit(int u) {
    int cnt = 0;
    rep(i, 26) if (tree[u].next[i] >= 0) {
        cnt++;
        visit(tree[u].next[i]);
    }
    if (!tree[u].end) tree[u].only = (cnt == 1);
    else tree[u].only = false;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	while (scanf("%d ", &n) != EOF) {
	    tree.clear();
	    root = newNode();
	    rep(i, n) {
            scanf(" %s ", word[i]); len[i] = strlen(word[i]);
            int id = root;
            rep(j, len[i]) {
                int u = word[i][j] - 'a';
                if (tree[id].next[u] < 0) {
                    int k = newNode();
                    tree[id].next[u] = k;
                }
                id = tree[id].next[u];
            }
            tree[id].end = true;
	    }
	    visit(root);
	    //printf("sz %d\n", tree.size());
	    int res = 0;
	    rep(i, n) {
	        int tmp = 1;
	        res++;
	        int id = tree[root].next[word[i][0] - 'a'], j = 1;
	        while (j < len[i]) {
	            while (j < len[i] && tree[id].only) {
	                id = tree[id].next[word[i][j] - 'a'];
	                j++;
	            }
	            if (j < len[i]) {
	                res++;
	                tmp++;
	                id = tree[id].next[word[i][j] - 'a'];
	                j++;
	            }
	        }
	      //  printf("%d: %d\n", i, tmp);
	    }
	    printf("%.2lf\n", res / (double)n);
	}
	return 0;
}
