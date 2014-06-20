//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1012 - Guilty Prince 
// Time Limit   : 2.000s
// Description  : bfs - easy
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
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 25
#define sq(x) ((x) * (x))
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };
int n, m, res;
char s[maxN][maxN];

bool inside(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < m);
}

void dfs(int x, int y) {
    if (!inside(x, y) || s[x][y] == '#') return;
    res++;
    s[x][y] = '#';
    REP(i, 4)
        dfs(x + dx[i], y + dy[i]);
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    int caseNo, cases = 0, sx, sy;
    scanf("%d", &caseNo);
    while (caseNo--) {
        scanf("%d %d ", &m, &n);
        REP(i, n) {
            scanf(" %s ", &s[i]);
            REP(j, m) if (s[i][j] == '@') {
                sx = i, sy = j;
            }
        }
        res = 0;
        dfs(sx, sy);
        printf("Case %d: %d\n", ++cases, res);
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
