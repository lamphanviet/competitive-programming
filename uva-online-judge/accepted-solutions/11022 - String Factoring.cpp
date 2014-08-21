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
#define maxN 88

int n, f[maxN][maxN], same[maxN][maxN];
char s[maxN];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	while (scanf(" %s ", s) && s[0] != '*') {
		n = strlen(s);
		fill(same, 0);
		rep(i, n) rep(j, n) {
			for (int len = 1; i + len <= n && j + len <= n; len++) {
				if (s[i + len - 1] == s[j + len - 1]) same[i][j] = len;
				else break;
			}
		}
		rep(i, n) f[i][i] = 1;
		fr(len, 2, n) {
			for (int i = 0, j = len - 1; j < n; i++, j++) {
				f[i][j] = j - i + 1;
				fr(k, i, j - 1) f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
				fr(k, 1, len - 1) if (len % k == 0) {
					bool allSame = true;
					for (int st = i; st <= j; st += k)
						if (!(same[i][st] >= k)) {
							allSame = false;
							break;
						}
					if (allSame) f[i][j] = min(f[i][j], f[i][i + k - 1]);
				}
			}
		}
		printf("%d\n", f[0][n - 1]);
	}
	return 0;
}
