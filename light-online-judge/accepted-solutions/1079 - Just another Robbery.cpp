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
#define maxN 101
#define maxM 10001

int n, money[maxN];
double p[maxN], f[maxM], P;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf(" %lf %d ", &P, &n);
		rep(i, n) scanf(" %d %lf ", &money[i], &p[i]);
		rep(i, maxM) f[i] = 2.0; f[0] = 0.0;
		rep(i, n) {
			for (int j = maxM - 1; j >= money[i]; j--)
				if (f[j - money[i]] <= P)
					f[j] = min(f[j], f[j - money[i]] + (1.0 - f[j - money[i]]) * p[i]);
			//printf("%d: ", i); fr(j, 0, 6) printf("%lf ", f[j]); puts("");
		}
		int res = 0;
		rep(j, maxM) if (f[j] <= P) res = j;
		printf("Case %d: %d\n", ++caseNo, res);
	}
	return 0;
}
