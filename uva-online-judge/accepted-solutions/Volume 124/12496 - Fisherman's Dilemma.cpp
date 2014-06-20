//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 12496 - Fisherman's Dilemma
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
#define maxN 222

int n, m, a[maxN][maxN], sum[maxN][maxN];

int gcd(int x, int y) { return (y == 0) ? x : gcd(y, x % y); }

int getSum(int i, int j, int u, int v) {
    int res = sum[u][v];
    if (i - 1 >= 0) res -= sum[i - 1][v];
    if (j - 1 >= 0) res -= sum[u][j - 1];
    if (i - 1 >= 0 && j - 1 >= 0) res += sum[i - 1][j - 1];
    return res;
}

int main(){
    #ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
    int cases, caseNo = 0, K;
    for (scanf("%d", &cases); cases--; ) {
        scanf("%d %d %d", &n, &m, &K);
        rep(i, n) rep(j, m) {
            scanf("%d", &a[i][j]);
            sum[i][j] = a[i][j];
            if (i - 1 >= 0) sum[i][j] += sum[i - 1][j];
            if (j - 1 >= 0) sum[i][j] += sum[i][j - 1];
            if (i - 1 >= 0 && j - 1 >= 0) sum[i][j] -= sum[i - 1][j - 1];
        }
        int all = 0, ok = 0;
        rep(i, n) rep(j, m)
            all += (n - i) * (m - j);
        rep(x1, n) for (int x2 = x1; x2 < n; x2++) {
            int y2 = 0;
            rep(y1, m) {
                while (y2 < y1) y2++;
                while (y2 < m && getSum(x1, y1, x2, y2) < K) y2++;
                ok += m - y2;
            }
        }
        //printf("ok %d/%d\n", all, ok);
        int g = gcd(ok, all);
        all /= g; ok /= g;
        printf("Case %d: %d/%d\n", ++caseNo, ok, all);
    }
}
