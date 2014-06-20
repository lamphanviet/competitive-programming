//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1117 - Helping Cicada 
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
#define maxN 22

int m, n, a[maxN];
int64 res;

int64 gcd(int64 x, int64 y) { return y ? gcd(y, x % y) : x; }
int64 lcm(int64 x, int64 y) { return (x * y) / gcd(x, y); }

void solve(int p, int64 value, int num) {
    if (p == n) {
        if (num == 0) return;
        if (num & 1) res += (m / value);
        else res -= (m / value);
        return;
    }
    solve(p + 1, value, num);
    solve(p + 1, lcm(value, a[p]), num + 1);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d ", &cases); cases--; ) {
	    scanf("%d %d", &m, &n);
	    rep(i, n) scanf("%d", &a[i]);
	    res = 0;
	    solve(0, 1, 0);
	    printf("Case %d: %d\n", ++caseNo, m - (int)res);
	}
	return 0;
}
