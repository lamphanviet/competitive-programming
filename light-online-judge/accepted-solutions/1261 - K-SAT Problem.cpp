//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1261 - K-SAT Problem 
// Time Limit   : 2.000s
// Description  : beginners
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
#define maxN 35
#define sq(x) ((x) * (x))
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, m, k, p;
int wish[maxN][maxN];
bool add[maxN], happy[maxN];

bool accept() {
    REP(i, n) happy[i] = false;
    FOR (j, 1, m)
        REP(i, n) if (!happy[i]) {
            if ((wish[i][j] == -1  || wish[i][j] == 2) && !add[j]) happy[i] = true;
            else if ((wish[i][j] == 1 || wish[i][j] == 2) && add[j]) happy[i] = true;
        }
    REP(i, n) if (!happy[i]) return false;
    return true;
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    int caseNo, cases = 0, val;
    scanf("%d", &caseNo);
    while (caseNo--) {
        scanf("%d %d %d ", &n, &m, &k);
        REP(i, n) FOR (j, 1, m)
            wish[i][j] = 0;
        REP(i, n) {
            REP(j, k) {
                scanf("%d", &val);
                if (wish[i][abs(val)] == 2) continue;
                if (val > 0) {
                    if (wish[i][val] == -1) wish[i][val] = 2;
                    else wish[i][val] = 1;
                }
                else {
                    val = -val;
                    if (wish[i][val] == 1) wish[i][val] = 2;
                    else wish[i][val] = -1;
                }
            }
        }
        FOR (i, 1, m) add[i] = false;
        scanf("%d", &p);
        REP(i, p) {
            scanf("%d", &val);
            add[val] = true;
        }
        printf("Case %d: ", ++cases);
        if (accept()) puts("Yes");
        else puts("No");
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
