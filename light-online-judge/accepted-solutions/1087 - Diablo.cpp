//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1087 - Diablo
// Time Limit   : 2.000s
// Description  : BIT - data structure
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
#define maxN 150010
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, a[maxN];
int tree[maxN];

int get(int i) {
    int res = 0;
    while (i) {
        res += tree[i];
        i -= Last(i);
    }
    return res;
}

void update(int i, int val) {
    while (i < maxN) {
        tree[i] += val;
        i += Last(i);
    }
}

void add(int x) {
    a[++n] = x;
    update(n, 1);
}

int call(int k) {
    int l = 1, r = n, res = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        int tmp = get(mid);
        if (tmp >= k) {
            if (tmp == k) res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    if (res == -1) return -1;
    update(res, -1);
    return a[res];
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    char ch;
    int caseNo, cases = 0, m, x;
    scanf("%d", &caseNo);
    while (caseNo--) {
        scanf("%d %d ", &n, &m);
        REP(i, maxN) tree[i] = 0;
        FOR (i, 1, n) {
            scanf("%d ", &a[i]);
            update(i, 1);
        }
        printf("Case %d:\n", ++cases);
        while (m--) {
            scanf(" %c %d ", &ch, &x);
            if (ch == 'a') add(x);
            else {
                x = call(x);
                if (x == -1) puts("none");
                else printf("%d\n", x);
            }
        }
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
