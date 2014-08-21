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
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 1001

struct BigInteger {
	static const int BASE = 1000000000; // 10^9
	
	vector<int64> digits;
	
	BigInteger() {
		digits.clear();
		digits.pb(0);
	}
	BigInteger(int64 number) {
		digits.clear();
		do {
			digits.pb(number % BASE);
			number /= BASE;
		} while (number);
	}
	
	BigInteger operator + (const BigInteger &b) const {
		BigInteger res = BigInteger();
		res.digits.resize(max(b.digits.size(), digits.size()));
		int64 remainder = 0;
		rep(i, res.digits.size()) {
			if (i < digits.size()) remainder += digits[i];
			if (i < b.digits.size()) remainder += b.digits[i];
			res.digits[i] = remainder % BASE;
			remainder /= BASE;
		}
		while (remainder) {
			res.digits.pb(remainder % BASE);
			remainder /= BASE;
		}
		return res;
	}
	
	BigInteger operator * (const BigInteger &b) const {
		BigInteger res = BigInteger();
		res.digits = vector<int64>(b.digits.size() + digits.size() - 1, 0);
		rep(i, digits.size()) rep(j, b.digits.size())
			res.digits[i + j] += digits[i] * (int64)b.digits[j];
		int64 remainder = 0;
		rep(i, res.digits.size()) {
			remainder += res.digits[i];
			res.digits[i] = remainder % BASE;
			remainder /= BASE;
		}
		while (remainder) {
			res.digits.pb(remainder % BASE);
			remainder /= BASE;
		}
		return res;
	}
	
	void print() {
		printf("%lld", digits.back());
		repr(i, (int)digits.size() - 1) printf("%09lld", digits[i]);
	}
	
	static BigInteger power(const BigInteger &b, int64 k) {
		if (k == 0) return BigInteger(1);
		if (k == 1) return b;
		BigInteger res = power(b, k / 2);
		res = res * res;
		if (k & 1) return res * b;
		return res;
	}
};

BigInteger ways[maxN];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	ways[0] = BigInteger(1);
	fr(i, 1, 1000) {
		ways[i] = ways[i - 1] + ways[i - 1];
		if (i - 2 >= 0) ways[i] = ways[i] + ways[i - 2];
		if (i - 3 >= 0) ways[i] = ways[i] + ways[i - 3];
	}
	int n;
	while (scanf("%d", &n) != EOF) {
		ways[n].print(); puts("");
	}
	return 0;
}
