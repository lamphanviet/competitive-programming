//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : UVA
// Problem Name : 12337 - Bob's Beautiful Balls
// Time Limit   : 1.000s
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
#define maxN 100
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };
int n, counter, r, c;
char s[maxN], a[maxN][maxN];

bool isOK(int r, int c) {
    FOR (j, 1, c)
        FOR (i, 2, r)
            if (a[i][j] != a[i - 1][j]) return false;
    return true;
}

bool inside(int x, int y) {
    return (1 <= x && x <= r && 1 <= y && y <= c);
}

void fillMatrix(int x, int y, int k) {
    if (a[x][y] != 'x') return;
    a[x][y] = s[counter++];
    
    int xx = x + dx[k], yy = y + dy[k];
    if (!inside(xx, yy) || a[xx][yy] != 'x')
        k = (k + 1) % 4;
    fillMatrix(x + dx[k], y + dy[k], k);
}

bool accept(int rr, int cc) {
    r = rr; c = cc;
    FOR (i, 1, r) FOR (j, 1, c)
        a[i][j] = 'x';
    counter = 0;
    fillMatrix(1, 1, 0);
    if (counter != n) return false;
    return isOK(r, c);
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); outFile("test.out");
    #endif
    int Case;
    scanf("%d ", &Case);
    FOR (test, 1, Case) {
        scanf("%s ", &s);
        n = strlen(s);
        int res = INF;
        for (int i = 2; i < n; i++)
            if (n % i == 0 && accept(i, n / i))
                res = min(res, i + n / i);
        printf("Case %d: %d\n", test, (res == INF) ? -1 : res);
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
