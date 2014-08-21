//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10090 - Marbles
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

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int n, c1, c2, n1, n2;
	while (scanf("%d", &n) && n) {
		scanf("%d %d", &c1, &n1);
		scanf("%d %d", &c2, &n2);
		extEuclid(n1, n2);
		bool fail = false;
		if (n % d) fail = true;
		else {
			x *= (n / d); y *= (n / d);
			int64 a = n2 / d, b = n1 / d;
			int64 lf = (int64)ceil(-x / (double)a), rg = (int64)floor(y / (double)b);
			//printf("xy %lld %lld : ab %lld %lld : lg %lld %lld\n", x, y, a, b, lf, rg);
			if (lf > rg) fail = true;
			else {
				//printf("lrg %lld %lld\n", lf, rg);
				if (c1 * (x + a * lf) + c2 * (y - b * lf) < c1 * (x + a * rg) + c2 * (y - b * rg))
					x += a * lf, y -= b * lf;
				else
					x += a * rg, y -= b * rg;
				//if (x < 0 || y < 0) fail = true;
			}
		}
		if (fail) puts("failed");
		else printf("%lld %lld\n", x, y);
	}
	return 0;
}