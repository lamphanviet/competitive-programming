//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1085 - All Possible Increasing Subsequences 
// Time Limit   : 2.000s
// Description  : BIT
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
#define MOD 1000000007
#define maxN 100010
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int a[maxN], n;
int tree[maxN], m;

void update(int i, int val) {
    while (i <= m) {
        tree[i] = (tree[i] + val) % MOD;
        i += Last(i);
    }
}

int get(int i) {
    int res = 0;
    while (i) {
        res = (res + tree[i]) % MOD;
        i -= Last(i);
    }
    return res;
}

map<int, int> idx;

void processInput() {
    vi b;
    idx.clear();
    FOR (i, 1, n) {
        scanf("%d", &a[i]);
        b.pb(a[i]);
    }
    sort(all(b));
    idx[b[0]] = m = 1;
    for (int i = 1; i < b.size(); i++)
        if (b[i] != b[i - 1])
            idx[b[i]] = ++m;
}

int solve() {
    int res = 0;
    FOR (i, 1, n) tree[i] = 0;
    FOR (i, 1, n) {
        a[i] = idx[a[i]];
        int tmp = get(a[i] - 1) + 1;
        res = (res + tmp) % MOD;
        update(a[i], tmp);
    }
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    int caseNo, cases = 0;
    scanf("%d", &caseNo);
    while (caseNo--) {
        scanf("%d ", &n);
        processInput();
        printf("Case %d: %d\n", ++cases, solve());
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
