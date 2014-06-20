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
#define maxN 1011

int n, m;
double f[maxN][maxN];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d ", &n, &m);
		fr(i, 0, n) fr(j, 0, m) f[i][j] = 0.0;
		f[n][m] = 1.0;
		frr(i, n, 0) frr(j, m, 0) {
			double sum = 0.0;
			if (i >= 2) sum += (i * (i - 1)) / (double)((i + j + 1) * (i + j)); // 2 tigers
			if (i && j) sum += (i * j) / (double)((i + j + 1) * (i + j)); // tiger vs deer
			if (i) sum += i / (double)((i + j + 1) * (i + j)); // human vs tiger
			
			if (i >= 2) f[i - 2][j] += (1.0 / sum) * f[i][j] * (i * (i - 1)) / ((i + j + 1) * (i + j)); // 2 tigers
			if (i && j) f[i][j - 1] += (1.0 / sum) * f[i][j] * (i * j) / ((i + j + 1) * (i + j)); // tiger vs deer
		}
		double res = 0.0;
		rep(j, m + 1) res += f[0][j];
		//rep(j, m + 1) res = max(res, f[0][j]);
		printf("Case %d: %.10lf\n", ++caseNo, res);
		if (n == 30 && m == 35 && false) {
			fr(i, 0, n) {
				fr(j, 0, m) printf("%7.3lf", f[i][j]); puts("");
			}
		}
	}
	return 0;
}
