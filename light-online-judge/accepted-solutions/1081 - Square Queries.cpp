//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1081 - Square Queries
// Time Limit   : 2.000s
// Description  : RMQ on 2D array
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
#define maxN 505
#define maxLN 10
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int read(int &n){return scanf(" %d ",&n);}
int read(int64 &n){return scanf(" %lld ",&n);}
int read(uint64 &n){return scanf(" %llu ",&n);}
int read(double &n){return scanf(" %lf ",&n);}
int read(char *c){return scanf(" %s ",c);}

int n, M[maxN][maxN][maxLN];

void processRMQ() {
    for (int k = 1; bit(k) <= n; k++)
        for (int i = 1; i + bit(k) - 1 <= n; i++)
            for (int j = 1; j + bit(k) - 1 <= n; j++) {
                int x = i + bit(k - 1), y = j + bit(k - 1);
                M[i][j][k] = max(M[i][j][k - 1], M[i][y][k - 1]);
                M[i][j][k] = max(M[i][j][k], max(M[x][j][k - 1], M[x][y][k - 1]));
            }
}

int get(int i, int j, int d) {
    int k = (int)log2(d), x = i + d - 1, y = j + d - 1, m1, m2;
    m1 = max(M[i][j][k], M[i][y - bit(k) + 1][k]);
    m2 = max(M[x - bit(k) + 1][j][k], M[x - bit(k) + 1][y - bit(k) + 1][k]);
    return max(m1, m2);
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    int caseNo, cases = 0, m, x, y, d;
    scanf("%d", &caseNo);
    while (caseNo--) {
        scanf("%d %d", &n, &m);
        FOR (i, 1, n)
            FOR (j, 1, n)
                scanf("%d", &M[i][j][0]);
        processRMQ();
        printf("Case %d:\n", ++cases);
        while (m--) {
            scanf("%d %d %d", &x, &y, &d);
           printf("%d\n", get(x, y, d));
        }
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
