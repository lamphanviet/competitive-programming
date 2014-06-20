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
#define INF 1000111222
#define eps 1e-7
#define maxN 100

int f[10][maxN][maxN], p[10], d, K;

int countDigit(int n) {
	int res = 0;
	do {
		res++; n /= 10;
	} while (n);
	return res;
}

int get(int n) {
	if (n == 0) return 1;
	vi digit;
	do {
		digit.pb(n % 10); n /= 10;
	} while (n);
	int res = 0, value = 0, sum = 0;
	repr(i, digit.size()) {
		rep(j, digit[i]) {
			rep(u, K) rep(v, K) if (f[i][u][v]) {
				if ((sum + u) % K == 0 && (value + v) % K == 0)
					res += f[i][u][v];
			}
			value = (value + p[i]) % K;
			sum = (sum + 1) % K;
		}
	}
	if (value % K == 0 && sum % K == 0) res++;
	return res;
}

int solve(int A, int B) {
	d = countDigit(B);
	if (K > d * 9LL) return 0;
	fill(f, 0);
	f[0][0][0] = 1;
	rep(i, d) rep(j, K) rep(k, K) if (f[i][j][k]) {
		rep(no, 10) {
			int jj = (no + j) % K, kk = (no * (int64)p[i] + k) % K;
			f[i + 1][jj][kk] += f[i][j][k];
		}
	}
	return get(B) - get(A - 1);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	p[0] = 1; fr(i, 1, 9) p[i] = p[i - 1] * 10;
	int cases, caseNo = 0, a, b;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d %d", &a, &b, &K);
		printf("Case %d: %d\n", ++caseNo, solve(a, b));
	}
	return 0;
}
