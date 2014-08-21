//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 12484 - Cards - UVa
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
#define maxN 10001

int n, a[maxN];
int64 f[maxN][maxN];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	while (scanf("%d", &n) != EOF) {
	    fr(i, 1, n) scanf("%d", &a[i]);
	    int st = n % 2 ? 1 : 2, nd = st;
	    for (int len = st; len <= n; len += 2) {
	        for (int i = 1, j = len; j <= n; i++, j++) {
	            if (len == st) f[i][j] = max(a[i], a[j]);
	            else {
	                int64 x = a[i] + min(f[i + 2][j], f[i + 1][j - 1]);
	                int64 y = a[j] + min(f[i][j - 2], f[i + 1][j - 1]);
	                f[i][j] = max(x, y);
	            }
	        }
	    }
	    printf("%lld\n", f[1][n]);
	}
	return 0;
}
