//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1266 - Points in Rectangle
// Time Limit   : 2.000s
// Description  : geometry - IT
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

const int n = 1001;
int m, tree[maxN][maxN];
bool exist[maxN][maxN];

void update(int x, int y) {
    while (x <= n) {
        int yy = y;
        while (yy <= n) {
            tree[x][yy]++;
            yy += Last(yy);
        }
        x += Last(x);
    }
}

int get(int x, int y) {
    int res = 0;
    while (x) {
        int yy = y;
        while (yy) {
            res += tree[x][yy];
            yy -= Last(yy);
        }
        x -= Last(x);
    }
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    int x, y, xx, yy, q;
    int caseNo, cases = 0;
    scanf("%d", &caseNo);
    while (caseNo--) {
        REP(i, maxN) REP(j, maxN)
            tree[i][j] = 0, exist[i][j] = false;
        scanf("%d", &m);
        printf("Case %d:\n", ++cases);
        while (m--) {
            scanf("%d", &q);
            if (q) {
                scanf("%d %d %d %d", &x, &y, &xx, &yy);
                x++, y++, xx++, yy++;
                int res = get(xx, yy) + get(x - 1, y - 1);
                res -= (get(x - 1, yy) + get(xx, y - 1));
                printf("%d\n", res);
            }
            else {
                scanf("%d %d", &x, &y);
                x++, y++;
                if (exist[x][y]) continue;
                exist[x][y] = true;
                update(x, y);
            }
        }
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
