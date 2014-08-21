//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1231 - ACORN - UVa
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
#define maxN 2002

int n, h, lost, m, num[maxN][maxN], f[maxN][maxN], mx[maxN];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int cases, pos;
	for (scanf("%d", &cases); cases--; ) {
	    scanf("%d %d %d", &n, &h, &lost);
	    fill(num, 0); fill(f, 0); fill(mx, 0);
	    rep(i, n) {
	        scanf("%d", &m);
	        while (m--) {
	            scanf("%d", &pos);
	            if (0 <= pos && pos <= h) num[i][pos]++;
	        }
	    }
	    
	    rep(i, n) {
	        mx[0] = max(mx[0], num[i][0]);
	        f[i][0] = num[i][0];
	    }
	    fr(j, 1, h) {
	        if (j) mx[j] = mx[j - 1];
	        rep(i, n) {
	            f[i][j] = f[i][j - 1] + num[i][j];
	            if (j - lost >= 0)
                    f[i][j] = max(f[i][j], mx[j - lost] + num[i][j]);
                mx[j] = max(mx[j], f[i][j]);
	        }
	    }
	    
	    int res = 0;
	    rep(i, n) res = max(res, f[i][h]);
	    printf("%d\n", res);
	}
	return 0;
}
