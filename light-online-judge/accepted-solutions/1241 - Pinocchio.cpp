//============================================================================
// Author       : LAM PHAN VIET
// Online Judge : LightOJ
// Problem Name : 1241 - Pinocchio 
// Time Limit   : 0.500s
// Description  : beginner
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
#define maxN 100010
#define sq(x) ((x) * (x))
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int get(int a, int b) {
    int res = 0;
    while (b > a)
        b -= 5, res++;
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); //outFile("test.out");
    #endif
    int n, next, cur, res;
    int caseNo, cases = 0;
    scanf("%d", &caseNo);
    while (caseNo--) {
        res = 0;
        scanf("%d", &n);
        scanf("%d", &cur);
        if (cur != 2) res += get(2, cur);
        for (int i = 1; i < n; i++) {
            scanf("%d", &next);
            if (next > cur) res += get(cur, next);
            cur = next;
        }
        printf("Case %d: %d\n", ++cases, res);
    }
    return 0;
}

// lamphanviet@gmail.com - 2011
