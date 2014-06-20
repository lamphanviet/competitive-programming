//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1029 - Civil and Evil Engineer
// Time Limit   : 2.000s
// Description  : MST
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
#define maxN 1010
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef pair<int, ii> iii;

int n, lab[maxN];
vector<iii> edges;

bool cmp(iii const &a, iii const &b) {
    return a.ff > b.ff;
}

int getRoot(int v) {
    if (lab[v] < 0) return v;
    lab[v] = getRoot(lab[v]);
    return lab[v];
}

void unionTree(int r1, int r2) {
    int x = lab[r1] + lab[r2];
    if (r1 > r2) {
        lab[r1] = r2;
        lab[r2] = x;
    }
    else {
        lab[r1] = x;
        lab[r2] = r1;
    }
}

int findMST() {
    FOR (i, 0, n) lab[i] = -1;
    int counter = 0, res = 0;
    REP(i, edges.size()) {
        int u = getRoot(edges[i].ss.ff), v = getRoot(edges[i].ss.ss);
        if (u != v) {
            res += edges[i].ff;
            if (++counter == n) break;
            unionTree(u, v);
        }
    }
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    int caseNo, cases = 0, u, v, w;
    scanf("%d", &caseNo);
    while (caseNo--) {
        scanf("%d", &n);
        edges.clear();
        while (scanf("%d %d %d", &u, &v, &w)) {
            if (!u && !v && !w) break;
            edges.pb(iii(w, ii(u, v)));
        }
        
        sort(all(edges), cmp);
        int res = findMST();
        sort(all(edges));
        res += findMST();
        
        printf("Case %d: ", ++cases);
        if (res & 1) printf("%d/2\n", res);
        else printf("%d\n", res >> 1);
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
