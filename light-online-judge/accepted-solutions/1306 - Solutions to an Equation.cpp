//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1306 - Solutions to an Equation
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
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000

int64 x, y, d;


void extEuclid(int64 a, int64 b) {
	if (b == 0) { x = 1; y = 0; d = a; return; }
	extEuclid(b, a % b);
	x = x - (a / b) * y;
	swap(x, y);
}

int64 solve(int a, int b, int c, int64 x1, int64 x2, int64 y1, int64 y2) {
	extEuclid(a, b);
	if (!a && !b) {
		if (c) return 0;
		return (x2 - x1 + 1) * (int64)(y2 - y1 + 1);
	}
	else if (!a) {
		if (c % b) return 0;
		c = -c / b;
		if (y1 <= c && c <= y2) return (x2 - x1 + 1);
		return 0;
	}
	else if (!b) {
		if (c % a) return 0;
		c = -c / a;
		if (x1 <= c && c <= x2) return (y2 - y1 + 1);
		return 0;
	}
	if (c % d == 0) {
		//d = abs(d);
		x *= (-c / d); y *= (-c / d);
		b /= d; a /= d;
		swap(a, b); // x + ka, y - kb
		double p = (x1 - x) / (double)a, q = (x2 - x) / (double)a;
		if (p > q) swap(p, q);
		x1 = (int64)ceil(p);
		x2 = (int64)floor(q);
		
		p = (y - y1) / (double)b; q = (y - y2) / (double)b;
		if (p > q) swap(p, q);
		y1 = (int64)ceil(p);
		y2 = (int64)floor(q);
		
		//printf("xy %lld %lld : ab %d %d : x %lld %lld : y %lld %lld\n", x, y, a, b, x1, x2, y1, y2);
		
		x1 = max(x1, y1); x2 = min(x2, y2);
		return max(0LL, x2 - x1 + 1);
	}
	return 0;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0, a, b, c, x1, y1, x2, y2;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d %d", &a, &b, &c);
		scanf("%d %d %d %d", &x1, &x2, &y1, &y2);
		printf("Case %d: %lld\n", ++caseNo, solve(a, b, c, x1, x2, y1, y2));
	}
	return 0;
}