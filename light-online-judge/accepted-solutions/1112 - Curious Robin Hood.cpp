//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1112 - Curious Robin Hood
// Time Limit   : 2.000s
// Description  : binary indexed tree
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

int n, a[maxN];
int tree[maxN];

void update(int i, int val) {
    while (i <= n) {
        tree[i] += val;
        i += Last(i);
    }
}

int64 get(int i) {
    int64 res = 0;
    while (i) {
        res += tree[i];
        i -= Last(i);
    }
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    int q, m, id, val;
    int caseNo, cases = 0;
    scanf("%d", &caseNo);
    while (caseNo--) {
        scanf("%d %d", &n, &m);
        FOR (i, 1, n) tree[i] = 0;
        FOR (i, 1, n) {
            scanf("%d", &a[i]);
            update(i, a[i]);
        }
        printf("Case %d:\n", ++cases);
        while (m--) {
            scanf("%d", &q);
            if (q == 1) {
                scanf("%d", &id); id++;
                update(id, -a[id]);
                printf("%d\n", a[id]);
                a[id] = 0;
            }
            else {
                scanf("%d %d", &id, &val); id++;
                if (q == 2) {
                    update(id, val);
                    a[id] += val;
                }
                else
                    printf("%lld\n", get(val + 1) - get(id - 1));
            }
        }
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
