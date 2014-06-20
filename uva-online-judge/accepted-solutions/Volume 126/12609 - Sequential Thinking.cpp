//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 
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
#define INF 1000111000111000LL
#define eps 1e-7
#define maxN 100111

int64 n;

int64 countDigit(int64 m) {
	int64 lo = 1, res = 0;
	fr(i, 1, 18) {
		if (lo * 10 > m) {
			res += (m - lo + 1) * i;
			break;
		}
		res += lo * 9LL * i;
		lo *= 10LL;
	}
	return res;
}

int64 getLength(int64 m) {
	return countDigit(m) + (m - (m / 4));
}

int getDigit(int64 m, int pos) {
	vi d;
	while (m) {
		d.pb(m % 10);
		m /= 10;
	}
	reverse(all(d));
	return d[pos - 1];
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	while (scanf("%lld", &n) && n) {
		int64 lo = 1, hi = INF, pos = 1;
		while (lo <= hi) {
			int64 mid = (lo + hi) / 2;
			if (getLength(mid) >= n) {
				pos = mid;
				hi = mid - 1;
			}
			else lo = mid + 1;
		}
		n -= getLength(pos - 1);
		if (pos % 4) {
			for (int i = 0; i < 10; i += 2)
				if ((pos * 10 + i) % 4 == 0) {
					pos = pos * 10 + i;
					break;
				}
		}
		printf("%d\n", getDigit(pos, n));
	}
	return 0;
}
