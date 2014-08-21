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
#define maxA 100
#define maxM 50005
#define maxN 500005

int n, m, k, f[maxN];
char alpha[maxA], x[maxM], a[maxM], b[maxN], pos[300];

bool ok(int add) {
	rep(i, m) a[i] = alpha[(pos[x[i]] + add) % k];
	f[0] = f[1] = 0;
	fr(i, 2, m) {
		for (int j = f[i - 1]; ;) {
			if (a[i - 1] == a[j]) { f[i] = j + 1; break; }
			if (j == 0) { f[i] = 0; break; }
			j = f[j];
		}
	}
	int cnt = 0;
	for (int j = 0, i = 0; j < n; ) {
		if (b[j] == a[i]) {
			j++; i++;
			if (i == m) {
				i = f[i];
				if (++cnt > 1) return false;
			}
		}
		else if (i > 0) i = f[i];
		else j++;
	}
	return cnt == 1;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	int cases;
	vi res;
	for (scanf("%d", &cases); cases--; ) {
		scanf(" %s %s %s ", alpha, x, b);
		res.clear();
		k = strlen(alpha);
		rep(i, k) pos[alpha[i]] = i;
		m = strlen(x); n = strlen(b);
		rep(i, k) if (ok(i)) res.pb(i);
		if (res.size() == 0) puts("no solution");
		else if (res.size() == 1) printf("unique: %d\n", res[0]);
		else {
			printf("ambiguous:");
			rep(i, res.size()) printf(" %d", res[i]);
			puts("");
		}
	}
	return 0;
}
