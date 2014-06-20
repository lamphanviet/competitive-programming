//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1080 - Binary Simulation 
// Time Limit   : 2.000s
// Description  : IT
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

int tree[maxN * 4];

void update(int p, int L, int R, int U, int V) {
    if (R < U || V < L) return;
    if (U <= L && R <= V) {
        tree[p]++;
        return;
    }
    if (L == R) return;
    int c = p << 1, mid = (L + R) >> 1;
    update(c, L, mid, U, V);
    update(c + 1, mid + 1, R, U, V);
}

int get(int p, int L, int R, int X) {
    if (X < L || R < X) return 0;
    if (L == R) return tree[p];
    int c = p << 1, mid = (L + R) >> 1;
    return tree[p] + get(c, L, mid, X) + get(c + 1, mid + 1, R, X);
}

char s[maxN];

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    char q[2];
    int n, x, y, m;
    int caseNo, cases = 0;
    scanf(" %d ", &caseNo);
    while (caseNo--) {
        gets(s);
        n = strlen(s);
        REP(i, maxN * 4) tree[i] = 0;
        REP(i, n) if (s[i] == '1')
            update(1, 1, n, i + 1, i + 1);
        scanf(" %d ", &m);
        printf("Case %d:\n", ++cases);
        while (m--) {
            scanf(" %s ", &q);
            if (q[0] == 'I') {
                scanf(" %d %d ", &x, &y);
                update(1, 1, n, x, y);
            }
            else {
                scanf(" %d ", &x);
                printf("%d\n", get(1, 1, n, x) & 1);
            }
        }
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
