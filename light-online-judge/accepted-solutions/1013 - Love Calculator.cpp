//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1013 - Love Calculator 
// Time Limit   : 2.000s
// Description  : dp
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
#define maxN 33
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int64 f[maxN * 2][maxN][maxN];
string x, y;
int n, nx, ny;

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    int caseNo, cases = 0;
    scanf("%d", &caseNo);
    while (caseNo--) {
        cin >> x >> y;
        nx = x.length(), ny = y.length();
        n = nx + ny;
        x = "." + x;
        y = "." + y;
        REP(i, n) REP(j, nx) REP(k, ny)
            f[i][j][k] = 0LL;
        f[0][0][0] = 1LL;
        FOR (i, 1, n) {
            FOR (j, 0, nx) {
                FOR (k, 0, ny) {
                    f[i][j][k] = f[i - 1][j][k] * 26LL;
                    if (j && k) {
                        if (x[j] == y[k])
                            f[i][j][k] += f[i - 1][j - 1][k - 1];
                        else {
                            f[i][j][k] += f[i - 1][j - 1][k];
                            f[i][j][k] += f[i - 1][j][k - 1];
                        }
                    }
                    else {
                        if (j) f[i][j][k] += f[i - 1][j - 1][k];
                        if (k) f[i][j][k] += f[i - 1][j][k - 1];
                    }
                }
            }
        }
        FOR (i, max(nx, ny), n)
            if (f[i][nx][ny]) {
                n = i;
                break;
            }
        printf("Case %d: %d %lld\n", ++cases, n, f[n][nx][ny]);
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
