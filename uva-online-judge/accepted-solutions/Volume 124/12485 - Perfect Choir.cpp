//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 12485 - Perfect Choir - UVa
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
#define INF 100011122299999999LL
#define eps 1e-7
#define maxN 10001

int n, a[maxN];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	while (scanf("%d", &n) != EOF) {
	    int64 up = 0, dn = 0, res = INF;
	    int mx = 0, mn = 0;
	    fr(i, 1, n) {
	        scanf("%d", &a[i]);
	        up += a[i];
	        mx = max(mx, a[i]);
	        mn = min(mn, a[i]);
	    }
	    int i = 1;
	    fr(j, mn, mx) {
	        while (i <= n && a[i] <= j) {
	            up -= a[i]; dn += a[i];
	            i++;
	        }
	        int64 lf = j * (int64)(i - 1);
	        int64 rg = j * (int64)(n - i + 1);
	        int64 d1 = dn - lf, d2 = up - rg;
	        if (d1 < 0) d1 = -d1;
	        if (d2 < 0) d2 = -d2;
	        if (d1 == d2) res = min(res, max(d1, d2));
	    }
	    if (res == INF) res = -2;
	    printf("%lld\n", res + 1);
	}
	return 0;
}
