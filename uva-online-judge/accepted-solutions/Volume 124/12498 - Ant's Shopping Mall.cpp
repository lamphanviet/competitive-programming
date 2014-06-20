//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 12498 - Ant's Shopping Mall
// Time Limit   : .000s
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

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 55

int n, m, a[maxN][maxN];
char s[maxN][maxN];

int solve() {
    rep(i, n) {
        int pos = -1;
        rep(j, m) if (s[i][j] == '0') {
            pos = j;
            break;
        }
        if (pos == -1) return -1;
        
        a[i][pos] = 0;
        for (int j = pos - 1; j >= 0; j--) {
            if (s[i][j] == '0') a[i][j] = 0;
            else a[i][j] = a[i][j + 1] + 1;
        }
        for (int j = pos + 1; j < m; j++) {
            if (s[i][j] == '0') a[i][j] = 0;
            else a[i][j] = a[i][j - 1] + 1;
        }
        
        repr(j, m) if (s[i][j] == '0') {
            pos = j;
            break;
        }
        
        for (int j = pos - 1; j >= 0; j--) {
            if (s[i][j] == '0') a[i][j] = 0;
            else a[i][j] = min(a[i][j], a[i][j + 1] + 1);
        }
        for (int j = pos + 1; j < m; j++) {
            if (s[i][j] == '0') a[i][j] = 0;
            else a[i][j] = min(a[i][j], a[i][j - 1] + 1);
        }
    }
    int res = INF;
    rep(j, m) {
        int tmpres = 0;
        rep(i, n) tmpres += a[i][j];
        res = min(res, tmpres);
    }
    return res;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("test.inp", "r", stdin);
        //freopen("test.out", "w", stdout);
    #endif
    int cases, caseNo = 0;
    for (scanf("%d", &cases); cases--; ) {

        scanf(" %d %d ", &n, &m);
        rep(i, n) scanf(" %s ", s[i]);
        printf("Case %d: %d\n", ++caseNo, solve());
    }
}
